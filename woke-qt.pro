#-------------------------------------------------
#
# Project created by QtCreator 2017-08-08T16:02:22
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = woke-qt
TEMPLATE = app

SUBDIRS += src

SOURCES += src/main.cpp \
    src/controller/historycontroller.cpp \
    src/urlutil.cpp \
    src/model/request.cpp \
    src/model/requestlistmodel.cpp \
    src/view/mainwindow.cpp \
    src/view/jsonsyntaxhighlighter.cpp

HEADERS += \
    src/controller/historycontroller.h \
    src/urlutil.h \
    src/model/request.h \
    src/model/requestlistmodel.h \
    src/view/mainwindow.h \
    src/view/jsonsyntaxhighlighter.h

#include(src/include.pri)

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/release/ -lqdjango-db
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/debug/ -lqdjango-db
else:unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lqdjango-db

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

test {
    message(Test build)

    QT += testlib
    TARGET = woke-qt-test

    SOURCES -= src/main.cpp

    HEADERS += \
        test/urlutil_test.h

    SOURCES += \
        test/test_main.cpp \
        test/urlutil_test.cpp
} else  {
    message(Normal build)
}
