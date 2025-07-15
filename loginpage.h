#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include <QCloseEvent>
#include <QMainWindow>
#include <QApplication>
#include <core.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class loginPage;
}
QT_END_NAMESPACE

class loginPage : public QMainWindow
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
    loginPage(QWidget *parent = nullptr);
    ~loginPage();

private slots:
    void on_loginButton_clicked();

private:
    Ui::loginPage *ui;
};
#endif // LOGINPAGE_H
