#include "principal.h"
#include "ui_principal.h"
#include "vagregapasajero.h"
#include "vagregartren.h"
#include "vmuestrapasajero.h"
#include <QString>
#include <QDebug>


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
    v->colaTrenes = this->colaTrenes;

    v->setVisible(true);
    this->close();
    v->exec();
}
void Principal::on_btnAgregaTren_clicked()
{
    vagregartren *v = new vagregartren();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaTrenes = this->colaTrenes;

    v->setVisible(true);
    this->close();
    v->exec();
}

void Principal::on_btnActualizar_clicked()
{
    ui->lstTickets->repaint();
    Pasajero *tmp = this->colaTicket->primero;
    while(tmp != NULL){
        QString x = tmp->nombre + "|" + QString::number(tmp->ID);
        qDebug() << x;
        ui->lstTickets->addItem(x);
        tmp = tmp->siguiente;
    }
}

void Principal::on_lstTickets_itemDoubleClicked()
{
    vmuestrapasajero *v = new vmuestrapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaTrenes = this->colaTrenes;

    int id = ui->lstTickets->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaTicket->buscar(id);

    v->setVisible(true);
    this->close();
    v->exec();

}
