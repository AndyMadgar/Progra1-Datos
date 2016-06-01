#ifndef VIAJE_H
#define VIAJE_H
#include "tren.h"
#include <QDateTime>

/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Lista Doble Enlazada
 * Para Viajes
*/
class Viaje{
public:
    //Declaracion de atributos
    Tren *transporte;
    QDateTime inicio;
    QDateTime final;
    int transcurrido;
    int restante;
    class Viaje *siguiente;
    class Viaje *anterior;
    //Constructores
    Viaje();
    Viaje(Tren*, QDateTime, QDateTime);
};

//Lista para el manejo de los viajes
class listaViajes{
public:
    //Declaracion de atributos
    class Viaje *primero;
    //Constructor
    listaViajes(){primero = NULL;}
    //Declaracion funciones
    bool listaVacia(){return primero == NULL;}
    void Push(Viaje *);
    //void Pop();
    void eliminar(Viaje *);
    Viaje *buscar(QString);
    Viaje *buscarDestino(QString);

};

#endif // VIAJE_H
