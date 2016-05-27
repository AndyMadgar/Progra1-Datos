#include "vagregapasajero.h"
#include "ui_vagregapasajero.h"
#include "vagregaequipaje.h"
#include "pasajero.h"
#include "QDebug"

vagregapasajero::vagregapasajero(QWidget *parent):QDialog(parent),ui(new Ui::vagregapasajero){
  ui->setupUi(this);
}

vagregapasajero::~vagregapasajero(){
    delete ui;
}

void vagregapasajero::on_btnVolver_clicked(){

    this->colaTicket->Push(this->amo);
    this->close();
}

void vagregapasajero::on_btnAgregar_clicked(){

    QString nombre = ui->txfNombre->text();
    QString apellido = ui->txfApellidos->text();
    QString nacio = ui->txfNacio->text();
    QString destino = ui->cbxDestino->currentText();
    int id = ui->txfID->text().toInt();
    int telf = ui->txfTelefono->text().toInt();
    int peso = ui->txfPeso->text().toInt();
    int estatura = ui->txfEstatura->text().toInt();
    int canTickets=ui->spinnerCantTickets->value();

    Pasajero *nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino,canTickets);
    this->amo=nuevo;
    qDebug()<<this->amo->nombre;
    //Desactivar todos los campos editables y ponerles la informacion del pasajero - W.I.P
    ui->btnAgregarMaleta->setEnabled(true);
    ui->btnAgregar->setEnabled(false);
}

void vagregapasajero::on_btnAgregarMaleta_clicked(){
    vagregaequipaje *v = new vagregaequipaje();
    v->amo = this->amo;
    this->hide();
    v->show();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}
