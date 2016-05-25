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
    listaPasajero *colaEspera = new listaPasajero();
    listaPasajero *colaTicket = new listaPasajero();
    listaTrenes *colaTrenes = new listaTrenes();

private slots:
    void on_btnAgregaPasajeros_clicked();

    void on_btnAgregaTren_clicked();

    void on_btnActualizar_clicked();

    void on_lstTickets_itemDoubleClicked();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
