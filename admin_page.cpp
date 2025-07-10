#include "admin_page.h"
#include "ui_admin_page.h"
#include "users.h"
#include "core.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <QRegularExpression>
#include <QMap>

using namespace std;

string staff;
string manager;
bool check = true;



Admin_Page::Admin_Page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Admin_Page)
{
    ui->setupUi(this);
}

Admin_Page::~Admin_Page()
{
    delete ui;
}



Admin::Admin(const QString& username, const QString& password)
    : User(username, password, "admin") {}

bool Admin::validatePassword(const QString& password) const {
    // Must contain at least one uppercase and one digit, min length 6
    QRegularExpression pattern("^(?=.*[A-Z])(?=.*\\d).{6,}$");
    return pattern.match(password).hasMatch();
}

void Admin::addUser(User user, const string& data) {
    ofstream File(data, ios_base::app);
    if (File.is_open()) {
        File << user.getUsername().toStdString() << ","
             << user.getPassword().toStdString() << ","
             << user.getRole().toStdString() << endl;
        File.close();
    } else {
        cerr << "Failed to open file: " << data << endl;
    }
}



QMap<QString, User> loadUsers(const string& data) {
    QMap<QString, User> users;
    ifstream file(data);
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
