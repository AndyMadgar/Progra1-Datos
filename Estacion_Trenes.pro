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
    ../../I-Proyecto/I Proyecto/I_Proyecto/ticket.cpp \
    ../../I-Proyecto/I Proyecto/I_Proyecto/viaje.cpp \
    viaje.cpp \
    ticket.cpp

HEADERS  += principal.h \
    pasajero.h \
    tren.h \
    equipaje.h \
    vagregapasajero.h \
    vagregaequipaje.h \
    vagregartren.h \
    vmuestrapasajero.h \
    ../../I-Proyecto/I Proyecto/I_Proyecto/ticket.h \
    ../../I-Proyecto/I Proyecto/I_Proyecto/viaje.h \
    viaje.h \
    ticket.h

FORMS    += principal.ui \
    vagregapasajero.ui \
    vagregaequipaje.ui \
    vagregartren.ui \
    vmuestrapasajero.ui

RESOURCES += \
    Imagenes.qrc

DISTFILES += \
    ../WhatsApp-Image-20160518.jpg
