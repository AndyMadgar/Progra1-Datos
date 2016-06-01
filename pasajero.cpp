#include "pasajero.h"
#include "equipaje.h"
#include "ticket.h"
#include <QDebug>

/*
 * Contructor
 * Entradas: Datos necesarios para crear el pasajero
 * Salidas: ninguna
*/
Pasajero::Pasajero(QString pNombre, QString pApellido, int pID, int pTel, QString pNacionalidad, int pPeso, int pEstatura, QString pDestino,int pCant){
    this->nombre = pNombre;
    this->apellidos = pApellido;
    this->ID = pID;
    this->telefono = pTel;
    this->nacionalidad = pNacionalidad;
    this->peso = pPeso;
    this->estatura = pEstatura;
    this->destino = pDestino;
    this->cantTickets = pCant;
    this->ticketsComprados = new listaTickets();
    this->equipaje = new listaEquipaje();
    this->siguiente = NULL;
    this->anterior = NULL;
}

/*
 * Funcion que se encarga de insertar un nuevo pasajero a la lista
 * Entradas: El pasajero a insertar
 * Salidas: Ninguna
 * Restricciones: El pasajero a insertar no puede ser nulo.
*/
void listaPasajero::Push(Pasajero *pPasajero){
    if(listaVacia()){
        this->primero = pPasajero;
        this->primero->anterior = NULL;
    }
    else{
        Pasajero *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = pPasajero;
        tmp->siguiente->anterior = tmp;
    }
}

/*
 * Funcion que se encarga de eliminar un pasajero dado de la lista
 * Entradas: El pasajero a eliminar
 * Salidas: Ninguna
 * Restricciones: El pasajero a elimnar no puede ser nulo
*/
void listaPasajero::eliminar(Pasajero *cliente){
    if(listaVacia()){
        return;
    }
    else{
        Pasajero *tmp = this->primero;
        while(tmp != NULL){
            if(tmp == cliente){
                if((tmp->anterior == NULL) && (tmp->siguiente != NULL)){
                    qDebug() << "Elimina el primero";
                    this->primero->siguiente->anterior = NULL;
                    this->primero = this->primero->siguiente;
                    break;
                }
                else if(tmp->anterior == NULL && tmp->siguiente == NULL){
                    qDebug() << "Solo un elemento";
                    this->primero = NULL;
                    break;
                }
                else if((tmp->siguiente == NULL) && (tmp->anterior != NULL)){
                    qDebug() << "Elimina el ultimo";
                    tmp->anterior->siguiente = NULL;
                    tmp->anterior = NULL;
                    break;
                }
                else if(tmp->siguiente != NULL && tmp->anterior != NULL){
                    qDebug() << "Elimina en medio";
                    tmp->anterior->siguiente = tmp->siguiente;
                    tmp->siguiente->anterior = tmp->anterior;
                    break;
                }
            }
            tmp = tmp->siguiente;
        }
    }
    qDebug() << "Sale de la funcion";
    this->mostrar();
}

/*
 * Funcion que se encarga de mostrar los elementos de la lista
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void listaPasajero::mostrar(){
    if(listaVacia()){
        qDebug() << "La lista es vacia -.-";
    }
    else{
        Pasajero *tmp = this->primero;
        while(tmp != NULL){
            qDebug() << "Mostrando el ID: " << tmp->ID;
            tmp = tmp->siguiente;
        }
    }
}


/*
 * Funcion que se encarga buscar un pasajero en la lista de pasajeros
 * Entradas: La Id del pasajero a buscar
 * Salidas: El pasajero encontrado
*/
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
