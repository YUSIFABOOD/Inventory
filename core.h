#ifndef CORE_H
#define CORE_H
#include <QMap>
#include <QString>
#include <iostream>
#include <QTableWidget>
using namespace std;
class User {
private:
    QString username;
    QString password;
    QString role;

public:
    User(): username(""), password(""), role(""){};
    User(const QString& uname, const QString& pword, const QString& r): username(uname), password(pword), role(r){};
    QString getUsername() const{return username;}
    QString getRole() const{return role;}
    QString getPass() const{return password;}
    void setUsername (const QString& newUsername);
};

class Authenticator {
    static QMap<QString, User> usersByUsername;
public:
    Authenticator();
    static QString login (QString name, QString pass);
    bool userExists(const QString& name) const;
    static bool checkPass(QString, QString, QMap<QString, User>);
    static bool ValidatePass(QString& pass);
};

class UserManager {
    static QMap<QString, User> usersByUsername;
public:
    UserManager(){usersByUsername=loadUsers("../../database/users.csv");}
    static void deleteUser(const QString& username);
    User* findUser(QMap<QString, User>&) const;
    static QMap <QString, User> loadUsers(const QString& data);
    static void addUser(QString, QString, QString);
    static void updateTable(QTableWidget* table);
    static QMap <QString, User> getData();
    static void saveUsers();
};

class Item {
private:
    QString name;
    QString category;
    int quantity;
    double price;
    QString supplier;

public:
    Item(const QString& n, const QString& cat, int qty, double pr, const QString& supp);
    QString getName() const;
    QString getSupplier() const;
    QString getPrice () const;
    QString getQuantity () const;
};




#endif // CORE_H
