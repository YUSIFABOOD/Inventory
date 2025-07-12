#include "inventory.h"
#include "ui_inventory.h"
#include "additem.h"
Inventory::Inventory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Inventory)
{
    ui->setupUi(this);
}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::on_Add_New_Item_Button_clicked()
{
    addItem* additem = new addItem(this);
    additem->show();
}

