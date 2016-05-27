#ifndef VAGREGAEQUIPAJE_H
#define VAGREGAEQUIPAJE_H

#include <QDialog>
#include "pasajero.h"
#include "tren.h"
#include "viaje.h"

namespace Ui {
class vagregaequipaje;
}

class vagregaequipaje : public QDialog
{
    Q_OBJECT

public:
    explicit vagregaequipaje(QWidget *parent = 0);
    ~vagregaequipaje();

    Pasajero *amo;
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaViajes *colaViajes = new listaViajes();


private slots:
    void on_btnVolver_clicked();

    void on_btnAgregar_clicked();

private:
    Ui::vagregaequipaje *ui;
};

#endif // VAGREGAEQUIPAJE_H
