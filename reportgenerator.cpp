#include "reportgenerator.h"
#include "ui_reportgenerator.h"

reportGenerator::reportGenerator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reportGenerator)
{
    ui->setupUi(this);
}

reportGenerator::~reportGenerator()
{
    delete ui;
}
