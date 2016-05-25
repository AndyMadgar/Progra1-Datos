#include "vagregarpasajero.h"
#include "ui_vagregarpasajero.h"
#include "principal.h"
#include "pasajero.h"
#include "vagregarmaleta.h"
#include <QDebug>
#include "main.cpp"
vAgregarPasajero::vAgregarPasajero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vAgregarPasajero){
    ui->setupUi(this);
}

vAgregarPasajero::~vAgregarPasajero()
{
    delete ui;
}


void vAgregarPasajero::on_btnAgregarPasajero_clicked()
{
    QString pNombre=ui->txtfNombre->text();
    QString pApellido=ui->txtfNombre->text();
    QString pNacionalidad=ui->txtfNombre->text();
    QString pDestino=ui->cmbxDestino->currentText();
    int pID=ui->txtfID->text().toInt();
    int pTelefono=ui->txtfTel->text().toInt();
    int pPeso=ui->txtfPeso->text().toInt();
    int pEstatura=ui->txtfEstatura->text().toInt();

    Principal *p=main.;

    Pasajero *pas = new Pasajero(pNombre, pApellido, pID, pTelefono, pNacionalidad, pPeso, pEstatura, pDestino);

    vAgregarMaleta ventan;
    ventan.setModal(true);
    ventan.amo=pas;
    ventan.ventanaPasajero=this;
    this->setVisible(false);
    ventan.exec();
    qDebug() << "Agregado";

    p->ColaTickets->insertar(pas);

    this->close();
}
