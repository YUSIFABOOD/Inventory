#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"
namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event) override {
        qDebug() << "X button clicked - saving users";
        UserManager::saveUsers();
        event->accept();
        QApplication::quit();  // This makes aboutToQuit work!
    }
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
