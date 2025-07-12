#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventory.h"
#include "additem.h"
#include "reportgenerator.h"
Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_InventoryButton_clicked()
{
    Inventory* inventory = new Inventory(this);
    inventory->show();
}

void Dashboard::on_addItemButton_clicked()
{
    addItem* additem = new addItem(this);
    additem->show();
}


void Dashboard::on_reportsButton_clicked()
{
    reportGenerator* generate = new reportGenerator(this);
    generate->show();
}

