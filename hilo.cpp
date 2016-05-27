#include "hilo.h"
#include <QDebug>
#include <QString>

Hilo::Hilo(){}

void Hilo::run(){
    int i = 0;
    this->ventanaPrincipal->show();
    while(true){
        qDebug() << "Tiempo de programa: " << i;
        i++;
        this->ventanaPrincipal->actualizar();
        this->sleep(1);
    }
}

