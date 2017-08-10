#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QPlainTextEdit>
#include <QLabel>
#include <QDebug>
#include "stdlib.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void on_urlTextInput_textChanged(const QString &arg1);
    void responseReceivedSlot(QNetworkReply * response);

    void on_urlTextInput_returnPressed();

private:
    void sendRequest();
    Ui::MainWindow *ui;

    QPlainTextEdit *responseBodyInput;
    QLabel *statusCodeLabel;

    QString urlText;
    QNetworkAccessManager *networkManager;
};

#endif // MAINWINDOW_H
