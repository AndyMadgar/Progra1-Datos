#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T00:52:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = I_Proyecto
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    pasajero.cpp \
    equipaje.cpp \
    ticket.cpp \
    tren.cpp \
    estacionprincipal.cpp \
    viaje.cpp \
    vagregarpasajero.cpp

HEADERS  += principal.h \
    pasajero.h \
    equipaje.h \
    ticket.h \
    tren.h \
    estacionprincipal.h \
    viaje.h \
    vagregarpasajero.h

FORMS    += principal.ui \
    vagregarpasajero.ui

RESOURCES += \
    imagenes.qrc
