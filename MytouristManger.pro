QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpackage.cpp \
    findpackage.cpp \
    findtourist.cpp \
    main.cpp \
    mainwindow.cpp \
    registertourist.cpp

HEADERS += \
    addpackage.h \
    databaseheader.h \
    findpackage.h \
    findtourist.h \
    mainwindow.h \
    registertourist.h

FORMS += \
    addpackage.ui \
    findpackage.ui \
    findtourist.ui \
    mainwindow.ui \
    registertourist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
