#include "viaje.h"
#include <QDebug>

/*
 * Constructor
 * Entradas: Datos para crear un nuevo Viaje
 * Salidas: El viaje ya creado
*/
Viaje::Viaje(Tren *pTransporte, QDateTime pInicio, QDateTime pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
    this->anterior = NULL;
}

/*
 * Constructor
 * Entradas: Ninguna
 * Salidas: Ninguna
 */
Viaje::Viaje(){
    this->transporte = NULL;
    this->inicio = QDateTime::currentDateTime();
    this->final = QDateTime::currentDateTime();
    this->siguiente = NULL;
    this->anterior = NULL;
}

/*
 * Funcion que se encarga de agregar nuevo viajes a la lista de viajes.
 * Entradas: El viaje a agregar
 * Salidas: Ninguna
 * Restricciones: El viaje a agregar no puede ser nulo
*/
void listaViajes::Push(Viaje *nuevo){
    if(listaVacia()){
        this->primero = nuevo;
        this->primero->anterior = NULL;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
        tmp->siguiente->anterior = tmp;
    }
}

/*
 * Funcion que se encarga de eliminar un viaje de la lista de viajes
 * Entradas: El viaje a eliminar.
 * Salidas: Ninguna
 * Restricciones: El viaje no puede ser nulo
*/
void listaViajes::eliminar(Viaje *viaje){
    if(listaVacia()){
        return;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp != NULL){
            if(tmp == viaje){
                if(tmp->anterior == NULL){
                    qDebug() << "Elimina el primero";
                    this->primero->siguiente->anterior = NULL;
                    this->primero = this->primero->siguiente;
                    break;
                }
                else if(tmp->siguiente == NULL){
                    qDebug() << "Elimina el ultimo";
                    tmp->anterior->siguiente = NULL;
                    tmp->anterior = NULL;
                    break;
                }
                else{
                    qDebug() << "Elimina en medio";
                    tmp->anterior->siguiente = tmp->siguiente;
                    tmp->siguiente->anterior = tmp->anterior;
                    break;
                }
            }
            else{
                tmp = tmp->siguiente;
            }
        }
    }
}

/*
 * Funcion que busca un viaje especifico en la lista de viajes
 * Entradas: La placa del tren que realiza el viaje.
 * Salidas: El viaje a realizar.
*/
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

/*
 * Funcion que se encarga de buacar si existe un viaje con el destino especificado
 * Entradas: El destino que se quiere buscar
 * Salidas: El viaje, si este existe
*/
Viaje *listaViajes::buscarDestino(QString Destino){
    if(listaVacia()){
        return NULL;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp != NULL){
            if(tmp->transporte->destino == Destino){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        Viaje *x = new Viaje();
        return x;
    }
}
