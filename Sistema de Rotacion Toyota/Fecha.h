#pragma once
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
    bool esbisiesto(int);
    void NumeroSerieaFecha(int);
    void FechaHora(int);

public:
    Fecha();
    Fecha(int, int, int);
    // Sets
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    // void setHora(int);
    //  Gets
    int getDia();
    int getMes();
    int getAnio();
    std::string toString();
    std::string toStringMes(int mes);
    //  OPERADOR
    void operator=(Fecha);
    bool operator==(Fecha);
    bool operator!=(Fecha);
    bool operator>(Fecha);
    bool operator>=(Fecha);
    bool operator<(Fecha);
    bool operator<=(Fecha);
    Fecha operator+(int);
    int operator-(Fecha &);
    void operator+=(int);
    int operator==(const char *);
    friend istream &operator>>(istream &, Fecha &);
    friend ostream &operator<<(ostream &, Fecha &);
    // FUNCIONES
    int cantDiasMes();
    int cantDiasHabilesMes();
    int cantAniosHastaHoy();
    int NumeroSerie();
    void MostrarFecha();
    void MostrarFechaTexto();
    bool validarFecha();
};
