#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T05:06:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Estacion_Trenes
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    pasajero.cpp \
    tren.cpp \
    equipaje.cpp \
    vagregapasajero.cpp \
    vagregaequipaje.cpp \
    vagregartren.cpp \
    vmuestrapasajero.cpp \
    hilo.cpp \
    ticket.cpp \
    viaje.cpp \
    controlador.cpp

HEADERS  += principal.h \
    pasajero.h \
    tren.h \
    equipaje.h \
    vagregapasajero.h \
    vagregaequipaje.h \
    vagregartren.h \
    vmuestrapasajero.h \
    hilo.h \
    ticket.h \
    viaje.h \
    controlador.h

FORMS    += principal.ui \
    vagregapasajero.ui \
    vagregaequipaje.ui \
    vagregartren.ui \
    vmuestrapasajero.ui

RESOURCES += \
    Imagenes.qrc

OTHER_FILES += \
    Datos/Pasajeros.xlsx \
    Datos/Viajes.xlsx
