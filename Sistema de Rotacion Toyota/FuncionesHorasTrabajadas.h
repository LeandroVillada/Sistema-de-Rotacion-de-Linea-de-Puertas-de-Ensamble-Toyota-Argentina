#ifndef FUNCIONESHORASTRABAJADAS_H_INCLUDED
#define FUNCIONESHORASTRABAJADAS_H_INCLUDED
#pragma once
#include "HorasTrabajadasArchivo.h"
using namespace std;

void agregarRegistros();
void mostrarRegistros();
void sumaHorasPorLegajo(int legajo);
void promedioGeneral();
void promedioPorLegajo(int legajo);
void promedioPorLegajoYAnio(int legajo, int anio);
void promedioPorLegajoYMes(int legajo, int mes);
void mostrarRegistrosPorLegajo(int legajo);
//void mostrarElMenorHorasLegajo();

#endif // FUNCIONESHORASTRABAJADAS_H_INCLUDED
