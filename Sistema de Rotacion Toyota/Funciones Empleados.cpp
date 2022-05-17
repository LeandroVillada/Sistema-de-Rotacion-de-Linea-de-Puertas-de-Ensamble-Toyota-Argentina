#include "Funciones Empleados.h"
void cargarNuevo()
{
    system("cls");
    Empleados reg;
    int legajo;
    std::string nombre;
    std::string apellido;
    cout << "--------Ingreso de Operario Nuevo--------" << endl;
    cout << "Ingrese Legajo de Operario Nuevo: ";
    cin >> legajo;
    if (reg.buscarLegajoExistente(legajo))
    {
        cout << "Ese legajo ya existe." << endl;
        system("pause>nul");
        return;
    }
    reg.setLegajo(legajo);
    cout << "Ingrese Nombre de Operario Nuevo: ";
    cin >> nombre;
    reg.setNombre(nombre);
    cout << "Ingrese Apellido de operario Nuevo: ";
    cin >> apellido;
    reg.setApellido(apellido);
    if (reg.grabarEnDisco())
    {
        cout << "Se Agrego Operarios Nuevo" << endl;
    }
    else
    {
        cout << "No se pudo agregar Operario" << endl;
    }
    system("pause>nul");
}

void listarOperarios()
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getEstado())
        {
            std::cout << "LEGAJO: " << reg.getLegajo() << std::endl;
            std::cout << "NOMBRE: " << reg.getNombre() << std::endl;
            std::cout << "APELLIDO: " << reg.getApellido() << std::endl;
            std::cout << "DISPONIBILIDAD: " << reg.getDisponibilidad() << std::endl;
            std::cout << "ESTADO: " << reg.getEstado() << std::endl;
            puts("");
        }
    }
}