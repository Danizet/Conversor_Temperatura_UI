#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectar el Dial de centigrados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->inFah, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kel(int)));

    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2cent(int)));

    connect(ui->inFah, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2kel(int)));

    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2fahr(int)));
}

Conversor::~Conversor()
{
    delete ui;

}

void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int cf = (grados * 9.0/5) +32;
        ui->inFah->setValue(cf);
    }
}

void Conversor::fahr2cent(int grados)
{
    if (ui->inFah->hasFocus()){
        int fc = (grados - 32) * 5.0/9;
        ui->inCent->setValue(fc);
    }
}

void Conversor::cent2kel(int grados)
{
    if (ui->inCent->hasFocus()){
        int ck = (grados + 273.15);
        ui->inKel->setValue(ck);
    }
}

void Conversor::kel2cent(int grados)
{
    if (ui->inKel->hasFocus()){
        int kc = (grados - 273.15);
        ui->inCent->setValue(kc);
    }
}

void Conversor::fahr2kel(int grados)
{
    if (ui->inFah->hasFocus()){
        int fk = ((grados - 32) * 5.0/9) + 273.15;
        ui->inKel->setValue(fk);
    }
}

void Conversor::kel2fahr(int grados)
{
    if (ui->inKel->hasFocus()){
        int kf = ((grados - 273.15) * 9.0/5) + 32;
        ui->inFah->setValue(kf);
    }
}

