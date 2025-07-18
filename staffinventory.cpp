#include "staffinventory.h"
#include "ui_staffinventory.h"
#include "reportgenerator.h"
#include "inventory.h"
#include "core.h"
#include <QMessageBox>
staffInventory::staffInventory(QWidget *parent)
    : QDialog(parent), ui(new Ui::staffInventory)
{
    ui->setupUi(this);
    ui->Search_Category->addItems({"Name", "Category", "Supplier"});
    InventoryManager::loadItemsIntoTable(ui->Items_Table);
}

staffInventory::~staffInventory()
{
    delete ui;
}

void staffInventory::on_generateReport_clicked()
{
    hide();
    reportGenerator * window = new reportGenerator(currentUser, this);
    window->show();
}


void staffInventory::on_searchButton_clicked()
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


void staffInventory::on_backButton_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->hide();
}

void staffInventory::setUsername(const QString &username)
{
    currentUser = username;
}