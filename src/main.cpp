#include "model/project.h"
#include "model/request.h"
#include "view/mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <qdjango/db/QDjango.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    QDjango::setDatabase(db);
    QDjango::registerModel<Request>();
    QDjango::registerModel<Project>();
    QDjango::createTables();

    MainWindow w;
    w.show();

    return a.exec();
}
