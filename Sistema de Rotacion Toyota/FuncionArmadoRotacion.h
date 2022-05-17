#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;
#include <windows.h>
#include "rlutil.h"


void gotoxy(short x, short y);

void ponercero(int v[], int tam);
void mostrarMensaje(string mensaje, int color, int colorFondo);

void confirmarSalida();

int agregarEmpleadosDisponiblesParaRotar();
