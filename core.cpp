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

QMap<QString, User> UserManager::usersByUsername;

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
    QMap <QString, User >usersByUsername = UserManager::loadUsers("../../database/users.csv");
    if(name.isEmpty()||pass.isEmpty())
    {throw std::runtime_error("Username and Password cannot be empty");}
    if(!usersByUsername.count(name))
    {throw std::runtime_error("User does not exist");}
    if(!checkPass(name, pass, usersByUsername))
    {throw std::runtime_error("Invaild password");}
    return (usersByUsername.find(name).value().getRole());
}




void UserManager::addUser(QString name, QString pass, QString role)
{
    if(name.isEmpty()||pass.isEmpty())
    {throw std::runtime_error("Username and Password cannot be empty");}
    if(usersByUsername.count(name))
    {throw std::runtime_error("User already exists");}
    if(!Authenticator::ValidatePass(pass))
    {throw std::runtime_error("Password should consist of characters and numbers");}
    else
    {usersByUsername[name]=User(name, pass, role);}
}


bool Authenticator::ValidatePass(QString& pass)
{
    QRegularExpression letterRegex("[A-Za-z]");
    QRegularExpression numberRegex("[0-9]");

    return pass.contains(letterRegex) && pass.contains(numberRegex);
}

void UserManager::deleteUser(const QString& name)
{

    usersByUsername.remove(name);
}
void InventoryManager::AddItem(QString& name, QString& quantity,   QString& price,   QString& supplier, QString& category  ){

    if(name.isEmpty()||quantity.isEmpty()||price.isEmpty()|| supplier.isEmpty(), category.isEmpty() ){
        throw runtime_error {"Error: You cannot add an empty item  "};

    }
    if (quantity.toInt()<0|| price.toInt()<0) {
        throw runtime_error {"Only postive numbers"};
    }
    QString key ;
    key = name+supplier;
    if (items.count(key)){
        throw runtime_error {"Item already exsit"} ;

    }
 else {
    items[key]=Item( name, category, quantity.toInt(), price.toInt(), supplier);

    }
}