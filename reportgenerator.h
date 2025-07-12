#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QDialog>

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
