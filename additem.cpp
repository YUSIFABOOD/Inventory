#include "additem.h"
#include "ui_additem.h"
#include "core.h"
#include "dashboard.h"
#include "loginpage.h"
#include <QMessageBox>
#include <stdexcept>
addItem::addItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addItem)
{
    ui->setupUi(this);
}

addItem::~addItem()
{
    delete ui;
}

bool addItem::CheckNumbers(QString& n)
{
    QRegularExpression letterRegex("[A-Za-z]");
    return n.contains(letterRegex);
}
void addItem::on_add_item_button_clicked()
{
    QString name= ui->item_name->text();
    QString category= ui->category->text();
    QString quantity= ui->item_quantity->text();
    QString price= ui->item_price->text();
    QString supplier= ui->supplier_name->text();
    try{
        if(CheckNumbers(quantity)&&CheckNumbers(price)) throw std::runtime_error("Quantity and Price are numerical values");
        InventoryManager::AddItem(name, quantity, price, supplier, category);
        QMessageBox::information(this, "Done", "Item added successfully");

    }
    catch (const std::runtime_error& e) {
        QMessageBox::critical(this, "Add item failed", e.what());}
}

void addItem::on_backButton_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->hide();
}




