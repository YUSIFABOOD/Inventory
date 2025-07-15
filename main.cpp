#include "loginpage.h"
#include "core.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InventoryManager::loadItems();
    QObject::connect(&a, &QApplication::aboutToQuit, &UserManager::saveUsers);
    UserManager manager;
    loginPage w;
    w.show();
    
    return a.exec();
}
