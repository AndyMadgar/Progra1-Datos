#ifndef VMUESTRAPASAJERO_H
#define VMUESTRAPASAJERO_H

#include <QDialog>
#include "pasajero.h"
#include "tren.h"
#include "viaje.h"

namespace Ui {
class vmuestrapasajero;
}

class vmuestrapasajero : public QDialog
{
    Q_OBJECT

public:
    explicit vmuestrapasajero(QWidget *parent = 0);
    ~vmuestrapasajero();
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaViajes *colaViajes = new listaViajes();
    Pasajero *amo;
    void actualizar();

private:
    Ui::vmuestrapasajero *ui;
};

#endif // VMUESTRAPASAJERO_H
