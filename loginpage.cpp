#include "loginpage.h"
#include "ui_loginpage.h"
#include "core.h"
#include "adminpage.h"
#include "dashboard.h"
#include "staffinventory.h"
#include <QMessageBox>
loginPage::loginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_loginButton_clicked()
{

    QString name= ui->usernameBox->text();
    QString pass= ui->passwordBox->text();
    try{
        if(name=="admin"&&pass=="admin")
        {
            adminpage* admin = new adminpage(this);
            admin->show();
            this->hide();
        }

        else if(Authenticator::login(name, pass)=="Manager")
        {
            Dashboard* dashboard = new Dashboard(this);
            dashboard->setUsername(name);
            dashboard->show();
            this->hide();
        }
        else if(Authenticator::login(name, pass)=="Staff")
        {
            staffInventory* inventory = new staffInventory(this);
            inventory->show();
            this->hide();
        }
    }
    catch (const std::runtime_error& e) {
        QMessageBox::critical(this, "Login Failed", e.what());}

}

