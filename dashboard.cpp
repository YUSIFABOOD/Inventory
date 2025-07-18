#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventory.h"
#include "additem.h"
#include "reportgenerator.h"
#include <QDateTime>
#include "loginpage.h"
Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    updateInventoryStats();

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_InventoryButton_clicked()
{
    hide();
    Inventory* inventory = new Inventory(this);
    inventory->exec();
    if (inventory->wasModified()) {
        updateInventoryStats(); 
    }
    show(); 
    delete inventory;
}

void Dashboard::on_addItemButton_clicked()
{
    hide();
    addItem* additem = new addItem(this);
    additem->exec();
    updateInventoryStats(); // Always refresh stats when returning from add item dialog
    show();
    delete additem;
}


void Dashboard::on_reportsButton_clicked()
{
    hide();
    reportGenerator* generate = new reportGenerator(this);
    generate->show();
}

void Dashboard::setUsername(const QString &username)
{
    ui->welcome_label->setText("Welcome, " + username);
    currentUser = username;
}

void Dashboard::updateInventoryStats() {
    const auto& map = InventoryManager::getInventory();

    int total = map.size();
    int lowStock = 0;

    for (const auto& item : map) {
        if (item.getQuantity() < 5) lowStock++;
    }

    ui->totalItemsLabel->setText("Total Items: " + QString::number(total));
    ui->lowStockLabel->setText("Low Stock Items: " + QString::number(lowStock));
    ui->lastUpdateLabel->setText(InventoryManager::getLastOperation() + " at " + InventoryManager::getLastModified().toString("hh:mm:ss"));
}


void Dashboard::on_pushButton_clicked()
{

    hide();
    loginPage* login = new loginPage(this);
    login->show();
}



void Dashboard::on_backButton_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->hide();
}

