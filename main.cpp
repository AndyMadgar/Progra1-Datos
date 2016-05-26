#include "principal.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "pasajero.h"
#include "tren.h"
#include "equipaje.h"
#include "hilo.h"
#include "viaje.h"

listaPasajero *pasajeros = new listaPasajero();
listaViajes *listViajes = new listaViajes();

void cargarPasajeros(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Pasajeros.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de pasajeros";
        return;
    }
    Pasajero *nuevo;

    QTextStream in(&file);
    QString nombre;
    QString apellido;
    int id;
    int telf;
    QString nacio;
    int peso;
    int estatura;
    QString destino;
    int pesoMaleta;
    bool isHand;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        nombre = data.at(0);
        apellido = data.at(1);
        id = data.at(2).toInt();
        telf = data.at(3).toInt();
        nacio = data.at(4);
        peso = data.at(5).toInt();
        estatura = data.at(6).toInt();
        destino = data.at(7);
        pesoMaleta = data.at(8).toInt();
        isHand = data.at(9).toInt() == 1; // 1=true 0=false

        nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino);
        Equipaje *mal = new Equipaje(pesoMaleta, nuevo, isHand);
        nuevo->equipaje->insertar(mal);
        pasajeros->Push(nuevo);
    }
    file.flush();
    file.close();

}

void cargarViajes(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Viajes.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de trenes";
        return;
    }
    Tren *nuevo;
    Viaje *viajeNuevo;
    QTextStream in(&file);
    QString destino;
    QString capitan;
    QString placa;
    QDateTime inicio;
    QDateTime final;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        capitan = data.at(0);
        placa = data.at(1);
        destino = data.at(2);
        QDateTime actual = QDateTime::currentDateTime();
        inicio = actual.addSecs(data.at(3).toInt());
        final = inicio.addSecs(data.at(4).toInt());
        nuevo = new Tren(destino, capitan, placa);
        viajeNuevo = new Viaje(nuevo, inicio, final);
        listViajes->Push(viajeNuevo);
    }
    file.flush();
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cargarPasajeros();
    cargarViajes();
    Hilo *h1 = new Hilo(pasajeros, listViajes);
    h1->start();

    return a.exec();
}
