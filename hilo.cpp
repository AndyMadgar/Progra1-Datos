#include "hilo.h"
#include <QDebug>
#include <QString>

Hilo::Hilo(){}

void Hilo::run(){
    int i = 0;

    this->ventanaPrincipal->show();

    while(true){
        qDebug() << "Hola Mundo: " << i;
        i++;
        //aqui deberia actualizar.
        this->ventanaPrincipal->actualizar();
        if(this->ventanaPrincipal->isActiveWindow()){
            qDebug() << "jajajajaja";
        }
        this->sleep(1);
    }
}

