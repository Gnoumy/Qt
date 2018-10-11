#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include <QDebug>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(0,0,200,200);
    QMainWindow::paintEvent(event); //on passe la méthode fille à la méthode mère
    qDebug() << this->width() << this->height();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if( event->pos().y() > this->height()-30)
    {
        qDebug() << "Point y: " << event->pos().y() <<endl<< "Point x: " << event->pos().x();
        qDebug() << event;
    }
}
