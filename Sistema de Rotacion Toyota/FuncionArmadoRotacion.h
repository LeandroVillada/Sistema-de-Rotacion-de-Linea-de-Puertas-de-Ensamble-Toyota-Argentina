#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

#include "Empleados.h"
#include "Funciones Disponibilidad.h"
#include "Funciones Globales.h"

void listarLegajosDisponiblesParaRotacion(int *, int);

void listarLegajosCargadosParaRotacion(int *);

void agregarEmpleadosDisponiblesParaRotar(int *, int *);

void mostrarMensajeCargaIngresados(int);

#include "Rotacion.h"

bool validarLegajoRepetido(int *, int);
void cargarBloqueUno(int (*)[26], int *);
void cargarBloqueDos(int (*)[26], int *);
void cargarBloqueTres(int (*)[26], int *);
void cargarBloqueCuatro(int (*)[26], int *);

void mostrarRotacion();
void armarRotacion(int *);
