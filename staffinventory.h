#ifndef STAFFINVENTORY_H
#define STAFFINVENTORY_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"

namespace Ui {
class staffInventory;
}

class staffInventory : public QDialog
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override {
        qDebug() << "X button clicked - saving users";
        UserManager::saveUsers();
        InventoryManager::saveItems();
        event->accept();
        QApplication::quit();
    }
public:
    explicit staffInventory(QWidget *parent = nullptr);
    ~staffInventory();
    void performSearch(const QString& type, const QString& text);
    void loadItemsIntoTable();
private slots:
    void on_generateReport_clicked();
    void on_searchButton_clicked();
    void on_backButton_clicked();

private:
    Ui::staffInventory *ui;
};

#endif // STAFFINVENTORY_H
