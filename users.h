#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QList>
#include "User.h"

class Admin : public User {
public:
    Admin(const QString& uname, const QString& pwd);


    bool addUser(QList<User*>& users, const QString& uname, const QString& pwd, const QString& role);
    bool validatePassword(const QString& pwd) const;
    void saveUsersToFile(const QList<User*>& users, const QString& filename) const;
    void loadUsersFromFile(QList<User*>& users, const QString& filename) const;
    void listUsers(const QList<User*>& users) const;
    bool deleteUser(QList<User*>& users, const QString& uname);
};



class Staff : public User {
public:
    Staff(const QString& uname, const QString& pwd);


    void viewInventory(const QList<Item>& inventory) const;
};
class Manager : public User {
public:
    Manager(const QString& uname, const QString& pwd);


    void viewInventory(const QList<Item>& inventory) const;
    bool addItem(QList<Item>& inventory, const Item& newItem);


    void generateReport(const QList<Item>& inventory, const QString& filename) const;
};




#endif // USERS_H
