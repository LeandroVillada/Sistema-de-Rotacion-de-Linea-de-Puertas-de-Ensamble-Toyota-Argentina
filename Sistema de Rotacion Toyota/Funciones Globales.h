#pragma once

#include <cstdio>

void cargarCadenas(char *pal, int tam);

void vectorEnCero(int *, int);

#include <iostream>
#include <windows.h>
#include "rlutil.h"

void gotoxy(short x, short y);

void mostrarMensaje(std::string mensaje, int color, int colorFondo);

void confirmarSalida();
