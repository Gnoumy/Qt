#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHash>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->personne["Julien"] = 32;
    this->personne["Kim"] = 42;
    this->personne["Hannibal"] = 46;
    this->personne["Schtroumpf"] = 54;
    this->personne["James"] = 29;

    ui->setupUi(this);

    //ajouter tous les éléments du QHash personne dans le comboBox
    ui->comboBox->addItems(personne.keys());

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)),
                 this,SLOT(afficherAge()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherAge()
{
    QString prenom = ui->comboBox->currentText();
    QString resultat;
    int age = this->personne[prenom];
    ui->lineEdit->setText(resultat.setNum(age, 10));
}
