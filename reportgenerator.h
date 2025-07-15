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

public:
    explicit reportGenerator(QWidget *parent = nullptr);
    ~reportGenerator();

private:
    Ui::reportGenerator *ui;
};

#endif // REPORTGENERATOR_H
