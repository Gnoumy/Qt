#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("villes");
    model->select();

    ui->tableView_afficherVille->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}
