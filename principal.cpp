#include "principal.h"
#include "ui_principal.h"
#include "vagregapasajero.h"
#include "vagregartren.h"
#include "vmuestrapasajero.h"
#include "vmuestraviajes.h"
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    this->colaEspera = new listaPasajero();
    this->colaTicket = this->cargarPasajeros();
    this->colaViajes = this->cargarViajes();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_btnAgregaPasajeros_clicked()
{
    vagregapasajero *v = new vagregapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    v->setVisible(true);
    this->hide();
    v->show();
    v->activateWindow();
    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::on_btnAgregaTren_clicked()
{
    vagregartren *v = new vagregartren();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    v->setVisible(true);
    this->hide();
    v->show();

    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::distribuirTickets(){//W.I.P. - Crear boleteria
    Pasajero *tmp = this->colaTicket->primero;
    while(tmp != NULL){
        this->colaEspera->Push(tmp);
        this->colaTicket->Pop();
        tmp = tmp->siguiente;
    }
}

void Principal::actualizar(){
    ui->lstEspera->clear();
    ui->lstTickets->clear();
    ui->lstViajes->clear();
    Pasajero *tmp1 = this->colaTicket->primero;
    while(tmp1 != NULL){
        QString x = tmp1->nombre + "|" + QString::number(tmp1->ID);
        ui->lstTickets->addItem(x);
        tmp1 = tmp1->siguiente;
    }

    Viaje *tmp = this->colaViajes->primero;
    while(tmp != NULL){
        QString x = tmp->transporte->destino + "|" + tmp->transporte->placa;
        ui->lstViajes->addItem(x);
        tmp = tmp->siguiente;
    }

    this->distribuirTickets();

    Pasajero *tmp2 = this->colaEspera->primero;
    while(tmp2 != NULL){
        QString x = tmp2->nombre + "|" + QString::number(tmp2->ID);
        ui->lstEspera->addItem(x);
        tmp2 = tmp2->siguiente;
    }
}

void Principal::on_lstTickets_itemDoubleClicked()
{
    vmuestrapasajero *v = new vmuestrapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    int id = ui->lstTickets->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaTicket->buscar(id);

    v->setVisible(true);
    this->hide();
    v->show();

    while(v->isActiveWindow()){

    }
    this->show();

}

void Principal::on_lstEspera_itemDoubleClicked()
{
    vmuestrapasajero *v = new vmuestrapasajero();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaViajes = this->colaViajes;

    int id = ui->lstEspera->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaEspera->buscar(id);

    v->setVisible(true);
    this->hide();
    v->show();
    v->actualizar();
    while(v->isActiveWindow()){

    }
    this->show();
}

void Principal::on_lstViajes_itemDoubleClicked()
{
    vmuestraviajes *v = new vmuestraviajes();

    QString id = ui->lstViajes->currentItem()->text().split("|").at(1);
    v->viaje= this->colaViajes->buscar(id);

    this->hide();
    v->show();
    v->actualizar();
    while(v->isActiveWindow()){


    }
    this->show();
}

listaPasajero* Principal::cargarPasajeros(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Pasajeros.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de pasajeros";
        return NULL;
    }
    listaPasajero *lista = new listaPasajero();
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
        lista->Push(nuevo);
    }
    file.flush();
    file.close();
    return lista;

}

listaViajes *Principal::cargarViajes(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Viajes.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de trenes";
        return NULL;
    }
    Tren *nuevo;
    Viaje *viajeNuevo;
    listaViajes *lista = new listaViajes();
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
        lista->Push(viajeNuevo);
    }
    file.flush();
    file.close();
    return lista;
}

