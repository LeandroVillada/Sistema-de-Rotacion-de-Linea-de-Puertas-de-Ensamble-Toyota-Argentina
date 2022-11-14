#include "Rotacion.h"
#include <cstdio>

// SETTS
void Rotacion::setOperarios(int *operarios)
{
    for (int i = 0; i < 26; i++)
    {
        operarios[i] = operarios[i];
    }
}
void Rotacion::setBloqueUno(int *Bloque)
{
    for (int i = 0; i < 26; i++)
    {
        _bloqueUno[i] = Bloque[i];
    }
}
void Rotacion::setBloqueDos(int *Bloque)
{
    for (int i = 0; i < 26; i++)
    {
        _bloqueDos[i] = Bloque[i];
    }
}
void Rotacion::setBloqueTres(int *Bloque)
{
    for (int i = 0; i < 26; i++)
    {
        _bloqueTres[i] = Bloque[i];
    }
}
void Rotacion::setBloqueCuatro(int *Bloque)
{
    for (int i = 0; i < 26; i++)
    {
        _bloqueCuatro[i] = Bloque[i];
    }
}
// GETTS
int *Rotacion::getOperarios() { return _operarios; }
int *Rotacion::getBloqueUno() { return _bloqueUno; }
int *Rotacion::getBloqueDos() { return _bloqueDos; }
int *Rotacion::getBloqueTres() { return _bloqueTres; }
int *Rotacion::getBloqueCuatro() { return _bloqueCuatro; }

int Rotacion::getSize()
{
    return sizeof *this;
}
