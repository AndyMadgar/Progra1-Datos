#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "pasajero.h"
#include "tren.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();
    listaPasajero *ColaEspera;
    listaPasajero *ColaTickets;
    listaTrenes ListaTrenes;

private slots:
    void on_btnAgregaPasajero_clicked();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
