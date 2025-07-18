#ifndef STAFFINVENTORY_H
#define STAFFINVENTORY_H

#include <QDialog>

namespace Ui {
class staffInventory;
}

class staffInventory : public QDialog
{
    Q_OBJECT

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
