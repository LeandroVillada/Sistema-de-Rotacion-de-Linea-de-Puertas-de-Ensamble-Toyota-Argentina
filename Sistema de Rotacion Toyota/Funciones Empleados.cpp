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

void cargarDatosDeInicio()
{
    // BORRA TODOS LOS DATOS CARGADOS ANTERIORMENTE
    FILE *p;
    p = fopen("Empleados.dat", "wb");
    fclose(p);

    Empleados reg;
    for (int i = 1; i <= 40; i++)
    {
        reg.setLegajo(i);
        if (i == 10 || i == 20 || i == 30 || i == 40)
        {
            reg.setDisponibilidad(false);
        }
        else
        {
            reg.setDisponibilidad(true);
        }
        if (i == 25)
        {
            reg.setEstado(false);
        }
        else
        {
            reg.setEstado(true);
        }
        reg.grabarEnDisco();
    }
    std::cout<<"DATOS DE PRUEBA CARGADO.\n";
}