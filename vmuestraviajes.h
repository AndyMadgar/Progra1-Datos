#ifndef VMUESTRAVIAJES_H
#define VMUESTRAVIAJES_H
#include "viaje.h"
#include "pasajero.h"
#include <QDialog>

namespace Ui {
class vmuestraviajes;
}

class vmuestraviajes : public QDialog
{
    Q_OBJECT

public:
    explicit vmuestraviajes(QWidget *parent = 0);
    ~vmuestraviajes();
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaViajes *colaViajes = new listaViajes();
    Viaje *viaje;
    void acctualizarHoras();

private:
    Ui::vmuestraviajes *ui;
};

#endif // VMUESTRAVIAJES_H
