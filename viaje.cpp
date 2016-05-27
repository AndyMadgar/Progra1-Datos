#include "viaje.h"
#include <QDebug>

Viaje::Viaje(Tren *pTransporte, QDateTime pInicio, QDateTime pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
    //calcular restante y transcurrido
}

Viaje::Viaje(){
    this->transporte = NULL;
    this->inicio = QDateTime::currentDateTime();
    this->final = QDateTime::currentDateTime();
    this->siguiente = NULL;
}

void listaViajes::Push(Viaje *nuevo){
    if(listaVacia()){
        this->primero = nuevo;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}

void  listaViajes::Pop(){
    if (listaVacia()){
    }
    else{
        Viaje *tmp = this->primero;
        this->primero= tmp->siguiente;
    }
}

Viaje *listaViajes::buscar(QString id){
    if(listaVacia()){
        return NULL;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp != NULL){
            if(tmp->transporte->placa == id){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        return NULL;
    }
}

Viaje *listaViajes::buscarDestino(QString Destino){
    qDebug() << "Entro a buscar destino";
    if(listaVacia()){
        qDebug() << "Lista Vacia";
        return NULL;
    }
    else{
        qDebug() << "Lista No Vacia";
        Viaje *tmp = this->primero;
        qDebug() << "Asigna el primero";
        while(tmp != NULL){
            qDebug() << "While 1";
            if(tmp->transporte->destino == Destino){
                qDebug() << "Encontro un viaje";
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        qDebug() << "No encontro nada";
        Viaje *x = new Viaje();
        return x;
    }
}

void listaViajes::ajustarTiempos(){//WIP
    QDateTime actual = QDateTime::currentDateTime();
    Viaje *tmp = this->primero;
    if (tmp->final >= actual){
        this->primero = tmp->siguiente;
    }
    else{
        Viaje *tmp2 = NULL;
        while(tmp->siguiente != NULL){
            actual = QDateTime::currentDateTime();
            if (tmp->final >= actual){
                tmp2 = tmp;
                tmp = NULL;
                tmp = this->primero;
                while(tmp->siguiente != NULL){
                    tmp = tmp->siguiente;
                }
                tmp->siguiente = tmp2->siguiente;
            }

            tmp = tmp->siguiente;
        }
        if (tmp->final >= actual){
            tmp2 = tmp;
            tmp = NULL;
            tmp = this->primero;
            while(tmp->siguiente != NULL){
                tmp = tmp->siguiente;
            }
            tmp->siguiente = tmp2->siguiente;

        }
    }

}
