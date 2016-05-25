#include "vagregarpasajero.h"
#include "ui_vagregarpasajero.h"
#include "principal.h"
#include "pasajero.h"

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
    QString nombre=ui->txtfNombre->text();
    QString apellidos=ui->txtfNombre->text();
    QString nacionalidad=ui->txtfNombre->text();
    QString destino=ui->cmbxDestino->currentText();
    int ID=ui->txtfID->text().toInt();
    int telefono=ui->txtfTel->text().toInt();
    int peso=ui->txtfPeso->text().toInt();
    int estatura=ui->txtfEstatura->text().toInt();
    Pasajero pas=new Pasajero();
    Principal.ColaTickets->insertar();
}
