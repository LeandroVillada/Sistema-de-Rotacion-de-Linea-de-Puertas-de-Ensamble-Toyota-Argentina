#pragma once
#include <iostream>
#include "Fecha.h"
class Licencias: public Empleados{
private:
    Fecha fechaInicioLicencia;
    Fecha fechaFinLicencia;
public:
    //setts
    void setFechaInicioLicencia(Fecha fil) {fechaInicioLicencia=fil;}
    void setFechaFinLicencia(Fecha ffl) {fechaFinLicencia=ffl;}
    //getts
    Fecha getFechaInicioLicencia(){return fechaInicioLicencia;}
    Fecha getFechaFinLicencia(){return fechaFinLicencia;}

    //Funciones Archivos
    bool leerDeDisco(int);
    bool grabarEnDisco();
    bool modificarEnDisco(int);

    void licencia();
};


