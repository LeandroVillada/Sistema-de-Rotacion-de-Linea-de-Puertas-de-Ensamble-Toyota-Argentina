#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadenas(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = cin.get();
        if (pal[i] == '\n')
        {
            break;
        }
    }
    pal[i] = '\0';
    fflush(stdin);
}
void ponerFalsoVectorBoleano(bool *vec, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = false;
    }
}

void cargarEmpleado()
{
    Empleados reg;
    if (reg.cargar())
    {
        cout << "\nEMPLEADO CARGADO.";
    }
    else
    {
        cout << "\nNO SE PUDO CARGAR EL EMPLEADO.";
    }
}
void cargarEmpleados()
{
    cout << "INGRESAR CANTIDAD DE EMPLEADOS A CARGAR: ";
    int empleados;
    cin >> empleados;

    for (int i = 0; i < empleados; i++)
    {
        Empleados reg;
        if (reg.cargar())
        {
            cout << "\nEMPLEADO CARGADO.";
        }
        else
        {
            cout << "\nNO SE PUDO CARGAR EL EMPLEADO.";
        }
    }
}
void mostrarEmpleados()
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.get_estado())
        {
            reg.mostrar();
            puts("");
        }
    }
}
void mostrarEmpleadoPorLegajo()
{
    Empleados reg;
    cout << "INGRESAR LEGAJO A BUSCAR: ";
    int legajo;
    cin >> legajo;
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    if (reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado esta dado de baja." << endl;
        return;
    }
    int pos = reg.buscarLegajo(legajo);
    reg.leerDeDisco(pos);
    reg.mostrar();
}
void mostrarEmpleadosInactivo()
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (!reg.get_estado())
        {
            reg.mostrar();
            puts("");
        }
    }
}
void crearArchivoEmpleadoNuevo()
{
    Empleados reg;
    reg.crearArchivo();
    cout << "ARCHIVO CREADO.";
}

#endif // FUNCIONES_H_INCLUDED
