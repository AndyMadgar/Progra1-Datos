#include "hilo.h"
#include <QDebug>
#include <QString>
#include "principal.h"

Hilo::Hilo(listaPasajero *pasajeros, listaViajes *viajes){
    this->ventanaPrincipal->colaEspera = new listaPasajero();
    this->ventanaPrincipal->colaTicket = pasajeros;
    this->ventanaPrincipal->colaViajes = viajes;
}

void Hilo::run(){
    int i = 0;
    this->ventanaPrincipal->setVisible(true);
    this->ventanaPrincipal->show();
    while(true){
        qDebug() << "Hola Mundo: " << i;
        i++;
        this->ventanaPrincipal->on_btnActualizar_clicked();
        this->sleep(1);
    }
}
