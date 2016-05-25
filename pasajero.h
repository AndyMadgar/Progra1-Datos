#ifndef PASAJERO_H
#define PASAJERO_H
#include <QString>

typedef class Pasajero{
public:
    QString nombre;
    QString apellidos;
    QString nacionalidad;
    QString destino;
    int ID;
    int telefono;
    int peso;
    int estatura;
    //ListaEquipaje *equipaje;
    class Pasajero *siguiente;

    Pasajero(QString, QString, int, int, QString, int, int, QString);
}*pasajero;

typedef class listaPasajero{
public:
    pasajero primero;

    listaPasajero(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(pasajero);
    pasajero buscar(int);
    int cuentaPos(int);
    void eliminar(int);
    void Mostrar();

}LPasajeros;

#endif // PASAJERO_H
