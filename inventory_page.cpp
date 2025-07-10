#include "inventory_page.h"
#include "ui_inventory_page.h"

Inventory_Page::Inventory_Page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inventory_Page)
{
    ui->setupUi(this);
}

Inventory_Page::~Inventory_Page()
{
    delete ui;
}
