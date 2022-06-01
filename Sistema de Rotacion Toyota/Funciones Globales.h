#pragma once

#include <cstdio>
#include <ctime>

void cargarCadenas(char *pal, int tam);

void vectorEnCero(int *, int);

int cargarAleatorio(int);

#include <iostream>
#include <windows.h>
#include "rlutil.h"

void gotoxy(short, short);

void mostrarMensaje(std::string, int, int);

void confirmarSalida();

void recuadro(short, short, short, short, short, short);

void separadorH(short, short, short, short, short, short);

void separadorV(short, short, short, short, short, short);

bool AjustarVentana(int, int);
