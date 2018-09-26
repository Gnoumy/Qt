#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configpolice.h"
#include <QSettings>
#include <QFont>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionConfig, SIGNAL(triggered(bool)),this,SLOT(afficherConfig()));

    //on instancie l'objet ConfigPolice afin de récuperer le signal émit par la Classe
    fenetre = new ConfigPolice(this);
    connect(fenetre, SIGNAL(setFont(QFont)), this, SLOT(maFont(QFont)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherConfig()
{
    this->fenetre->exec();
}

void MainWindow::maFont(QFont nouvelleFont)
{
    QFont ancienneFont;
    QString nomFont = nouvelleFont.family();
    int value = nouvelleFont.pixelSize();

    ancienneFont.setFamily(nomFont);
    ancienneFont.setPixelSize(value);
}
