#include "EmpleadosArchivo.h"
#include "Fecha.h"
#include "Licencias.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// CONSTRUCTORES
Licencias::Licencias()
{
    _legajo = 0;
}

// SETTS
void Licencias::setLegajo(int legajo) { _legajo = legajo; }

void Licencias::setFechaInicioLicencia(Fecha fechaIn){ fechaInicioLicencia=fechaIn; }

void Licencias::setFechaFinLicencia(Fecha fechaFn){ fechaFinLicencia=fechaFn; }

// GETTS
int Licencias::getLegajo() { return _legajo; }

Fecha Licencias::getFechaInicioLicencia(){return fechaInicioLicencia; }

Fecha Licencias::getFechaFinLicencia(){return fechaFinLicencia; }

int Licencias::getSize()
{
    return sizeof * this;
}

void Licencias::Mostrar()
{
    cout << "Legajo: ";
    cout << _legajo << endl;
    cout << "Fecha inicio licencia: "<<endl;
    cout << fechaInicioLicencia << endl;
    cout << "Fecha fin licencia: "<<endl;
    cout << fechaFinLicencia << endl;
    cout << endl;
}
