#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_nom->setText("Gaucher");
    ui->lineEdit_prenom->setText("Julien");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ok_clicked()
{
    /*ui->lineEdit_prenom->setDisabled(true);
    ui->lineEdit_prenom->setText("Coucou");*/
}

void MainWindow::on_pushButton_ok_clicked(bool checked)
{
    qDebug() <<checked;
    if(checked == true){
        ui->lineEdit_prenom->setDisabled(true);
        ui->lineEdit_prenom->setText("Coucou");
        qDebug() << "if: " <<checked;
    }
    else{
        ui->lineEdit_prenom->setDisabled(false);
        ui->lineEdit_prenom->setText("AHAHAH");
        qDebug() << "else: " <<checked;
        ui->pushButton_ok->setChecked(true);
        checked = true;
        qDebug()<<checked;
    }
}
