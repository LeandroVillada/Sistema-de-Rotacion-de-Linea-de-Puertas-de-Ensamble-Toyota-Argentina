#include "HorasTrabajadas.h"
#include "EmpleadosArchivo.h"
#include "HorasTrabajadasArchivo.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// CONSTRUCTORES
HorasTrabajadas::HorasTrabajadas()
{
    _legajo = 0;
    _horasTrabajadas = 0;
}

// SETTS
void HorasTrabajadas::setLegajo(int legajo) { _legajo = legajo; }

void HorasTrabajadas::setHorasTrabajadas(float horas) { _horasTrabajadas = horas; }

void HorasTrabajadas::setFechaHoraTrabajadas(Fecha fecha){ fechaHoraTrabajadas=fecha; }

// GETTS
int HorasTrabajadas::getLegajo() { return _legajo; }

float HorasTrabajadas::getHorasTrabajadas() { return _horasTrabajadas; }

Fecha HorasTrabajadas::getFechaHoraTrabajadas(){return fechaHoraTrabajadas; }
int HorasTrabajadas::getSize()
{
    return sizeof * this;
}

void HorasTrabajadas::Mostrar()
{
    cout << "Legajo: ";
    cout << _legajo << endl;
    cout << fechaHoraTrabajadas;
    cout << "Horas Trabajadas: ";
    cout << _horasTrabajadas << endl
    << endl;
}
