#include "Funciones Disponibilidad.h"
#include "EmpleadosArchivo.h"
#include "Fecha.h"

int contarLegajosActivosDisponibles()
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidad();
    Empleados* reg = new Empleados[cantidad];
    Archivo.leerTodos(reg, cantidad);

    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if ((reg[i].getEstado()) && (reg[i].getDisponibilidad()))
        {
            contador++;
        }
    }
    return contador;
}
void asignarLegajosAlVector(int *vector, int tam)
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidad();
    Empleados* reg = new Empleados[cantidad];
    Archivo.leerTodos(reg, cantidad);

    int contador = 0;
        for (int i = 0; i < cantidad; i++)
    {
        if ((reg[i].getEstado()) && (reg[i].getDisponibilidad()))
        {
            vector[contador] = reg[i].getLegajo();
            contador++;
        }
    }
}

void listarOperariosDisponiblesParaRotar()
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidad();
    Empleados* reg = new Empleados[cantidad];
    Archivo.leerTodos(reg, cantidad);


    for (int i = 0; i < cantidad; i++)
    {
        if ((reg[i].getEstado()) && (reg[i].getDisponibilidad()))
        {
            std::cout << reg[i].getLegajo() << std::endl;
        }
    }
}

void disponible(){
    Empleados reg;
    EmpleadosArchivo archivo;
    int legajo;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!archivo.buscarLegajoExistente(legajo))
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (archivo.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ingresado ya se encuentra disponible." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    archivo.leer(reg, pos);
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(true);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    archivo.guardar(reg, pos);
    std::cout << "Legajo se encuentra con disponibilidad." << std::endl;

}

void NOdisponible(){
    EmpleadosArchivo archivo;
    Empleados reg;
    int legajo;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!archivo.buscarLegajoExistente(legajo))
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (!archivo.LegajoDisponible(legajo))
    {
        std::cout << "El legajo ingresado ya se encuentra no disponible." << std::endl;
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    archivo.leer(reg, pos);
    // Cambiamos el valor del estado del registro
    reg.setDisponibilidad(false);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    archivo.guardar(reg, pos);
    std::cout << "Legajo se encuentra sin disponibilidad." << std::endl;

}
