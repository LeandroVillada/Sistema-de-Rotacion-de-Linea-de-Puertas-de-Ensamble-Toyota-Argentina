#include "Funciones Globales.h"
#include <cstdio>
#include <iostream>

void cargarCadenas(char* pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = std::cin.get();
        if (pal[i] == '\n') { break; }
    }
    pal[i] = '\0';
    fflush(stdin);
}