#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QDialog>
#include <QApplication>
#include <QCloseEvent>
#include <QString>
#include <core.h>

namespace Ui {
class reportGenerator;
}

class reportGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit reportGenerator(const QString& username, QWidget *parent = nullptr);
    explicit reportGenerator(QWidget *parent = nullptr);
    ~reportGenerator();

private slots:
    void on_exportButton_clicked();

    void on_GenerateReports_Back_clicked();

private:
    Ui::reportGenerator *ui;
    QString currentUser;
    QString reportText;

    void generateSimpleReport(const QString& timestamp);
};

#endif
