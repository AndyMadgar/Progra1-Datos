#include "hilo.h"
#include <QDebug>
#include <QString>
#include "principal.h"

Hilo::Hilo(listaPasajero *pasajeros, listaViajes *viajes)
{
    p->colaEspera = new listaPasajero();
    p->colaTicket = pasajeros;
    p->colaViajes = viajes;
    p->setVisible(true);
    p->show();
}

void Hilo::run(){
    int i = 0;
    while(true){
        qDebug() << "Hola Mundo: " << i;
        i++;
        //p->on_btnActualizar_clicked();
        this->sleep(1);
    }

}
