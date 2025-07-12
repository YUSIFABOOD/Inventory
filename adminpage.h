#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:

    void on_addUserButton_clicked();

    void on_adminBack_clicked();

    void on_userDeleteButton_clicked();

private:
    Ui::adminpage *ui;
};

#endif // ADMINPAGE_H
