#ifndef CORE_H
#define CORE_H

#include <QString>

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
 //verification functions
};

class UserManager {
//container for the users
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

public:
    void addItem(const Item& item);
    void saveToFile(const QString& filePath) const;
//search functions
};

class ReportGenerator {
    public:
    //functions to generate a report. A report contains summary of all items in the inventory, and low-stock items.
    static void generatorReport(const Inventory& inventory, const Qstring& filename);
};

#endif // CORE_H
