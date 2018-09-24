#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(editingFinished()),
                 this,SLOT(afficherConsole()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherConsole()
{
    QString result;
    result = ui->lineEdit->text();
    qDebug() << result.toUpper();
}
