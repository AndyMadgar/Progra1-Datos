#ifndef VAGREGARTRENES_H
#define VAGREGARTRENES_H

#include <QDialog>

namespace Ui {
class vAgregarTrenes;
}

class vAgregarTrenes : public QDialog
{
    Q_OBJECT

public:
    explicit vAgregarTrenes(QWidget *parent = 0);
    ~vAgregarTrenes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vAgregarTrenes *ui;
};

#endif // VAGREGARTRENES_H
