#ifndef DIOS_H
#define DIOS_H

#include <QMainWindow>
#include "pasajero.h"
#include "viaje.h"
#include "principal.h"
#include "vagregaequipaje.h"
#include "vagregapasajero.h"
#include "vagregartren.h"
#include "vmuestrapasajero.h"

namespace Ui {
class Dios;
}

class Dios : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dios(QWidget *parent = 0);
    ~Dios();
    Principal *ventanaPrincipal;
    vagregapasajero *agregaPasajero = NULL;
    vagregaequipaje *agregaEquipaje = NULL;
    vagregartren *agregarTren = NULL;
    vmuestrapasajero *mostrarPasajero = NULL;
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaViajes *colaViajes = new listaViajes();
    listaPasajero *cargarPasajeros();
    listaViajes *cargarViajes();

private:
    Ui::Dios *ui;
};

#endif // DIOS_H
