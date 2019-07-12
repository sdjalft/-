#-------------------------------------------------
#
# Project created by QtCreator 2019-06-25T10:57:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        enemyplane.cpp \
        flyer.cpp \
        gameover.cpp \
        global.cpp \
        littleenemyplane.cpp \
        main.cpp \
        mainwindow.cpp \
        planefactory.cpp \
        playerplane.cpp \
        randomizer.cpp \
        space.cpp \
        unflyer.cpp \
        enemybullet.cpp \
        playerbullet.cpp \
        bulletfactory.cpp

HEADERS += \
        enemyplane.h \
        flyer.h \
        gameover.h \
        global.h \
        littleenemyplane.h \
        mainwindow.h \
        plane.h \
        planefactory.h \
        playerplane.h \
        randomizer.h \
        space.h \
        unflyer.h \
        bullet.h \
        enemybullet.h \
        playerbullet.h \
        bulletfactory.h

FORMS += \
        gameover.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    title.jpg

RESOURCES += \
    haha.qrc
