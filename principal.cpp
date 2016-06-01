#include "principal.h"
#include "ui_principal.h"
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QThread>

/* Constructor de la ventana  principal
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
Principal::Principal(QWidget *parent):QMainWindow(parent),ui(new Ui::Principal){
    ui->setupUi(this);
    this->colaEspera = new listaPasajero();
    this->colaTicket = this->cargarPasajeros();
    this->colaViajes = this->cargarViajes();
}

Principal::~Principal(){
    delete ui;
}

/*
 * Funcion que se ajecuta cuando le da clic al boton Agregar Pasajero
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::on_btnAgregaPasajeros_clicked(){
    vagregapasajero *v = new vagregapasajero();
    v->colaTicket = this->colaTicket;
    this->hide();
    v->show();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}

/*
 * Funcion que se ejecuta cuando le da clic al boton Agregar Tren
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::on_btnAgregaTren_clicked(){
    vagregartren *v = new vagregartren();
    v->colaViajes = this->colaViajes;
    this->hide();
    v->show();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}

/*
 * Funcion que se encarga de distribuir los tickets a los pasajeros esperando
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::distribuirTickets(){

    listaPasajero *colaRecompra = new listaPasajero();
    Pasajero *pasajeroAtendido = this->colaTicket->primero;
    while(pasajeroAtendido != NULL){
        Tren *trenAsignado = this->colaViajes->buscarDestino(pasajeroAtendido->destino)->transporte;
        if(trenAsignado != NULL){    //busca si ya hay un viaje que tenga un tren con su destino
            int cant = pasajeroAtendido->cantTickets;
            while(cant != 0){     //compra la cantidad de tiquetes que quiere
                Ticket *ticketComprado = new Ticket(cant,trenAsignado,pasajeroAtendido->destino);
                pasajeroAtendido->ticketsComprados->insertar(ticketComprado);
                cant = cant-1;
            }
            this->colaEspera->Push(pasajeroAtendido);
            this->colaTicket->eliminar(pasajeroAtendido);
            QThread::sleep(1); //atiende a una persona cada medio segundo
            pasajeroAtendido = pasajeroAtendido->siguiente;
        }
        else{//si no hay lo saca de la cola y lo vuelve a meter al final hasta que haya un tren
            colaRecompra->Push(pasajeroAtendido);
            this->colaTicket->eliminar(pasajeroAtendido);
            QThread::sleep(1);
            pasajeroAtendido = pasajeroAtendido->siguiente; //atiende al siguiente
            if(pasajeroAtendido == NULL){
                break;
            }
        }
    }    //termina de recorrer la cola de pasajeros si tickets

    Pasajero *tmp = colaRecompra->primero;
    while(tmp != NULL){
        colaRecompra->eliminar(tmp);
        colaTicket->Push(tmp);
        tmp = tmp->siguiente;
    }//pone los que no pudieron conseguir tren en la cola de boleteria
    qDebug() << "refrescó la boletería";
}

/*
 * Funcion que se encarga de hacer que cada pasajero aborde su respectivo tren
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::abordarLosTrenes(){
    Pasajero *tmp = this->colaEspera->primero;
    while(tmp != NULL){
        QString placaDeMiTren = tmp->ticketsComprados->primero->transporte->placa;
        Viaje *tmp2 = this->colaViajes->primero;
        while(tmp2 != NULL){
            if(tmp2->transporte->placa == placaDeMiTren){
                //Calcular el espacio del tren y despues agregarlo
                if(calcEspacio(tmp, tmp2->transporte)){
                    tmp2->transporte->listaAsientos->Push(tmp);
                    //eliminar el pasajero de la cola de espera.
                }
                else{
                    this->colaTicket->Push(tmp);
                    //eliminar el pasajero de la cola de espera.
                }
                break;
            }
            else{
                tmp2 = tmp2->siguiente;
            }
        }
        tmp = tmp->siguiente;
    }
}

/*
 * Funcion que se encarga de calcular si hay suficiente espacio en un tren para un pasajero
 * Entradas: El pasajero a calcular el espacio, el tren a calcular si hay espacio
 * Salidas: Un booleano si el pasajero cabe en dicho tren
*/
bool Principal::calcEspacio(Pasajero *cliente, Tren *tren){
    int pesoCliente = cliente->peso;
    int pesoBodega = 0;
    Equipaje *tmp = cliente->equipaje->primero;
    while(tmp != NULL){
        if(tmp->isInHand){
            pesoCliente += tmp->peso;
        }
        else{
            pesoBodega += tmp->peso;
        }
        tmp = tmp->siguiente;
    }
    if(pesoCliente > tren->pesoPasajero && pesoBodega > tren->pesoBodega){
        return false;
    }
    else{
        tren->pesoBodega -= pesoBodega;
        tren->pesoPasajero -= pesoCliente;
        return true;
    }
}

