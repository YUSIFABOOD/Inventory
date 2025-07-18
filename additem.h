#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"
namespace Ui {
class addItem;
}

class addItem : public QDialog
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
    explicit addItem(QWidget *parent = nullptr);
    ~addItem();
    bool CheckNumbers(QString& n);

signals:
    void itemAdded(); 

private slots:
    void on_add_item_button_clicked();
    void on_backButton_clicked();
private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
