#pragma once
#include "Fecha.h"

class HorasTrabajadas
{
private:
    int _legajo;
    float _horasTrabajadas;
    Fecha fechaHoraTrabajadas;

public:
    // CONSTRUCTORES
    HorasTrabajadas();
    // SETS
    void setLegajo(int);
    void setHorasTrabajadas(float);
    void setFechaHoraTrabajadas(Fecha fechaHoraTrabajadas);
    // GETS
    int getLegajo();
    float getHorasTrabajadas();
    Fecha getFechaHoraTrabajadas();
    int getSize();

    void Mostrar();
};