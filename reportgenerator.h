#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include "core.h"
namespace Ui {
class reportGenerator;
}

class reportGenerator : public QDialog
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
    explicit reportGenerator(QWidget *parent = nullptr);
    ~reportGenerator();

private:
    Ui::reportGenerator *ui;
};

#endif // REPORTGENERATOR_H
