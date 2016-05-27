#include "hilo.h"
#include <QDebug>
#include <QString>
#include "principal.h"

Hilo::Hilo(){}

void Hilo::run(){
    int i = 0;
    this->dios->setVisible(false);
    //this->dios->show();
    while(true){
        qDebug() << "Hola Mundo: " << i;
        i++;
        //aqui deberia actualizar.
        this->dios->ventanaPrincipal->actualizar();
        if(this->dios->ventanaPrincipal->isActiveWindow()){
            qDebug() << "jajajajaja";
        }
        this->sleep(1);
    }
}
