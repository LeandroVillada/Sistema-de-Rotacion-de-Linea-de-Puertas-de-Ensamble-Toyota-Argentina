#pragma once
#include <ctime>

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
    int _dia_maximo;
    bool _fecha_correcta;

public:
    Fecha();
    Fecha(int, int, int);
    // Sets
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    // Gets
    int getDia();
    int getMes();
    int getAnio();
    // OPERADOR
    void operator=(Fecha);
    bool operator==(Fecha);
    bool operator!=(Fecha);
    bool operator>(Fecha);
    bool operator<(Fecha);
    // FUNCIONES
    bool Cargar();
    void Mostrar();
};
