#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>

namespace Ui {
class Reports;
}

class Reports : public QWidget
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

private:
    Ui::Reports *ui;
};

#endif // REPORTS_H
