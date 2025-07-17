#include "inventory.h"
#include "ui_inventory.h"
#include "additem.h"
#include "reportgenerator.h"
Inventory::Inventory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Inventory)
{
    ui->setupUi(this);
    InventoryManager::loadItems("../database/items.csv");
    ui->Search_Category->addItems({"Name", "Category", "Supplier"});
    loadItemsIntoTable();

}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::performSearch(const QString& type, const QString& text)
{
    ui->Items_Table->setRowCount(0);
    int row = 0;
    bool found = false;
    QMap<QString, Item>& items = InventoryManager::getInventory();
    for (auto it = items.begin(); it != items.end(); ++it) {
        const Item& item = it.value();
        bool match = false;

        if (type == "Name" && item.getName().contains(text, Qt::CaseInsensitive)) {
            match = true;
        } else if (type == "Category" && item.getCategory().contains(text, Qt::CaseInsensitive)) {
            match = true;
        } else if (type == "Supplier" && item.getSupplier().contains(text, Qt::CaseInsensitive)) {
            match = true;
        }

        if (match) {
            ui->Items_Table->insertRow(row);
            ui->Items_Table->setItem(row, 0, new QTableWidgetItem(item.getName()));
            ui->Items_Table->setItem(row, 1, new QTableWidgetItem(item.getCategory()));
            ui->Items_Table->setItem(row, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
            ui->Items_Table->setItem(row, 3, new QTableWidgetItem(QString::number(item.getPrice())));
            ui->Items_Table->setItem(row, 4, new QTableWidgetItem(item.getSupplier()));
            ++row;
            found = true;
        }
    }
    if (!found) {
        QMessageBox::information(this, "No Results", "No matching items found.");
    }
}


void Inventory::loadItemsIntoTable() {
    const auto& items = InventoryManager::getInventory();
    ui->Items_Table->setRowCount(0);
    int row = 0;
    ui->Items_Table->setColumnCount(5);
    ui->Items_Table->setHorizontalHeaderLabels({"Name", "Category", "Quantity", "Price", "Supplier"});

    for (auto it = items.begin(); it != items.end(); ++it) {
        const Item& item = it.value();
        ui->Items_Table->insertRow(row);
        ui->Items_Table->setItem(row, 0, new QTableWidgetItem(item.getName()));
        ui->Items_Table->setItem(row, 1, new QTableWidgetItem(item.getCategory()));
        ui->Items_Table->setItem(row, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
        ui->Items_Table->setItem(row, 3, new QTableWidgetItem(QString::number(item.getPrice())));
        ui->Items_Table->setItem(row, 4, new QTableWidgetItem(item.getSupplier()));
        ++row;
    }
}


void Inventory::on_Add_New_Item_Button_clicked()
{
    addItem* additem = new addItem(this);
    additem->show();
    if (additem->exec() == QDialog::Accepted) {
        loadItemsIntoTable();
    }
}

void Inventory::on_searchButton_clicked()
{
    QString category = ui->Search_Category->currentText();
    QString searchText = ui->Search_bar->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter text to search.");
        return;
    }

    performSearch(category, searchText);

}


void Inventory::on_pushButton_clicked()
{

}


void Inventory::on_generateReport_clicked()
{
    hide();
    reportGenerator * window = new reportGenerator( this);
    window->show();
}

