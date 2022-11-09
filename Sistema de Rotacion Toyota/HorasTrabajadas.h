#ifndef HORASTRABAJADAS_H_INCLUDED
#define HORASTRABAJADAS_H_INCLUDED
#include "Fecha.h"
class HorasTrabajadas{
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

    void Mostrar();

    // FUNCIONES PUBLICAS
    /*
    void Cargar();


    void sumaHorasPorLegajo(int);

    bool grabarEnDisco();

    bool leerDeDisco(int);

    int getCantidad();

    //void MostrarHoras(float);

    void agregarRegistros();

    void mostrarRegistros();

    void PromedioGeneral();

    void PromedioPorLegajo(int);

    void PromedioPorLegajoYAnio(int,int);

    void PromedioPorLegajoYMes(int,int);

    void mostrarRegistrosPorLegajo(int);
    */
};


#endif // HORASTRABAJADAS_H_INCLUDED
