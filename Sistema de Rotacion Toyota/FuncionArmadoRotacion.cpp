#include "FuncionArmadoRotacion.h"

void listarLegajosDisponiblesParaRotacion(int *legajosDisponibles, int cantidadDisponible)
{
    Empleados emp;
    int y = 0;
    gotoxy(3, 3);
    mostrarMensaje("Operarios Disponibles Para Agregar a Rotacion: ", 15, 9);
    for (int q = 0; q < cantidadDisponible; q++)
    {
        if (legajosDisponibles[q] != 0)
        {
            gotoxy(10, 5 + y);
            cout<<emp.buscarEmpleadoPorLegajo(legajosDisponibles[q]).getApellido();
            gotoxy(35, 5 + y);
            cout << legajosDisponibles[q] << endl;
            y++;
        }
    }
}

void listarLegajosCargadosParaRotacion(int *operariosParaRotar)
{
    Empleados emp;
    int y = 0;
    gotoxy(80, 3);
    mostrarMensaje("Operarios Ingresados Para Rotar: ", 15, 9);
    for (int w = 0; w < 26; w++)
    {
        if (operariosParaRotar[w] != 0)
        {
            gotoxy(85, 5 + y);
            cout<<emp.buscarEmpleadoPorLegajo(operariosParaRotar[w]).getApellido();
            gotoxy(105, 5 + y);
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

    do
    {
        /// lista de disponibles para agregar a la rotacion
        listarLegajosDisponiblesParaRotacion(legajosDisponibles, cantidadDisponible);

        /// lista de operarios ingresados para rotar
        listarLegajosCargadosParaRotacion(operariosParaRotar);

        gotoxy(3, 1);
        mostrarMensaje("Ingresar legajo de los disponibles para rotar: ", 15, 6);
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
    }while (true && legajoIngresado!=0);

    mostrarMensajeCargaIngresados(legajoIngresado);

    return;
}

void mostrarMensajeCargaIngresados(int legajo){
        if (legajo!=0){
        system("cls");
        gotoxy(35, 5);
        mostrarMensaje("Todos los Puestos Fueron Cargados.", 15, 2);
    }
    else{
        ///Si legajo ==0 cancela la carga y muestro mensaje
        system("cls");
        gotoxy(50, 5);
        mostrarMensaje("Se cancelo la carga!", 15, 4);
    }
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

void cargarBloqueDos(int rotacion[][26], int *operariosParaRotar)
{

    int posicionGenerada;
    srand(120);
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
    srand(300);
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
    srand(450);
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

void encabezado(){

    cout<<endl;
    cout <<" PUESTO"<<"\t"<<"\t";
    cout <<"LEGAJO"<<"\t"<<"\t";
    cout <<"APELLIDO             NOMBRE"<<endl;
    cout <<"---------------------------------------------------------------"<<endl;
}

void mostrarRotacionUno()
{
    Empleados aux;
    Rotacion reg;
    reg.leerDeDisco(0);
    int y=0;

    for (int i = 0; i < 26; i++)
    {
        gotoxy(4, 4 + y);
        cout <<i + 1;
        gotoxy(19, 4 + y);
        cout << reg.getBloqueUno()[i];
        gotoxy(33, 4 + y);
        cout <<aux.buscarEmpleadoPorLegajo(reg.getBloqueUno()[i]).getApellido();
        gotoxy(54, 4 + y);
        cout <<aux.buscarEmpleadoPorLegajo(reg.getBloqueUno()[i]).getNombre()<<endl;
        y++;
    }
    cout <<"---------------------------------------------------------------"<<endl;
}

void mostrarRotacionDos()
{
    Empleados aux;
    Rotacion reg;
    reg.leerDeDisco(0);
    int y=0;

    for (int i = 0; i < 26; i++)
    {
        gotoxy(4, 34 + y);
        cout <<i + 1;
        gotoxy(19, 34 + y);
        cout << reg.getBloqueDos()[i];
        gotoxy(33, 34 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueDos()[i]).getApellido();
        gotoxy(54, 34 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueDos()[i]).getNombre()<<endl;
        y++;
    }
    cout <<"---------------------------------------------------------------"<<endl;
}

void mostrarRotacionTres()
{
    Empleados aux;
    Rotacion reg;
    reg.leerDeDisco(0);
    int y=0;

    for (int i = 0; i < 26; i++)
    {
        gotoxy(4, 64 + y);
        cout <<i + 1;
        gotoxy(19, 64 + y);
        cout << reg.getBloqueTres()[i];
        gotoxy(33, 64 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueTres()[i]).getApellido();
        gotoxy(54, 64 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueTres()[i]).getNombre()<<endl;
        y++;
    }
    cout <<"---------------------------------------------------------------"<<endl;
}

void mostrarRotacionCuatro()
{
    Empleados aux;
    Rotacion reg;
    reg.leerDeDisco(0);
    int y=0;

    for (int i = 0; i < 26; i++)
    {
        gotoxy(4, 94 + y);
        cout << i + 1;
        gotoxy(19, 94 + y);
        cout << reg.getBloqueCuatro()[i];
        gotoxy(33, 94 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueCuatro()[i]).getApellido();
        gotoxy(54, 94 + y);
        cout << aux.buscarEmpleadoPorLegajo(reg.getBloqueCuatro()[i]).getNombre()<<endl;
        y++;
    }
    cout <<"---------------------------------------------------------------"<<endl;
}

void mostrarRotacion()
{
   Rotacion reg;
    reg.leerDeDisco(0);
    Empleados aux;

    ///Bloque 1
    gotoxy(50, 1);
    mostrarMensaje("Bloque 1", 15, 9);
    gotoxy(0, 2);
    encabezado();
    mostrarRotacionUno();

    ///Bloque 2
    gotoxy(50, 31);
    mostrarMensaje("Bloque 2", 15, 9);
    gotoxy(0, 36);
    encabezado();
    mostrarRotacionDos();

    ///Bloque 3
    gotoxy(50, 61);
    mostrarMensaje("Bloque 3", 15, 9);
    gotoxy(0, 65);
    encabezado();
    mostrarRotacionTres();

    ///Bloque 4
    gotoxy(50, 91);
    mostrarMensaje("Bloque 4", 15, 9);
    gotoxy(0, 96);
    encabezado();
    mostrarRotacionCuatro();
}

void armarRotacion(int *operariosParaRotar)
{
    mostrarMensaje("Generando una nueva rotacion, porfavor espere...\n", 15, 10);
    int rotacion[4][26] = {0};
    cargarBloqueUno(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 1 GENERADA\n", 15, 9);
    Sleep(2000);
    cargarBloqueDos(rotacion, operariosParaRotar);
    mostrarMensaje("BLOQUE 2 GENERADA\n", 15, 9);
    Sleep(3000);
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
