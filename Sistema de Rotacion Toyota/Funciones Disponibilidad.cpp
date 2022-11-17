#include "Funciones Disponibilidad.h"
#include "EmpleadosArchivo.h"
#include "Fecha.h"

int contarLegajosActivosDisponibles()
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *reg = new Empleados[cantidad];
    if (reg == NULL)
    {
        return -2;
    }
    if (!Archivo.leerTodos(reg, cantidad))
    {
        return -2;
    }

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
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *reg = new Empleados[cantidad];
    if (reg == NULL)
    {
        return;
    }
    if (!Archivo.leerTodos(reg, cantidad))
    {
        return;
    }

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
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *reg = new Empleados[cantidad];
    if (reg == NULL)
    {
        return;
    }
    if (!Archivo.leerTodos(reg, cantidad))
    {
        return;
    }
    // ENCABEZADO
    gotoxy(2, 2);
    cout << "LEGAJO";
    gotoxy(20, 2);
    cout << "APELLIDO";
    gotoxy(50, 2);
    cout << "NOMBRE" << endl;
    cout << "---------------------------------------------------------------" << endl;
    int y = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if ((reg[i].getEstado()) && (reg[i].getDisponibilidad()))
        {
            gotoxy(4, 4 + y);
            cout << reg[i].getLegajo() << endl;
            gotoxy(20, 4 + y);
            cout << reg[i].getApellido() << endl;
            gotoxy(50, 4 + y);
            cout << reg[i].getNombre() << endl;
            y++;
        }
    }
}

void disponible()
{
    Empleados reg;
    EmpleadosArchivo archivo;
    int legajo;
    cout << "Ingresar el Legajo: ";
    cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!archivo.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    if (archivo.LegajoDisponible(legajo))
    {
        mostrarMensaje("El legajo ingresado ya esta disponible.", 15, 2);
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    if (!archivo.leer(reg, pos))
    {
        cout << "No de pudo abrir el archivo Empleados.dat\n";
        return;
    }
    // Cambiamos el valor de la disponibilidad del registro
    reg.setDisponibilidad(true);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    if (!archivo.guardar(reg, pos))
    {
        cout << "No se pudo grabar en Empleados.dat.\n";
        return;
    }
    mostrarMensaje("El legajo se encuentra disponible.", 15, 2);
}

void NOdisponible()
{
    EmpleadosArchivo archivo;
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo: ";
    cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!archivo.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    if (!archivo.LegajoDisponible(legajo))
    {
        mostrarMensaje("El legajo ingresado ya se encuentra no disponible.", 15, 4);
        return;
    }

    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = archivo.buscarPosicionEmpleadoPorLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    if (!archivo.leer(reg, pos))
    {
        cout << "No de pudo abrir el archivo Empleados.dat\n";
        return;
    }
    // Cambiamos el valor de la disponibilidad del registro
    reg.setDisponibilidad(false);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    if (!archivo.guardar(reg, pos))
    {
        cout << "No se pudo grabar en Empleados.dat.\n";
        return;
    }
    mostrarMensaje("El legajo se encuentra no disponible.", 15, 4);
}
