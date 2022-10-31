#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Hora {
public:
    Hora();
    void estableceHora(int, int, int);  // establece hora, minuto, segundo
    void imprimeMilitar();              // imprime la hora en formato militar
    void imprimeEstandar();             // imprime la hora en formato estandar
private:
    int hora;       // 0 - 23
    int minuto;     // 0 - 59
    int segundo;    // 0 - 59
};
