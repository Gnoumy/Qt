#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_afficher, SIGNAL(clicked()),
                 this,SLOT(changerText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changerText ()
{
    QString data;
    data = ui->lineEdit_saisir->text();
    ui->lineEdit_afficher->setText(data);
}
