#include "configpolice.h"
#include "ui_configpolice.h"
#include <QFont>
#include <QSettings>
#include <QDebug>
ConfigPolice::ConfigPolice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigPolice)
{
    ui->setupUi(this);
    connect(ui->buttonBox_Sauvegarder, SIGNAL(accepted()), this, SLOT(sauvegarder()));
    connect(ui->spinBox_TaillePolice, SIGNAL(valueChanged(int)), this, SLOT(afficher()));
    connect(ui->fontComboBox, SIGNAL(activated(int)), this, SLOT(afficher()));
}

ConfigPolice::~ConfigPolice()
{
    delete ui;
}

//on sauvegarde dans le fichier ExerciceFont.ini
void ConfigPolice::sauvegarder()
{
    QSettings s;
    s.setValue("Police/family", ui->fontComboBox->currentText());
    s.setValue("Police/size"  , ui->spinBox_TaillePolice->value());
}

//
void ConfigPolice::afficher()
{
    QFont fontProgramme;
    QFont font = ui->fontComboBox->currentFont();
    QString nomFont = font.family();
    int value = ui->spinBox_TaillePolice->value();
    fontProgramme.setFamily(nomFont);
    fontProgramme.setPixelSize(value);
    ui->label_affichage->setFont(fontProgramme);
    emit setFont(fontProgramme);
}

