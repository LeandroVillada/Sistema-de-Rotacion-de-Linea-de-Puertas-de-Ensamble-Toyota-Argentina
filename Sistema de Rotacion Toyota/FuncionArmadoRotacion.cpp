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

bool validarLegajoRepetido(int *rotacion, int legajo)
{
    for (int i = 0; i < 26; i++)
    {
        if (rotacion[i] == legajo)
        {
            return true;
        }
    }
    return false;
}

void cargarBloqueUno(int rotacion[][26], int *operariosParaRotar)
{
    int posicionGenerada;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarAleatorio(26);
        while (validarLegajoRepetido(rotacion[0], operariosParaRotar[posicionGenerada]))
        {
            posicionGenerada = cargarAleatorio(26);
        }

        rotacion[0][i] = operariosParaRotar[posicionGenerada];
    }
}

bool validarOperacionEspejosRepetidas(int *rotacion, int Legajo, int posicionFor)
{
    if (posicionFor % 2 == 0)
    {
        if ((rotacion[posicionFor] == Legajo) || (rotacion[posicionFor + 1] == Legajo))
        {
            return true;
        }
    }
    else
    {
        if ((rotacion[posicionFor] == Legajo) || (rotacion[posicionFor - 1] == Legajo))
        {
            return true;
        }
    }
    return false;
}

void cargarBloqueDos(int rotacion[][26], int *operariosParaRotar)
{

    int posicionGenerada;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarAleatorio(26);
        while (validarLegajoRepetido(rotacion[1], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i))
        {
            posicionGenerada = cargarAleatorio(26);
        }

        rotacion[1][i] = operariosParaRotar[posicionGenerada];
    }
}

void cargarBloqueTres(int rotacion[][26], int *operariosParaRotar)
{

    int posicionGenerada;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarAleatorio(26);
        while (validarLegajoRepetido(rotacion[2], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[1], operariosParaRotar[posicionGenerada], i))
        {
            posicionGenerada = cargarAleatorio(26);
        }
        rotacion[2][i] = operariosParaRotar[posicionGenerada];
    }
}

void cargarBloqueCuatro(int rotacion[][26], int *operariosParaRotar)
{

    int posicionGenerada;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarAleatorio(26);
        while (validarLegajoRepetido(rotacion[3], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[1], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[2], operariosParaRotar[posicionGenerada], i))
        {
            posicionGenerada = cargarAleatorio(26);
        }

        rotacion[3][i] = operariosParaRotar[posicionGenerada];
    }
}

void mostrarRotacionUno()
{
    Empleados aux;
    Rotacion reg;
    reg.leerDeDisco(0);
    int y = 0;
    for (int i = 0; i < 26; i++)
    {
        gotoxy(5, 5 + y);
        // cout << "PUESTO: " << i + 1 << "\t LEGAJO: " << reg.getBloqueUno()[i];
        cout << i + 1 << "\t" << reg.getBloqueUno()[i] << "\t";
        cout <<  "\t" << aux.buscarEmpleadoPorLegajo(reg.getBloqueUno()[i]).getNombre();
        cout <<  "\t" << aux.buscarEmpleadoPorLegajo(reg.getBloqueUno()[i]).getApellido();
        y++;
    }
}

void mostrarRotacion()
{
    Rotacion reg;
    reg.leerDeDisco(0);
    Empleados aux;

    int y = 0;
    gotoxy(3, 3);
    mostrarMensaje("Bloque 1: ", 15, 9);
    mostrarRotacionUno();
    // for (int i = 0; i < 26; i++)
    // {
    //     gotoxy(5, 5 + y);
    //     // cout << "PUESTO: " << i + 1 << "\t LEGAJO: " << reg.getBloqueUno()[i];
    //     cout << i + 1 << "\t" << reg.getBloqueUno()[i] << "\t";
    //     cout << aux.buscarApellidoPorLegajo(reg.getBloqueUno()[i]);
    //     cout << "\t" << aux.buscarNombrePorLegajo(reg.getBloqueUno()[i]);
    //     y++;
    // }
    system("pause");
    y = 0;
    gotoxy(33, 3);
    mostrarMensaje("Bloque 2: ", 15, 9);
    for (int i = 0; i < 26; i++)
    {
        gotoxy(35, 5 + y);
        cout << "PUESTO: " << i + 1;
        gotoxy(35 + 13, 5 + y);
        cout << "LEGAJO: " << reg.getBloqueDos()[i];
        y++;
    }
    y = 0;
    gotoxy(62, 3);
    mostrarMensaje("Bloque 3: ", 15, 9);
    for (int i = 0; i < 26; i++)
    {
        gotoxy(64, 5 + y);
        cout << "PUESTO: " << i + 1;
        gotoxy(69 + 8, 5 + y);
        cout << "LEGAJO: " << reg.getBloqueTres()[i];
        y++;
    }
    y = 0;
    gotoxy(91, 3);
    mostrarMensaje("Bloque 4: ", 15, 9);
    for (int i = 0; i < 26; i++)
    {
        gotoxy(94, 5 + y);
        cout << "PUESTO: " << i + 1;
        gotoxy(94 + 13, 5 + y);
        cout << "LEGAJO: " << reg.getBloqueCuatro()[i];
        y++;
    }
}

void armarRotacion(int *operariosParaRotar)
{
    mostrarMensaje("Generando una nueva rotacion, porfavor espere...\n", 15, 10);
    int rotacion[4][26] = {0};
    cargarBloqueUno(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 1 GENERADA\n", 15, 9);
    Sleep(4000);
    cargarBloqueDos(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 2 GENERADA\n", 15, 9);
    Sleep(4000);
    cargarBloqueTres(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 3 GENERADA\n", 15, 9);
    Sleep(4000);
    cargarBloqueCuatro(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 4 GENERADA\n", 15, 9);

    system("pause");
    system("cls");
    Rotacion reg;
    reg.setOperarios(operariosParaRotar);
    reg.setBloqueUno(rotacion[0]);
    reg.setBloqueDos(rotacion[1]);
    reg.setBloqueTres(rotacion[2]);
    reg.setBloqueCuatro(rotacion[3]);
    reg.grabarEnDisco();
    reg.grabarEnBackUp();

    mostrarRotacion();
}
