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
int *cargarOperariosDisponibles()
{
    Empleados reg;
    int *disponibles;
    disponibles = new int[contarLegajosActivosDisponibles()];
    if (disponibles == NULL)
    {
        std::cout << "NO SE PUDO ASIGNAR MEMORIA.\n";
        return NULL;
    }
    asignarLegajosAlVector(disponibles, contarLegajosActivosDisponibles());
    std::cout << "VECTOR CARGADO.\n";
    return disponibles;
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
