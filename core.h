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

#endif // CORE_H
