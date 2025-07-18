#ifndef INVENTORY_H
#define INVENTORY_H
#include <QMessageBox>
#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"
namespace Ui {
class Inventory;
}

class Inventory : public QDialog
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event) override {
        qDebug() << "X button clicked - saving users";
        UserManager::saveUsers();
        InventoryManager::saveItems();
        event->accept();
        QApplication::quit();  // This makes aboutToQuit work!
    }
public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();
    bool wasModified() const { return itemsModified; }
private slots:
    void on_Add_New_Item_Button_clicked();

    void on_searchButton_clicked();

    void on_backButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Inventory *ui;
    bool itemsModified = false;
};

#endif // INVENTORY_H
