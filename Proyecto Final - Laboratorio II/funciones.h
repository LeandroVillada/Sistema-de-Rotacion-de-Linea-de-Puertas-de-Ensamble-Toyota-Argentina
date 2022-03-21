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
            break;
    }
    pal[i] = '\0';
    fflush(stdin);
}

void cargarEmpleado()
{
    Empleados reg;
    if (reg.cargar())
        cout << "\nEMPLEADO CARGADO.";
    else
        cout << "\nNO SE PUDO CARGAR EL EMPLEADO.";
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
void crearArchivoEmpleadoNuevo()
{
    Empleados reg;
    reg.crearArchivo();
    cout << "ARCHIVO CREADO.";
}

#endif // FUNCIONES_H_INCLUDED
