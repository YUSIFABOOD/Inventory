#include "loginpage.h"
#include "ui_loginpage.h"
#include "core.h"
#include "adminpage.h"
#include "dashboard.h"
#include "inventory.h"
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
            hide();
            adminpage* admin = new adminpage(this);
            admin->show();
        }

        else if(Authenticator::login(name, pass)=="Manager")
        {
            hide();
            Dashboard* dashboard = new Dashboard(this);
            dashboard->show();
        }
        else if(Authenticator::login(name, pass)=="Staff")
        {
            hide();
            Inventory* inventory = new Inventory(this);
            inventory->show();
        }
    }
    catch (const std::runtime_error& e) {
        QMessageBox::critical(this, "Login Failed", e.what());}

}

