#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QRegExp>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir = dir.homePath();
    QStringList listeFichier = dir.entryList();

    QRegExp exp("\\.\\w{3}$");
    foreach ( QString l, listeFichier){
        if ( l.contains(exp) == true)
            qDebug() << l;
    }

    return a.exec();
}
