QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_item.cpp \
    core.cpp \
    dashboard.cpp \
    inventory_page.cpp \
    maestro.cpp \
    main.cpp \
    mainwindow.cpp \
    reports.cpp \
    users.cpp

HEADERS += \
    add_item.h \
    core.h \
    dashboard.h \
    inventory_page.h \
    maestro.h \
    mainwindow.h \
    reports.h \
    users.h

FORMS += \
    add_item.ui \
    dashboard.ui \
    inventory_page.ui \
    mainwindow.ui \
    reports.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
