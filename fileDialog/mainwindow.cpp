#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuitter, SIGNAL(triggered(bool)),this, SLOT(close()));
    connect(ui->actionOuvrir_un_fichier, SIGNAL(triggered(bool)),this, SLOT(ouvrirFichier()));
    connect(ui->actionA_Propos, SIGNAL(triggered(bool)),this, SLOT(aide()));
    connect(ui->actionDerniers_fichiers_ouverts, SIGNAL(triggered(bool)),this, SLOT(listeFichier()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::aide()
{
    this->fenetre->exec();
}
void MainWindow::ouvrirFichier()
{
    QString path = QFileDialog::getOpenFileName(this);
    QFile file(path);

    if (file.open(QFile::ReadOnly | QFile::Truncate)) {
          QTextStream out(&file);
          ui->textEdit->setPlainText(out.readAll());
          file.close();
      }
}

void MainWindow::listeFichier()
{
    //lister les fichiers ouverts précédement...
}
