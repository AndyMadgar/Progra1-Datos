#include "vagregaequipaje.h"
#include "ui_vagregaequipaje.h"
#include "vagregapasajero.h"
#include "equipaje.h"
#include <QDebug>
#include "hilo.h"

vagregaequipaje::vagregaequipaje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vagregaequipaje)
{
    ui->setupUi(this);
}

vagregaequipaje::~vagregaequipaje()
{
    delete ui;
}

void vagregaequipaje::on_btnVolver_clicked()
{
    vagregapasajero *v = new vagregapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;
    v->amo=this->amo;
    v->revisarAmo();
    v->show();
    this->close();
}

void vagregaequipaje::on_btnAgregar_clicked(){

    int peso = ui->txfPeso->text().toInt();
    bool isMano = ui->chxMano->checkState() == 1;

    Equipaje *nuevo = new Equipaje(peso, this->amo, isMano);
    this->amo->equipaje->insertar(nuevo);

    vagregapasajero *v = new vagregapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;
    v->amo=this->amo;
    v->revisarAmo();
    v->show();
    this->close();
}
