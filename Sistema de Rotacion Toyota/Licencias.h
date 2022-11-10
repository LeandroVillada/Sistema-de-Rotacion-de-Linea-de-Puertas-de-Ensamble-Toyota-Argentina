#pragma once
#include <iostream>
#include "Fecha.h"
class Licencias{
private:
    int _legajo;
    Fecha fechaInicioLicencia;
    Fecha fechaFinLicencia;
public:
    // CONSTRUCTORES
    Licencia();
    //setts
    void setLegajo(int);
    void setFechaInicioLicencia(Fecha fechaInicioLicencia);
    void setFechaFinLicencia(Fecha fechaFinLicencia);
    //getts
    int getLegajo();
    Fecha getFechaInicioLicencia();
    Fecha getFechaFinLicencia();

    void Mostrar();
};


