#include "requestscontroller.h"

RequestsController::RequestsController(QObject *parent) : QObject(parent) {
    this->networkManager = QSharedPointer<QNetworkAccessManager>(new QNetworkAccessManager);
}

/**
 * @brief RequestsController::sendRequest
 *
 * Send a network request with an optional body and headers
 *
 * @param verb HTTP request type verb (GET, POST, ...)
 * @param url with protocol and hostname
 * @param headers or empty string
 * @param body if relavant or empty string
 * @return pointer to a fat request model object
 */
QSharedPointer<Request> RequestsController::sendRequest(QString &verb, QString &url, QString &headers, QString &body) {
    QSharedPointer<Request> currentRequest = QSharedPointer<Request>(new Request());
    UrlSegments segments = UrlUtil::safeSplitUrl(url);

    QNetworkRequest request(url);
    UrlUtil::setHeadersFromStringBlob(headers, request);
    HttpVerb verbEnum = UrlUtil::safeParseVerb(verb);

    currentRequest.data()->setProto(segments.proto);
    currentRequest.data()->setHost(segments.hostname);
    currentRequest.data()->setUri(segments.uri);
    currentRequest.data()->setVerb(HttpVerbStrings[verbEnum]);
    currentRequest.data()->setRequestHeaders(headers);
    currentRequest.data()->setRequestBody(body);

    this->responseTimer.start();

    switch (verbEnum) {
    case HttpVerb::GET:
        this->networkManager.data()->get(request);
        break;
    case HttpVerb::POST:
        this->networkManager.data()->post(request, body.toUtf8());
        break;
    case HttpVerb::PUT:
        this->networkManager.data()->put(request, body.toUtf8());
        break;
    case HttpVerb::PATCH:
        this->networkManager.data()->put(request, body.toUtf8());
        break;
    case HttpVerb::DELETE:
        this->networkManager.data()->deleteResource(request);
        break;
    case HttpVerb::HEAD:
        this->networkManager.data()->head(request);
        break;
    case HttpVerb::OPTIONS:
        this->networkManager.data()->get(request);
        break;
    case HttpVerb::CONNECT:
        this->networkManager.data()->get(request);
        break;
    default:
        break;
    }

    return currentRequest;
}

/**
 * @brief RequestsController::handleResponse
 *
 * Parse any relavant response information from the QNetworkReply
 *
 * @param response
 * @return response info struct
 */
ResponseInfo RequestsController::handleResponse(QNetworkReply &response) {
    int responseTime = this->responseTimer.elapsed();

    auto statusCode = response.attribute(QNetworkRequest::HttpStatusCodeAttribute);
    auto statusCodeInt = statusCode.toInt();

    QString contentType("");
    auto contentTypeVar = response.header(QNetworkRequest::KnownHeaders::ContentTypeHeader);
    if (contentTypeVar.canConvert(QVariant::String)) {
        contentType = contentTypeVar.toString();
    }

    qDebug() << contentType;

    ResponseInfo responseInfo;
    responseInfo.responseTime = responseTime;
    responseInfo.statusCode = statusCodeInt;
    responseInfo.contentType = contentType;

    return responseInfo;
}
