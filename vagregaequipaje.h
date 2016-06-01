#ifndef VAGREGAEQUIPAJE_H
#define VAGREGAEQUIPAJE_H
#include <QDialog>
#include "pasajero.h"

namespace Ui {
class vagregaequipaje;
}

class vagregaequipaje : public QDialog{
    Q_OBJECT

public:
    explicit vagregaequipaje(QWidget *parent = 0);
    ~vagregaequipaje();
    //Declaracion de atributos
    Pasajero *amo;

private slots:

    void on_btnAgregar_clicked();

private:
    Ui::vagregaequipaje *ui;
};

#endif // VAGREGAEQUIPAJE_H
