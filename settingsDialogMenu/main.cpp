#include "mainwindow.h"
#include <QApplication>
#include "configpolice.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //définition des paramètres
    a.setOrganizationName("exerciceFont");
    a.setOrganizationDomain("CS");
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings s;

    //initialisation des paramètres de la FONT
    QFont font;
    font.setFamily(s.value("Police/family").toString());
    font.setPixelSize(s.value("Police/size").toInt());

    //ajout de la FONT au programme
    a.setFont(font);

    MainWindow w;
    w.show();

    return a.exec();
}
