#ifndef INVENTORY_PAGE_H
#define INVENTORY_PAGE_H

#include <QWidget>

namespace Ui {
class Inventory_Page;
}

class Inventory_Page : public QWidget
{
    Q_OBJECT

public:
    explicit Inventory_Page(QWidget *parent = nullptr);
    ~Inventory_Page();

private:
    Ui::Inventory_Page *ui;
};

#endif // INVENTORY_PAGE_H
