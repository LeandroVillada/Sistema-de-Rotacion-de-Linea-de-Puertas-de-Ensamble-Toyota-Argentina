#include "Funciones Disponibilidad.h"

int contarLegajosActivosDisponibles()
{
    Empleados reg;
    int pos = 0, contador = 0;
    while (reg.leerDeDisco(pos++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            contador++;
        }
    }
    return contador;
}
void asignarLegajosAlVector(int *vector, int tam)
{
    Empleados reg;
    int pos = 0, contador = 0;
    while (reg.leerDeDisco(pos++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            vector[contador] = reg.getLegajo();
            contador++;
        }
    }
}

void listarOperariosDisponiblesParaRotar()
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            std::cout << reg.getLegajo() << std::endl;
        }
    }
}
