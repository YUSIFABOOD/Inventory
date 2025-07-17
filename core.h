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
        UserManager(){loadUsers("../database/users.csv");}
    static void deleteUser(const QString& username);
    User* findUser(QMap<QString, User>&) const;
    static void loadUsers(const QString& data);
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
    Item() : name(""), category(""), quantity(0), price(0.0), supplier("") {}
    Item(const QString& n, const QString& cat, int qty, double pr, const QString& supp) : name(n), category(cat), quantity(qty), price(pr), supplier(supp) {};
    QString getName() const{return name;}
    QString getSupplier() const{return supplier;}
    QString getCategory ()const {return category;}
    double getPrice () const{return price;}
    int getQuantity () const{return quantity;}
};

class InventoryManager {
    static QMap<QString, Item> items;
    static QMap<QString, Item> itemsByName;
    static QMap<QString, Item> itemsByCategory;
    static QMap<QString, Item> itemsBySupplier;
public:
        InventoryManager(){loadItems("../database/items.csv");}
    static void loadItems(const QString&);
    static void saveItems();
    static QMap<QString, Item>& getInventory();
    static void AddItem (QString& name, QString& quantity,   QString& price,   QString& supplier, QString& category );
};





#endif // CORE_H
