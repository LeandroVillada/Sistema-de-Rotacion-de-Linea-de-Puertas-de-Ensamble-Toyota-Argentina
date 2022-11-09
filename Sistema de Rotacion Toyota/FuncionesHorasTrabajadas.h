#ifndef FUNCIONESHORASTRABAJADAS_H_INCLUDED
#define FUNCIONESHORASTRABAJADAS_H_INCLUDED
#pragma once
#include "HorasTrabajadasArchivo.h"
using namespace std;

void sumaHorasPorLegajo(int legajo);
//void MostrarHoras(float cant);
void agregarRegistros();
void mostrarRegistros();
void promedioGeneral();
void promedioPorLegajo(int legajo);
void promedioPorLegajoYAnio(int legajo, int anio);
void promedioPorLegajoYMes(int legajo, int mes);
void mostrarRegistrosPorLegajo(int legajo);

#endif // FUNCIONESHORASTRABAJADAS_H_INCLUDED
