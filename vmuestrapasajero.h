#ifndef VMUESTRAPASAJERO_H
#define VMUESTRAPASAJERO_H
#include <QDialog>
#include "pasajero.h"

namespace Ui {
class vmuestrapasajero;
}

class vmuestrapasajero : public QDialog{
    Q_OBJECT

public:
    explicit vmuestrapasajero(QWidget *parent = 0);
    ~vmuestrapasajero();
    Pasajero *amo;
    void actualizar();

private:
    Ui::vmuestrapasajero *ui;
};

#endif // VMUESTRAPASAJERO_H
