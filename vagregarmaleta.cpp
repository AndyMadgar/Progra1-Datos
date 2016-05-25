#include "vagregarmaleta.h"
#include "ui_vagregarmaleta.h"
#include "pasajero.h"

vAgregarMaleta::vAgregarMaleta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vAgregarMaleta)
{
    ui->setupUi(this);
}

vAgregarMaleta::~vAgregarMaleta()
{
    delete ui;
}

void vAgregarMaleta::on_pushButton_clicked()
{
    int peso=ui->txtfPesoMaleta->text().toInt();
    bool isInHand=ui->chkbxHand->checkState()==1;

    Equipaje(int pPeso, Pasajero *pAmo, bool pHand);

    this->close();
}
