#include "Funciones Empleados.h"
#include "Cadena.h"
void cargarNuevo()
{
    system("cls");
    EmpleadosArchivo archivo;
    Empleados reg;
    int legajo;
    Cadena nombre{""};
    Cadena apellido{""};
    cout << "--------Ingreso de Operario Nuevo--------" << endl;
    cout << "Ingrese Legajo de Operario Nuevo: ";
    cin >> legajo;
    if (archivo.buscarLegajoExistente(legajo))
    {
        cout << "Ese legajo ya existe." << endl;
        system("pause>nul");
        system("cls");
        cargarNuevo();
        return;
    }
    if (legajo < 1)
    {
        cout << "El legajo debe ser mayor a 0." << endl;
        system("pause>nul");
        system("cls");
        cargarNuevo();
        return;
    }
    reg.setLegajo(legajo);

    cout << "Ingrese Nombre de Operario Nuevo: ";
    cin >> nombre;
    reg.setNombre(nombre.getP());
    cout << "Ingrese Apellido de operario Nuevo: ";
    cin >> apellido;

    reg.setApellido(apellido.getP());
    if (archivo.guardar(reg))
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
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *reg = new Empleados[cantidad];
    Archivo.leerTodos(reg, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "LEGAJO: " << reg[i].getLegajo() << std::endl;
        std::cout << "NOMBRE: " << reg[i].getNombre() << std::endl;
        std::cout << "APELLIDO: " << reg[i].getApellido() << std::endl;
        std::cout << "DISPONIBILIDAD: " << reg[i].getDisponibilidad() << std::endl;
        std::cout << "ESTADO: " << reg[i].getEstado() << std::endl;
        puts("");
        // cout << reg[i].toString() << endl;
    }
}

void cargarDatosDeInicio()
{
    // BORRA TODOS LOS DATOS CARGADOS ANTERIORMENTE
    FILE *p;
    p = fopen("Empleados.dat", "wb");
    fclose(p);

    Empleados reg;
    EmpleadosArchivo archivo;
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
        archivo.guardar(reg);
    }
    std::cout << "DATOS DE PRUEBA CARGADO.\n";
}