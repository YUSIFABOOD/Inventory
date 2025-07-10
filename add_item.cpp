#include "add_item.h"
#include "ui_add_item.h"

Add_item::Add_item(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Add_item)
{
    ui->setupUi(this);
}

Add_item::~Add_item()
{
    delete ui;
}
