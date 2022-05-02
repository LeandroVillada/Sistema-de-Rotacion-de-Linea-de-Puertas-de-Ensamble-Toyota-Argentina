#pragma once

#include < string>
class Rotacion
{
private:
    int _legajo;
    int _rotacion[26][4];

public:
    // FUNCIONES ARCHIVOS
    bool leerDeDisco(int);
    bool grabarEnDisco();
    bool modificarEnDisco(int);
    int cantidadRegistros();
    bool grabarEnBackUp();
    bool restaurarBackUP();
    bool exportar();
    // SETTS
    void setLegajo(int);
    void setRotacion(int*);
    // GETTS
    int getLegajo();
    int **getRotacion();
};
