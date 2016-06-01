#include "hilo.h"
#include <QDebug>
#include <QString>

/* Constructor
 * Entradas: Ninguna
 * Salidas: Ninguna
*/

Hilo::Hilo(){}

/*
 * Funcion que ejecuta el hilo una vez creado
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Hilo::run(){
    int i = 0;
    this->ventanaPrincipal->show();
    while(true){
        qDebug() << "Tiempo de programa: " << i;
        i++;
        this->ventanaPrincipal->actualizar();
        //this->ventanaPrincipal->abordarLosTrenes();
        //this->ventanaPrincipal->RevisarFin();
        this->sleep(1);
    }
}

