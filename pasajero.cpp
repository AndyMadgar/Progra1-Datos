#include "pasajero.h"
#include "equipaje.h"
#include "ticket.h"
#include <QDebug>

Pasajero::Pasajero(QString pNombre, QString pApellido, int pID, int pTel, QString pNacionalidad, int pPeso, int pEstatura, QString pDestino){
    this->nombre = pNombre;
    this->apellidos = pApellido;
    this->ID = pID;
    this->telefono = pTel;
    this->nacionalidad = pNacionalidad;
    this->peso = pPeso;
    this->estatura = pEstatura;
    this->destino = pDestino;
    this->equipaje = new listaEquipaje();
    this->ticketes = new listaTickets();
    this->siguiente = NULL;
}

void listaPasajero::Push(Pasajero *pPasajero){
    if(listaVacia()){
        primero = pPasajero;
    }
    else{
        Pasajero *tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = pPasajero;
    }
}

void listaPasajero::Pop(){
    if (listaVacia()){
        return;
    }
    else{
        Pasajero *tmp = this->primero;
        this->primero= tmp->siguiente;
    }
}

Pasajero *listaPasajero::buscar(int id){
    if(listaVacia()){
        return NULL;
    }
    else{
        Pasajero *tmp = primero;
        while(tmp != NULL){
            if(tmp->ID == id){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        return NULL;
    }
}
