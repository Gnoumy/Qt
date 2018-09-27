#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QString>
#include <QTableView>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/formation/Qt/sqlQueryModel/mabase.db");
    db.open();
    ui->setupUi(this);

    QSqlQuery query("SELECT DISTINCT dep FROM villes");
         while (query.next()) {
             ui->comboBox_selectionnerDepartement->addItem(query.value(0).toString());
         }
    connect(ui->comboBox_selectionnerDepartement, SIGNAL(currentIndexChanged(QString)), this, SLOT(afficherVilles(QString)));
    connect(ui->tableView_afficherDepartement, SIGNAL(pressed(QModelIndex)), this, SLOT(afficherInfos(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherVilles(QString departement)
{
    this->model->setQuery(QString("SELECT  ncc,pole, com  FROM villes WHERE dep='%1'").arg(departement));

    this->model->setHeaderData(0, Qt::Horizontal, tr("Villes"));
    this->model->setHeaderData(1, Qt::Horizontal, tr("Code Postal"));
    ui->tableView_afficherDepartement->setModel(model);
    ui->tableView_afficherDepartement->show();
}
void MainWindow::afficherInfos(QModelIndex infosVille)
{
    ui->lineEdit_infosVille->setText(infosVille.data().toString());
}
