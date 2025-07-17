#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"
namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
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
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    void setUsername(const QString &username);
    void updateInventoryStats();
    QString currentUser;


private slots:
    void on_InventoryButton_clicked();

    void on_addItemButton_clicked();

    void on_reportsButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
