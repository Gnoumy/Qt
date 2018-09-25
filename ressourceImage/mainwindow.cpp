#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap image(":/images/wallpaper.jpg");
    ui->label->setPixmap(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
