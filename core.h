#ifndef CORE_H
#define CORE_H

#include <QString>
#include <QVector>

class user {
    private:
    QString username;
    QString password;
    QString role;

    public:
    User(const QString& uname, const QString& pword, const QString& r);
    virtual ~User();
    QString getUsername() const;
    QString getRole() const;
    void setUsername (const QString& newUsername); // for renaming the username after being intialized (i guess)

    virtual bool canManageUsers() const = 0;
    virtual bool canAddItems() const = 0;
    virtual bool canGenerateReports() const = 0;
};

class Authenticator {
public:
    static User* login(const QString& username, const QString& password, const QVector<User*>& users);
};

class UserManager {
private:
    QVector<User*> users;

public:
    void loadUsers(const QString& filename);
    void saveUsers(const QString& filename) const;
    void addUser(User* user);
    void deleteUser(const QString& username);
    User* findUser(const QString& username) const;
    ~UserManager();
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

class Inventory {
private:
    QVector<Item> items;

public:
    void addItem(const Item& item);
    void loadFromFile(const QString& filePath);
    void saveToFile(const QString& filePath) const;

    QVector<Item> searchByName(const QString& name) const; // for searching the items.
    QVector<Item> searchByCategory(const QString& category) const;// mostly we will make it with radio buttons 
    QVector<Item> searchBySupplier(const QString& supplier) const;// to determine which method we will use 
};

#endif // CORE_H
