#pragma once

#include <cstdio>
#include <ctime>

void cargarCadenas(char *pal, int tam);

void vectorEnCero(int *, int);

void cargarAleatorio(int *, int, int);

#include <iostream>
#include <windows.h>
#include "rlutil.h"

void gotoxy(short x, short y);

void mostrarMensaje(std::string mensaje, int color, int colorFondo);

void confirmarSalida();

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea = 15, short colorFondo = 11);

void separadorH(short iniX, short iniY, short ancho, short colorLinea = rlutil::WHITE, short colorFondo = rlutil::BLACK);

void separadorV(short iniX, short iniY, short alto, short colorLinea = rlutil::WHITE, short colorFondo = rlutil::BLACK);

bool AjustarVentana(int Ancho, int Alto);