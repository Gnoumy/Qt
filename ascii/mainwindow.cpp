#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QColor>
#include <QStringList>
#include <QDebug>
#include <QChar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList couleur;
         couleur << "blue" << "red" << "black" << "green";

    ui->setupUi(this);
    ui->comboBox_couleurCaractere->addItems(couleur);
    ui->comboBox_couleurRectangle->addItems(couleur);
    ui->comboBox_couleurTrait->addItems(couleur);
    connect(ui->pushButton_genererFichiers, SIGNAL(pressed()), this, SLOT(genererFichiers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::genererFichiers()
{
    for(int i=33; i<240; i++){
        QPixmap *pixmap = new QPixmap(100,100);
        pixmap->fill(Qt::transparent);
        QPainter *painter= new QPainter(pixmap);
        // Définition du stylo et de la brosse
        QPen pen(QColor(Qt::blue));
        QBrush brush(QColor (Qt::blue));
        QString couleurCaractere = ui->comboBox_couleurTrait->currentText();
        QString couleurTrait = ui->comboBox_couleurCaractere->currentText();
        QString couleurRectangle = ui->comboBox_couleurRectangle->currentText();

        brush.setColor(couleurTrait);
        pen.setColor(couleurCaractere);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawText(0, 0, 100, 100, Qt::AlignCenter, QString((char)i));

        painter->end();
        pixmap->save(QString("/home/formation/Qt/ascii/fichier%1.png").arg(i));
    // Une fois la painter fermé on sauve le pixmap dans un fichier
    }
}
