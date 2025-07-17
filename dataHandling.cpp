#include "core.h"
#include <sstream>
#include <QString>
#include <QMessageBox>
#include <QWidget>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QDir>
#include <QRegularExpression>
#include <QTableWidget>
using namespace std;


void UserManager::loadUsers(const QString& data) {
    ifstream file(data.toStdString());
    if (!file.is_open()) {
        // throw runtime_error("File does not exist");
        cout<<data.toStdString()<<endl;
    }

    string line;
    while (getline(file, line)) {
        stringstream so(line);
        string username, password, role;

        if (getline(so, username, ',') &&
            getline(so, password, ',') &&
            getline(so, role, ',')) {
            usersByUsername[QString::fromStdString(username)] =
                User(QString::fromStdString(username),
                     QString::fromStdString(password),
                     QString::fromStdString(role));
        }
    }
    file.close();
}


void UserManager::updateTable(QTableWidget* table) {
    table->setRowCount(0);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels(QStringList() << "Username" << "Password" << "Role");

    int row = 0;
    for (const auto& it: usersByUsername)
    {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(it.getUsername()));
            table->setItem(row, 1, new QTableWidgetItem(it.getPass()));
            table->setItem(row, 2, new QTableWidgetItem(it.getRole()));

            ++row;
        }

}


QMap<QString, User> UserManager::getData() {return usersByUsername;}


void UserManager::saveUsers()
{
    QString database="../database/users.csv";
    ofstream File(database.toStdString());
    for(auto it=usersByUsername.begin(); it!= usersByUsername.end();++it)
    {
        if (File.is_open()) {
            File << it.value().getUsername().toStdString() << ","
                 << it.value().getPass().toStdString() << ","
                 << it.value().getRole().toStdString() << endl;
        }
    }
    File.close();
}


void InventoryManager::AddItem(QString& name, QString& quantity,   QString& price,   QString& supplier, QString& category  ){
    QString key ;
    key = name+supplier;
    if(name.isEmpty()||quantity.isEmpty()||price.isEmpty()|| supplier.isEmpty(), category.isEmpty() ){
        throw runtime_error {"Error: You cannot add an empty item  "};

    }
    if (quantity.toInt()<0|| price.toInt()<0) {
        throw runtime_error {"Only postive numbers"};
    }
    if (items.count(key)){
        throw runtime_error {"Item already exsit"} ;

    }
    else {
    items[key]=Item( name, category, quantity.toInt(), price.toInt(), supplier);

    }
}


void InventoryManager::loadItems(const QString& file)
{
    ifstream File(file.toStdString());
    if (!File.is_open()) {
        cout<<file.toStdString();

    }

    string line;
    while (getline(File, line)) {
        stringstream ss(line);
        string name, category, quantityStr, priceStr, supplier;

        if (getline(ss, name, ',') &&
            getline(ss, category, ',') &&
            getline(ss, quantityStr, ',') &&
            getline(ss, priceStr, ',') &&
            getline(ss, supplier, ',')) {
            string key ;
            key = name+supplier;
            items[QString::fromStdString(key)] =
                Item(
                    QString::fromStdString(name),
                    QString::fromStdString(category),
                    stoi(quantityStr),
                    stod(priceStr),
                    QString::fromStdString(supplier)
                    );
        }
    }

    File.close();
}



void InventoryManager::saveItems()
{
    QString path = "../database/items.csv";
    ofstream file(path.toStdString());
    if (!file.is_open()) {
        throw runtime_error("Failed to open inventory file for writing");
    }

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        file << it.value().getName().toStdString() << ","
             << it.value().getCategory().toStdString() << ","
             << it.value().getQuantity() << ","
             << it.value().getPrice() << ","
             << it.value().getSupplier().toStdString() << endl;
    }

    file.close();
}





QMap<QString, Item>& InventoryManager::getInventory() {return items;}
