#include "core.h"
#include <bits/stdc++.h>
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


QMap <QString, User> UserManager::loadUsers(const QString& data) {
    ifstream file(data.toStdString());
    if (!file.is_open()) {
        throw runtime_error("File does not exist");
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

    return usersByUsername;
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
    QString database="../../database/users.csv";
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
