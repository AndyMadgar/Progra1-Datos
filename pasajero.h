#ifndef PASAJERO_H
#define PASAJERO_H
#include <QString>

class Pasajero{
public:
    QString nombre;
    QString apellidos;
    QString nacionalidad;
    QString destino;
    int ID;
    int telefono;
    int peso;
    int estatura;
    class listaEquipaje *equipaje;
    class Pasajero *siguiente;

        Pasajero(QString, QString, int, int, QString, int, int, QString);
};

class listaPasajero{
public:
    Pasajero *primero;

    listaPasajero(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(Pasajero *);
    Pasajero *buscar(int);
    int cuentaPos(int);
    void eliminar(int);
    void Mostrar();

};

#endif // PASAJERO_H
