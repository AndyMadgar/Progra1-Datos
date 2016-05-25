#include "hilo.h"
#include <QDebug>
#include <QString>

Hilo::Hilo()
{
}

void Hilo::run(){
    int i = 0;
    while(true){
        qDebug() << "Hola Mundo" << i;
        i++;
        this->sleep(1);
    }
}
