#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class loginPage;
}
QT_END_NAMESPACE

class loginPage : public QMainWindow
{
    Q_OBJECT

public:
    loginPage(QWidget *parent = nullptr);
    ~loginPage();

private slots:
    void on_loginButton_clicked();

private:
    Ui::loginPage *ui;
};
#endif // LOGINPAGE_H
