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
void cargarHabilidadesEmpleado()
{
    Empleados reg;
    int legajo;
    cout << "INGRESAR EL LEGAJO DEL EMPLEADO: ";
    cin >> legajo;
    int pos = reg.buscarLegajo(legajo);
    cout << "INGRESAR EL NUMERO DEL PUESTO QUE SABE REALIZAR (1 a 26)." << endl;
    int puesto;
    bool habilidades[HABILIDADES];
    cout << "PUESTO: ";
    cin >> puesto;
    while (puesto > 0 && puesto < 27)
    {
        if (puesto % 2 == 0)
        {
            habilidades[puesto / 2 - 1] = true;
        }
        else
        {
            habilidades[(puesto + 1) / 2 - 1] = true;
        }
        cout << "PUESTO: ";
        cin >> puesto;
    }
    reg.leerDeDisco(pos);
    reg.set_habilidades(habilidades);
    reg.modificarEnDisco(pos);
    cout << "HABILIDADES DEL EMPLEADO CARGADAS.";
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
