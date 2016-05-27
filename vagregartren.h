#ifndef VAGREGARTREN_H
#define VAGREGARTREN_H

#include <QDialog>
#include "principal.h"
#include "pasajero.h"
#include "tren.h"
#include "viaje.h"

namespace Ui {
class vagregartren;
}

class vagregartren : public QDialog{
    Q_OBJECT

public:
    explicit vagregartren(QWidget *parent = 0);
    ~vagregartren();
    listaViajes *colaViajes = new listaViajes();

private slots:
    void on_btnVolver_clicked();
    void on_btnAgregar_clicked();

private:
    Ui::vagregartren *ui;
};

#endif // VAGREGARTREN_H
