#include "mondialog.h"
#include "ui_mondialog.h"

MonDialog::MonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonDialog)
{
    ui->setupUi(this);
}

MonDialog::~MonDialog()
{
    delete ui;
}
