QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additem.cpp \
    adminpage.cpp \
    core.cpp \
    dashboard.cpp \
    dataHandling.cpp \
    inventory.cpp \
    main.cpp \
    loginpage.cpp \
    reportgenerator.cpp

HEADERS += \
    additem.h \
    adminpage.h \
    core.h \
    dashboard.h \
    inventory.h \
    loginpage.h \
    reportgenerator.h

FORMS += \
    additem.ui \
    adminpage.ui \
    dashboard.ui \
    inventory.ui \
    loginpage.ui \
    reportgenerator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
