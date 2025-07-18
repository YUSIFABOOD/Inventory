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
#include <QDateTime>
using namespace std;

// Static variable definitions
QMap<QString, Item> InventoryManager::items;
QDateTime InventoryManager::lastModified = QDateTime::currentDateTime();
QString InventoryManager::lastOperation = "System initialized";

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
    if (items.count(key)){
        throw runtime_error {"Item already exsit"} ;

    }
    else {
    items[key]=Item( name, category, quantity.toInt(), price.toInt(), supplier);
    lastModified = QDateTime::currentDateTime();
    lastOperation = "Added item: " + name + " (" + supplier + ")"; // Record the operation

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


void InventoryManager::loadItemsIntoTable(QTableWidget *table) {
    const auto& items = InventoryManager::getInventory();
    table->setRowCount(0);
    int row = 0;
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Name", "Category", "Quantity", "Price", "Supplier"});

    for (auto it = items.begin(); it != items.end(); ++it) {
        const Item& item = it.value();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(item.getName()));
        table->setItem(row, 1, new QTableWidgetItem(item.getCategory()));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(item.getPrice())));
        table->setItem(row, 4, new QTableWidgetItem(item.getSupplier()));
        if (item.getQuantity() < 5) {
            for (int col = 0; col < 5; ++col) {
                table->item(row, col)->setBackground(QBrush(QColor(255, 200, 200))); // Light red background
                table->item(row, col)->setForeground(QBrush(QColor(139, 0, 0))); // Dark red text
            }
        }
        
        ++row;
    }
}


void InventoryManager::performSearch(const QString& type, const QString& text, QTableWidget *table)
{
    table->setRowCount(0);
    int row = 0;
    bool found = false;
    QMap<QString, Item>& items = InventoryManager::getInventory();
    for (auto it = items.begin(); it != items.end(); ++it) {
        const Item& item = it.value();
        bool match = false;

        if (type == "Name" && item.getName().contains(text, Qt::CaseInsensitive)) {
            match = true;
        } else if (type == "Category" && item.getCategory().contains(text, Qt::CaseInsensitive)) {
            match = true;
        } else if (type == "Supplier" && item.getSupplier().contains(text, Qt::CaseInsensitive)) {
            match = true;
        }

        if (match) {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(item.getName()));
            table->setItem(row, 1, new QTableWidgetItem(item.getCategory()));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
            table->setItem(row, 3, new QTableWidgetItem(QString::number(item.getPrice())));
            table->setItem(row, 4, new QTableWidgetItem(item.getSupplier()));
            
            if (item.getQuantity() < 5) {
                for (int col = 0; col < 5; ++col) {
                    table->item(row, col)->setBackground(QBrush(QColor(255, 200, 200))); // Light red background
                    table->item(row, col)->setForeground(QBrush(QColor(139, 0, 0))); // Dark red text
                }
            }
            
            ++row;
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No matching result");
    }
}

void InventoryManager::deleteItem(const QString& item, QString& supplier)
{
    QString key = item+supplier;
    items.remove(key);
    lastModified = QDateTime::currentDateTime();
    lastOperation = "Deleted item: " + item + " (" + supplier + ")"; // Record the operation
}

QMap<QString, Item>& InventoryManager::getInventory() {return items;}

QDateTime InventoryManager::getLastModified() {
    return lastModified;
}

QString InventoryManager::getLastOperation() {
    return lastOperation;
}
