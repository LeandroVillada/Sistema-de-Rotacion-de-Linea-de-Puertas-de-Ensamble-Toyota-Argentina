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

void disponible(){
    Empleados reg;
    int legajo;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (reg.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ingresado ya se encuentra disponible." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(true);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    std::cout << "Legajo se encuentra con disponibilidad." << std::endl;

}

void NOdisponible(){
    Empleados reg;
    int legajo;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (!reg.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ingresado ya se encuentra no disponible." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(false);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    std::cout << "Legajo se encuentra sin disponibilidad." << std::endl;

}
