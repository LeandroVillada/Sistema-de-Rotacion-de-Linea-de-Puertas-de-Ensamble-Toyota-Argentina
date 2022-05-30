#include "FuncionArmadoRotacion.h"

void listarLegajosDisponiblesParaRotacion(int *legajosDisponibles, int cantidadDisponible)
{
    int y = 0;
    gotoxy(3, 3);
    mostrarMensaje("Operarios Disponibles Para Agregar a Rotacion: ", 15, 9);
    for (int q = 0; q < cantidadDisponible; q++)
    {
        if (legajosDisponibles[q] != 0)
        {
            gotoxy(5, 5 + y);
            cout << legajosDisponibles[q] << endl;
            y++;
        }
    }
}

void listarLegajosCargadosParaRotacion(int *operariosParaRotar)
{
    int y = 0;
    gotoxy(80, 3);
    mostrarMensaje("Operarios Ingresados Para Rotar: ", 15, 9);
    for (int w = 0; w < 26; w++)
    {
        if (operariosParaRotar[w] != 0)
        {
            gotoxy(80, 5 + y);
            cout << operariosParaRotar[w] << endl;
            y++;
        }
    }
}

void agregarEmpleadosDisponiblesParaRotar(int *legajosDisponibles, int *operariosParaRotar)
{
    int cantidadDisponible = contarLegajosActivosDisponibles();
    // legajosDisponibles = new int[cantidadDisponible];
    // if (legajosDisponibles == NULL)
    // {
    //     std::cout << "NO SE PUDO ASIGNAR MEMORIA.\n";
    //     return;
    // }
    asignarLegajosAlVector(legajosDisponibles, cantidadDisponible);

    vectorEnCero(operariosParaRotar, 26);

    int legajoIngresado, posicion;
    bool buscarDisponible;

    while (true)
    {
        /// lista de disponibles para agregar a la rotacion
        listarLegajosDisponiblesParaRotacion(legajosDisponibles, cantidadDisponible);

        /// lista de operarios ingresados para rotar
        listarLegajosCargadosParaRotacion(operariosParaRotar);

        gotoxy(3, 1);
        cout << "ingresar legajo de los disponibles para rotar: ";
        cin >> legajoIngresado;

        /// asignacion de una lista a la otra
        posicion = 0, buscarDisponible = false;

        for (int e = 0; e < cantidadDisponible; e++)
        {
            if (legajosDisponibles[e] == legajoIngresado)
            {
                legajosDisponibles[e] = 0;
                buscarDisponible = true;
            }
        }
        while (buscarDisponible && posicion < 26)
        {
            if (operariosParaRotar[posicion] == 0)
            {
                operariosParaRotar[posicion] = legajoIngresado;
                buscarDisponible = false;
            }
            else
            {
                posicion++;
            }
        }

        system("cls");
        if (operariosParaRotar[25] != 0)
        {
            listarLegajosDisponiblesParaRotacion(legajosDisponibles, cantidadDisponible);
            listarLegajosCargadosParaRotacion(operariosParaRotar);
            break;
        }
    }
    gotoxy(3, 1);
    mostrarMensaje("Todos los Puestos Fueron Cargados.                         ", 15, 2);
    return;
}
