#include "temperatura.h"
#include "ui_temperatura.h"
#include <QtDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2Cent(int)));
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
        float f= valor * 9.0/5 + 32;
        ui->dialFahr->setValue(f);
     }
}

void Temperatura::fahr2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
       float c = (valor - 32) * 5.0/9;
       ui->dialCent->setValue(c);
    }
}


