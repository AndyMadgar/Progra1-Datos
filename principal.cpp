#include "principal.h"
#include "ui_principal.h"
#include "vagregapasajero.h"
#include "vagregartren.h"
#include "vmuestrapasajero.h"
#include "vmuestraviajes.h"
#include <QString>
#include <QThread>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_btnAgregaPasajeros_clicked()
{
    vagregapasajero *v = new vagregapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    v->setVisible(true);
    this->hide();
    v->show();
    v->activateWindow();
    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::on_btnAgregaTren_clicked()
{
    vagregartren *v = new vagregartren();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    v->setVisible(true);
    this->hide();
    v->show();

    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::distribuirTickets(){//W.I.P. - Crear boleteria
    Pasajero *tmp = this->colaTicket->primero;
    while(tmp != NULL){
        this->colaEspera->Push(tmp);
        this->colaTicket->Pop();
        tmp = tmp->siguiente;
    }
}

void Principal::actualizar(){
    ui->lstEspera->clear();
    ui->lstTickets->clear();
    ui->lstViajes->clear();
    Pasajero *tmp1 = this->colaTicket->primero;
    while(tmp1 != NULL){
        QString x = tmp1->nombre + "|" + QString::number(tmp1->ID);
        ui->lstTickets->addItem(x);
        tmp1 = tmp1->siguiente;
    }

    Viaje *tmp = this->colaViajes->primero;
    while(tmp != NULL){
        QString x = tmp->transporte->destino + "|" + tmp->transporte->placa;
        ui->lstViajes->addItem(x);
        tmp = tmp->siguiente;
    }

    this->distribuirTickets();

    Pasajero *tmp2 = this->colaEspera->primero;
    while(tmp2 != NULL){
        QString x = tmp2->nombre + "|" + QString::number(tmp2->ID);
        ui->lstEspera->addItem(x);
        tmp2 = tmp2->siguiente;
    }
}

void Principal::on_lstTickets_itemDoubleClicked()
{
    vmuestrapasajero *v = new vmuestrapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    int id = ui->lstTickets->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaTicket->buscar(id);

    v->setVisible(true);
    this->hide();
    v->show();

    while(v->isActiveWindow()){

    }
    this->show();

}

void Principal::on_lstEspera_itemDoubleClicked()
{
    vmuestrapasajero *v = new vmuestrapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    int id = ui->lstEspera->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaEspera->buscar(id);

    v->setVisible(true);
    this->hide();
    v->show();
    v->actualizar();
    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::on_lstViajes_itemDoubleClicked()
{
    vmuestraviajes *v = new vmuestraviajes();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    QString id = ui->lstViajes->currentItem()->text().split("|").at(1);
    v->viaje= this->colaViajes->buscar(id);
    this->hide();
    v->show();
    while(v->isActiveWindow()){


    }
    this->show();
}
