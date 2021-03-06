#-------------------------------------------------
#
# Project created by QtCreator 2017-08-08T16:02:22
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = woke
TEMPLATE = app

SUBDIRS += src

SOURCES += src/main.cpp \
    src/controller/historycontroller.cpp \
    src/urlutil.cpp \
    src/model/request.cpp \
    src/model/requestlistmodel.cpp \
    src/view/mainwindow.cpp \
    src/view/jsonsyntaxhighlighter.cpp \
    src/view/urlsyntaxhighlighter.cpp \
    src/view/requestitem.cpp \
    src/controller/requestscontroller.cpp \
    src/view/urlplaintextedit.cpp \
    src/view/urleditor.cpp \
    src/view/tabbededitor.cpp \
    src/view/requesttabbededitor.cpp \
    src/view/responsetabbededitor.cpp \
    src/view/headersyntaxhighlighter.cpp \
    test/view/tabbededitor_test.cpp \
    src/view/saveeditor.cpp \
    src/model/project.cpp \
    src/controller/projectcontroller.cpp

HEADERS += \
    src/controller/historycontroller.h \
    src/urlutil.h \
    src/model/request.h \
    src/model/requestlistmodel.h \
    src/view/mainwindow.h \
    src/view/jsonsyntaxhighlighter.h \
    src/view/urlsyntaxhighlighter.h \
    src/view/requestitem.h \
    src/controller/requestscontroller.h \
    src/view/urlplaintextedit.h \
    src/view/urleditor.h \
    src/view/tabbededitor.h \
    src/view/requesttabbededitor.h \
    src/view/responsetabbededitor.h \
    src/view/headersyntaxhighlighter.h \
    test/view/tabbededitor_test.h \
    src/view/saveeditor.h \
    src/model/project.h \
    src/controller/projectcontroller.h

FORMS += mainwindow.ui \
    requestitem.ui \
    urleditor.ui \
    tabbededitor.ui \
    saveeditor.ui

DISTFILES += misc/woke.desktop

unix|win32: LIBS += -lqdjango-db

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

test {
    message(Test build)

    QT += testlib
    TARGET = woke-test

    SOURCES -= src/main.cpp

    HEADERS += \
        test/urlutil_test.h \
        test/mainwindow_test.h \
        test/view/requestitem_test.h \
        test/controller/mockrequestscontroller.h \
        test/qt/mocknetworkreply.h

    SOURCES += \
        test/test_main.cpp \
        test/urlutil_test.cpp \
        test/view/requestitem_test.cpp \
        test/mainwindow_test.cpp \
        test/controller/mockrequestscontroller.cpp \
        test/qt/mocknetworkreply.cpp

} else  {
    message(Normal build)
}

unix {
    isEmpty(PREFIX) {
        PREFIX = /usr/local
    }

    target.path = $$PREFIX/bin

    shortcutfiles.files = misc/woke.desktop
    shortcutfiles.path = $$PREFIX/share/applications/

    INSTALLS += shortcutfiles
}

INSTALLS += target

