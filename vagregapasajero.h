#ifndef VAGREGAPASAJERO_H
#define VAGREGAPASAJERO_H
#include <QDialog>
#include "pasajero.h"

namespace Ui {
class vagregapasajero;
}

class vagregapasajero : public QDialog{
    Q_OBJECT

public:
    explicit vagregapasajero(QWidget *parent = 0);
    ~vagregapasajero();
    Pasajero *amo = NULL;
    listaPasajero *colaTicket = new listaPasajero();

private slots:
    void on_btnVolver_clicked();
    void on_btnAgregar_clicked();
    void on_btnAgregarMaleta_clicked();

private:
    Ui::vagregapasajero *ui;
};

#endif // VAGREGAPASAJERO_H
