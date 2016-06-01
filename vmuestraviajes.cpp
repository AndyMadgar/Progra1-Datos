#include "vmuestraviajes.h"
#include "ui_vmuestraviajes.h"
#include <QDebug>

vmuestraviajes::vmuestraviajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vmuestraviajes)
{
    ui->setupUi(this);
}

vmuestraviajes::~vmuestraviajes()
{
    delete ui;
}

void vmuestraviajes::actualizarHoras(){

}

/*
 * Funcion que se ejecuta cuando se le da clic al boton actualizar, muestra los datos del viaje en al ventana correspondiente.
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void vmuestraviajes::actualizar(){
    ui->txfCapitan->setText(this->viaje->transporte->capitan);
    ui->txfDestino->setText(this->viaje->transporte->destino);
    ui->txfLlegada->setText(this->viaje->final.toString());
    ui->txfPlaca->setText(this->viaje->transporte->placa);
    ui->txfRestante->setText(QString::number(this->viaje->restante));
    ui->txfSalida->setText(this->viaje->inicio.toString());
    ui->txfTranscurrido->setText(QString::number(this->viaje->transcurrido));

    Pasajero *tmp1 = this->viaje->transporte->listaAsientos->primero;
    ui->lstPasajeros->addItem("Nombre|ID");
    while(tmp1 != NULL){
        qDebug() << "Entre al while 1";
        QString x = tmp1->nombre + "|" + QString::number(tmp1->ID);
        ui->lstPasajeros->addItem(x);
        tmp1 = tmp1->siguiente;
    }

    Equipaje *tmp2= this->viaje->transporte->bodega->primero;
    ui->lstEquipaje->addItem("Nombre|Peso");
    while(tmp2 != NULL){
        qDebug() << "Entre al while 2";
        QString y = tmp2->amo->nombre + "|" + QString::number(tmp2->peso) ;
        ui->lstEquipaje->addItem(y);
        tmp2 = tmp2->siguiente;

    }
}

