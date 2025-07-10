#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QWidget>

namespace Ui {
class Admin_Page;
}

class Admin_Page : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Page(QWidget *parent = nullptr);
    ~Admin_Page();

private:
    Ui::Admin_Page *ui;
};

#endif // ADMIN_PAGE_H
