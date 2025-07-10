#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QWidget>

namespace Ui {
class Add_item;
}

class Add_item : public QWidget
{
    Q_OBJECT

public:
    explicit Add_item(QWidget *parent = nullptr);
    ~Add_item();

private:
    Ui::Add_item *ui;
};

#endif // ADD_ITEM_H
