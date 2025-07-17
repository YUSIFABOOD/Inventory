#include "adminpage.h"
#include "ui_adminpage.h"
#include "core.h"
#include "loginpage.h"
#include "dashboard.h"
#include "inventory.h"
#include <QMessageBox>
adminpage::adminpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminpage)
{
    ui->setupUi(this);
    UserManager::updateTable(ui->userTable);
}

adminpage::~adminpage()
{
    delete ui;
}



void adminpage::on_addUserButton_clicked()
{
    QString name = ui->addNameBox->text();
    QString pass = ui->addPassBox->text();
    QString role = ui->roleBox->currentText();
    try{
        UserManager::addUser(name,pass,role);
        UserManager::updateTable(ui->userTable);
        QMessageBox::information(this, "Done", "User added successfully");
    }
    catch (const std::runtime_error& e) {
        QMessageBox::critical(this, "Add user failed", e.what());}
}


void adminpage::on_adminBack_clicked()
{
    hide();
    loginPage* login = new loginPage(this);
    login->show();
}


void adminpage::on_userDeleteButton_clicked()
{
        int row = ui->userTable->currentRow();
        if (row < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a user to delete.");
            return;
        }

        QString username = ui->userTable->item(row, 0)->text();

        try {
            UserManager::deleteUser(username); // Remove from CSV
            ui->userTable->removeRow(row);     // Remove from table
            QMessageBox::information(this, "Success", "User deleted successfully.");
        } catch (const std::exception& e) {
            QMessageBox::critical(this, "Error", e.what());
        }
}


void adminpage::on_InventoryButton_clicked()
{
    Inventory* inventory = new Inventory;
    inventory->show();
}

