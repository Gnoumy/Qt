#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QList>
#include <QStringList>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit_saisir, SIGNAL(editingFinished()),
                 this,SLOT(afficherConsole()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherConsole()
{
    QStringList listPrenom;
    QString result;
    listPrenom << "Jules" << "Julius" << "Juliette" << "Jerome" << "Justine";

    QCompleter *completer = new QCompleter(listPrenom, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_saisir->setCompleter(completer);


    result = ui->lineEdit_saisir->text();
    qDebug() << result;
}
