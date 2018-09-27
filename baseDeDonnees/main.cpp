#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("/home/formation/Qt/baseDeDonnees/mabase.db");
    db.setDatabaseName(a.applicationDirPath()+"/mabase.db");

    qDebug()<<a.applicationDirPath();

    MainWindow w;
    w.show();

    return a.exec();
}
