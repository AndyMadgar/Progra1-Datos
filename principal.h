#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QMainWindow>
#include "pasajero.h"
#include "tren.h"
#include "viaje.h"
#include "ticket.h"
#include "vagregapasajero.h"
#include "vagregartren.h"
#include "vmuestrapasajero.h"
#include "vmuestraviajes.h"
/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Declaracion de la ventana principal
*/
namespace Ui {
class Principal;
}

class Principal : public QMainWindow{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();
    //Declaracion de atributos
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaViajes *colaViajes = new listaViajes();
    //Declaracion de atributos
public slots:
    void on_btnAgregaPasajeros_clicked();

    void on_btnAgregaTren_clicked();

    void on_lstTickets_itemDoubleClicked();

    void distribuirTickets();

    void abordarLosTrenes();

    void EliminarViaje(Viaje*);

    void RevisarFin();

    void actualizar();

    listaViajes *cargarViajes();

    listaPasajero *cargarPasajeros();

    bool calcEspacio(class Pasajero*, Tren *tren);

private slots:
    void on_lstEspera_itemDoubleClicked();

    void on_lstViajes_itemDoubleClicked();


private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
