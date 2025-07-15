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
        event->accept();
        QApplication::quit();  // This makes aboutToQuit work!
    }
public:
    explicit addItem(QWidget *parent = nullptr);
    ~addItem();

private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
