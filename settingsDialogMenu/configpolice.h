#ifndef CONFIGPOLICE_H
#define CONFIGPOLICE_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class ConfigPolice;
}

class ConfigPolice : public QDialog
{
    Q_OBJECT

public:
    QFont *configFont = new QFont;
    explicit ConfigPolice(QWidget *parent = 0);
    ~ConfigPolice();

signals:
    void setFont(QFont font);

private:
    Ui::ConfigPolice *ui;

private slots:
    void sauvegarder();
    void afficher();
};

#endif // CONFIGPOLICE_H
