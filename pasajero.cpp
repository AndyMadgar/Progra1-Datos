#include "pasajero.h"
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
    this->siguiente = NULL;
}

void listaPasajero::insertar(pasajero pPasajero){
    if(listaVacia()){
        primero = pPasajero;
    }
    else{
        pasajero tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = pPasajero;
    }
}

pasajero listaPasajero::buscar(int id){
    if(listaVacia()){
        return NULL;
    }
    else{
        pasajero tmp = primero;
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

int listaPasajero::cuentaPos(int id){
    int pos = 0;
    if(listaVacia()){
        return pos;
    }
    else{
        pasajero tmp = primero;
        while(tmp != NULL){
            if(tmp->ID == id){
                return pos;
            }
            pos++;
            tmp = tmp->siguiente;
        }
        return 0;
    }
}

void listaPasajero::eliminar(int pos){
    if(pos == 0){
        return;
    }
    else{
        pasajero tmp = primero;
        while(tmp != NULL && pos != 1){
            tmp = tmp->siguiente;
            pos--;
        }
        tmp->siguiente = tmp->siguiente->siguiente;
    }
    return;
}

void listaPasajero::Mostrar(){
    if(listaVacia()){
        qDebug() << "No hay elementos en la lista";
        return;
    }
    else{
        pasajero tmp = primero;
        while(tmp != NULL){
            qDebug() << "Nombre: " << tmp->nombre;
            qDebug() << "Apellido: " << tmp->apellidos;
            qDebug() << "ID: " << tmp->ID;
            qDebug() << "Telefono: " << tmp->telefono;
            qDebug() << "Nacionalidad: " << tmp->nacionalidad;
            qDebug() << "Peso: " << tmp->peso;
            qDebug() << "Estatura: " << tmp->estatura;
            qDebug() << "Destino: " << tmp->destino;
            qDebug() << "\n";
            tmp = tmp->siguiente;
        }
    }
}
