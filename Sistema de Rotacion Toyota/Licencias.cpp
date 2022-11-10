#include "EmpleadosArchivo.h"
#include "Fecha.h"
#include "Licencias.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// CONSTRUCTORES
Licencias::Licencia()
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

/*

void licencia(){
    EmpleadosArchivo archivo;
    Licencias lic;
    Fecha(9,7,22);
    int legajo, desde, hasta, mesD, mesH;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    if (archivo.buscarLegajoExistente(legajo)==false)
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (archivo.LegajoDisponible(legajo)==false)
    {
        std::cout << "El legajo ingresado ya se encuentra con licencia." << std::endl;
        return;
    }
    std::cout << "Ingresar Fecha Desde: ";
    std::cin >> desde;
    /*std::cout << "Ingresar Fecha Hasta: ";
    std::cin >> hasta;
    std::cout << "Ingresar Fecha Mes desde: ";
    std::cin >> mesD;
    /*std::cout << "Ingresar Fecha Mes hasta: ";
    std::cin >> mesH;

    ///NO ANDA ESTA PARTE POR EL MOMENTO//////////////////////////////////////////////

    if(lic.getFechaInicioLicencia().getDia()==desde && lic.getFechaInicioLicencia().getMes()==mesD){
        int pos = archivo.buscarPosicionLegajo(legajo);
        lic.leerDeDisco(pos);
        lic.setDisponibilidad(false);
        lic.modificarEnDisco(pos);
    }

}
*/
