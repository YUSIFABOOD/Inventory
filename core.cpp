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


bool Authenticator::checkPass(QString name, QString pass, QMap<QString,User> map)
{
    auto it = map.find(name);
    if (it != map.end()) {
        return it.value().getPass() == pass;
    }
    return false;
}


QString Authenticator::login (QString name, QString pass)
{
    QString database = "../../database/users.csv";
    QMap <QString, User>usersByUsername = UserManager::loadUsers(database);
    if(name.isEmpty()||pass.isEmpty())
    {throw std::runtime_error("Username and Password cannot be empty");}
    if(!usersByUsername.count(name))
    {throw std::runtime_error("User does not exist");}
    if(!checkPass(name, pass, usersByUsername))
    {throw std::runtime_error("Invaild password");}
    return (usersByUsername.find(name).value().getRole());
}


QMap<QString, User> UserManager::loadUsers(const QString& data) {
    QMap<QString, User> users;
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
            users[QString::fromStdString(username)] =
                User(QString::fromStdString(username),
                     QString::fromStdString(password),
                     QString::fromStdString(role));
        }
    }

    return users;
}

void UserManager::addUser(QString name, QString pass, QString role)
{
    QString database = "../../database/users.csv";
    QMap <QString, User>usersByUsername = UserManager::loadUsers(database);
    if(name.isEmpty()||pass.isEmpty())
    {throw std::runtime_error("Username and Password cannot be empty");}
    if(usersByUsername.count(name))
    {throw std::runtime_error("User already exists");}
    if(!Authenticator::ValidatePass(pass))
    {throw std::runtime_error("Password should consist of characters and numbers");}
    else
    {
        ofstream File(database.toStdString(), ios_base::app);
        if (File.is_open()) {
            File << name.toStdString() << ","
                 << pass.toStdString() << ","
                 << role.toStdString() << endl;
            File.close();
        } else {
            throw std::runtime_error("Cannot access the database");
        }
    }
}

bool Authenticator::ValidatePass(QString& pass)
{
    QRegularExpression letterRegex("[A-Za-z]");
    QRegularExpression numberRegex("[0-9]");

    return pass.contains(letterRegex) && pass.contains(numberRegex);
}

void UserManager::deleteUser(const QString& name)
{
    QString database = "../../database/users.csv";
    QMap <QString, User>usersByUsername = UserManager::loadUsers(database);
    ofstream File(database.toStdString());
    for(auto it=usersByUsername.begin(); it!= usersByUsername.end();++it)
    {
        if (it.value().getUsername()==name) continue;
        if (File.is_open()) {
            File << it.value().getUsername().toStdString() << ","
                 << it.value().getPass().toStdString() << ","
                 << it.value().getRole().toStdString() << endl;
        } else {
            throw std::runtime_error("Cannot access the database");
        }
    }
    File.close();
}


void UserManager::loadTableFromCSV(QTableWidget* table, const QString& filePath) {
    ifstream file(filePath.toStdString());
    if (!file.is_open()) {
        qWarning("Cannot open file");
        return;
    }

    table->setRowCount(0);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels(QStringList() << "Username" << "Password" << "Role");

    string line;
    int row = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, role;

        if (getline(ss, username, ',') &&
            getline(ss, password, ',') &&
            getline(ss, role, ',')) {

            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(username)));
            table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(password)));
            table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(role)));

            ++row;
        }
    }

    file.close();
}
