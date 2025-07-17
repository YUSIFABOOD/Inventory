#include "loginpage.h"
#include "core.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QObject::connect(&a, &QApplication::aboutToQuit, &UserManager::saveUsers);
    UserManager manager;
    InventoryManager manager2;
    loginPage w;
    w.show();
    
    return a.exec();
}
