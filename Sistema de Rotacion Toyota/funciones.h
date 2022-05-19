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

void ponercero(int v[], int tam){
int i;
for(i=0;i<(tam-1);i++){
v[i]=0;
}
}

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

/*void cargarEmpleado()
{
    Empleados reg;
    if (reg.cargar())
        cout << "\nEMPLEADO CARGADO.";
    else
        cout << "\nNO SE PUDO CARGAR EL EMPLEADO.";
}*/

/*void mostrarEmpleados()
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
}*/

/*void mostrarEmpleadosInactivo()
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
         if (!reg.getEstado())
         {
            reg.mostrar();
            puts("");
         }
    }
}*/

/*void crearArchivoEmpleadoNuevo()
{
    Empleados reg;
    reg.crearArchivo();
    cout << "ARCHIVO CREADO.";
}*/



#endif // FUNCIONES_H_INCLUDED
