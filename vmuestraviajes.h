#ifndef VMUESTRAVIAJES_H
#define VMUESTRAVIAJES_H
#include "viaje.h"
#include <QDialog>

namespace Ui {
class vmuestraviajes;
}

class vmuestraviajes : public QDialog{
    Q_OBJECT

public:
    explicit vmuestraviajes(QWidget *parent = 0);
    ~vmuestraviajes();
    Viaje *viaje;
    void actualizarHoras();
    void actualizar();

private:
    Ui::vmuestraviajes *ui;
};

#endif // VMUESTRAVIAJES_H