void Principal::RevisarFin(){
    QDateTime actual = QDateTime::currentDateTime();
    Viaje *tmp = this->colaViajes->primero;
    while(tmp != NULL){
        if(tmp->final.operator >=(actual)){
            this->colaViajes->eliminar(tmp);
        }
        else{
            tmp = tmp->siguiente;
        }
    }
}

/*
 * Funcion que permite cargar los pasajeros desde un archivo .xlsx
 * Entradas: Ninguna
 * Salidas: Lista de pasajeros con todos los datos cargados desde el archivo
*/
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

        nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino,1);
        Equipaje *mal = new Equipaje(pesoMaleta, nuevo, isHand);
        nuevo->equipaje->insertar(mal);
        lista->Push(nuevo);
    }
    file.flush();
    file.close();
    return lista;

}

/*
 * Funcion que permite cargar los viajes desde un archivo .xlsx
 * Entradas: Ninguna
 * Salidas: Lista de viajes con todos los datos cargados desde el archivo
*/
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

/*
 * Funcion que actualiza las listas en la interfaz y se las muestra al usuario
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::actualizar(){
    ui->lstEspera->clear();
    ui->lstTickets->clear();
    ui->lstViajes->clear();
    Pasajero *tmp1 = this->colaTicket->primero;
    ui->lstTickets->addItem("Nombre|ID");
    while(tmp1 != NULL){
        QString x = tmp1->nombre + "|" + QString::number(tmp1->ID);
        ui->lstTickets->addItem(x);
        tmp1 = tmp1->siguiente;
    }
    Viaje *tmp = this->colaViajes->primero;
    ui->lstViajes->addItem("Destino|Placa");
    while(tmp != NULL){
        QString x = tmp->transporte->destino + "|" + tmp->transporte->placa;
        ui->lstViajes->addItem(x);
        tmp = tmp->siguiente;
    }  
    this->distribuirTickets();//Boleteria
    Pasajero *tmp2 = this->colaEspera->primero;
    ui->lstEspera->addItem("Nombre|ID");
    while(tmp2 != NULL){
        QString x = tmp2->nombre + "|" + QString::number(tmp2->ID);
        ui->lstEspera->addItem(x);
        tmp2 = tmp2->siguiente;
    }
}

/*
 * Funcion que se ejecuta cuando se le da doble clic a un elemento de la lista en la interfaz
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::on_lstTickets_itemDoubleClicked(){
    vmuestrapasajero *v = new vmuestrapasajero();
    int id = ui->lstTickets->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaTicket->buscar(id);
    this->hide();
    v->show();
    v->actualizar();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}

/*
 * Funcion que se ejecuta cuando se le da doble clic a un elemento de la lista en la interfaz
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::on_lstEspera_itemDoubleClicked(){
    vmuestrapasajero *v = new vmuestrapasajero();
    int id = ui->lstEspera->currentItem()->text().split("|").at(1).toInt();
    v->amo = this->colaEspera->buscar(id);
    this->hide();
    v->show();
    v->actualizar();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}

/*
 * Funcion que se ejecuta cuando se le da doble clic a un elemento de la lista en la interfaz
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void Principal::on_lstViajes_itemDoubleClicked(){
    vmuestraviajes *v = new vmuestraviajes();
    QString id = ui->lstViajes->currentItem()->text().split("|").at(1);
    v->viaje= this->colaViajes->buscar(id);
    this->hide();
    v->show();
    v->actualizar();
    //HILO O ALGO ASI QUE NO HAGA NADA MIENTRAS LA VENTANA ESTA ABIERTA
    this->show();
}
