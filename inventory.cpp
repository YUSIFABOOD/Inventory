#include "inventory.h"
#include "ui_inventory.h"
#include "additem.h"
#include "reportgenerator.h"
Inventory::Inventory(QWidget *parent)
    : QDialog(parent), ui(new Ui::Inventory)
{
    ui->setupUi(this);
    ui->Search_Category->addItems({"Name", "Category", "Supplier"});
    InventoryManager::loadItemsIntoTable(ui->Items_Table);

}

Inventory::~Inventory()
{
    delete ui;
}



void Inventory::on_Add_New_Item_Button_clicked()
{
    addItem* additem = new addItem(this);
    connect(additem, &addItem::itemAdded, this, [this]() {
    InventoryManager::loadItemsIntoTable(ui->Items_Table);
    itemsModified = true;
    });
    
    additem->show(); 
}

void Inventory::on_searchButton_clicked()
{
    QString category = ui->Search_Category->currentText();
    QString searchText = ui->Search_bar->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter text to search.");
        return;
    }
    try{
    InventoryManager::performSearch(category, searchText, ui->Items_Table);
    }
    catch (const std::runtime_error& e)
    {
        QMessageBox::warning(this, "No matching result", "Search on another item");
    }
}






void Inventory::on_backButton_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->hide();
}


void Inventory::on_pushButton_clicked()
{
    int row = ui->Items_Table->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an item to delete.");
        return;
    }

    QString item = ui->Items_Table->item(row, 0)->text();
    QString supplier=ui->Items_Table->item(row, 4)->text();
    try {
        InventoryManager::deleteItem(item, supplier); 
        ui->Items_Table->removeRow(row);    
        itemsModified = true; 
        QMessageBox::information(this, "Success", "Item deleted successfully.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


