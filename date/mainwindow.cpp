#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QString>
//#include <QSpinBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(-100, 100);

    connect(ui->spinBox, SIGNAL(valueChanged(int)),
                 this,SLOT(afficherDate()));
    connect(ui->calendrier, SIGNAL(clicked(QDate)),
                 this,SLOT(afficherDate()));
    connect(ui->pushButton_quitter, SIGNAL(clicked(bool)),
                 this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherDate()
{
    QDate chaine = ui->calendrier->selectedDate();
    chaine = chaine.addDays(ui->spinBox->value());

    ui->calendrier->setSelectedDate(chaine);
    ui->label->setText(chaine.toString());
}
