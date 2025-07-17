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
    
    // Debug: Show current working directory and resolved paths
    std::cout << "=== PROGRAM EXECUTION DEBUG INFO ===" << std::endl;
    std::cout << "Current working directory: " << QDir::currentPath().toStdString() << std::endl;
    std::cout << "Resolved users.csv path: " << QDir("../../database/users.csv").absolutePath().toStdString() << std::endl;
    std::cout << "Resolved items.csv path: " << QDir("../../database/items.csv").absolutePath().toStdString() << std::endl;
    std::cout << "====================================" << std::endl;
    QObject::connect(&a, &QApplication::aboutToQuit, &UserManager::saveUsers);
    UserManager manager;
    InventoryManager manager2;
    loginPage w;
    w.show();
    
    return a.exec();
}
