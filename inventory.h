#ifndef INVENTORY_H
#define INVENTORY_H

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

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();

private slots:
    void on_Add_New_Item_Button_clicked();

private:
    Ui::Inventory *ui;
};

#endif // INVENTORY_H
