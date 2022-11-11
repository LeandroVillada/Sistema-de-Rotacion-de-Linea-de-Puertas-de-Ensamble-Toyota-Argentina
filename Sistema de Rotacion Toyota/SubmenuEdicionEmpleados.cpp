#include "SubmenuEdicionEmpleados.h"
#include "Funciones Empleados.h"

void menuEmpleadosEdicion()
{
    // Le damos el nombre que quieramos al objeto
    Menu MenuEdicionEmpleados;
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuEdicionEmpleados.setSalida("Volver al Menu de Principal");
    // Agregamos el Titulo del menu
    MenuEdicionEmpleados.setTitulo("MENU EDICCION DE EMPLEADOS");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuEdicionEmpleados.agregarOpcion("Dar de Baja un Legajo");
    // OPCION 2
    MenuEdicionEmpleados.agregarOpcion("Dar de Alta un Legajo");
    // OPCION 3
    MenuEdicionEmpleados.agregarOpcion("Editar Nombre");
    // OPCION 4
    MenuEdicionEmpleados.agregarOpcion("Editar Apellido");
    // OPCION 5
    MenuEdicionEmpleados.agregarOpcion("Listar Operarios");

    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuEdicionEmpleados.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::BROWN);
        system("cls");
        switch (opciones)
        {
        case 1:
            darBajaLegajo();
            system("pause>nul");

            break;
        case 2:
            darAltaLegajo();
            system("pause>nul");

            break;
        case 3:
            editarNombreEmpleado();
            system("pause>nul");

            break;
        case 4:
            editarApellidoEmpleado();
            system("pause>nul");

            break;
        case 5:
            listarOperarios();
            system("pause>nul");

            break;
        default:
            // VOLVER AL MENU ANTERIOR O SALIR
            return;
            break;
        }
    }
    /*
        int opciones;
        while (true)
        {
            system("color 6");
            system("cls");
            cout << "\t\t\tMENU EDICCION DE EMPLEADOS" << endl;
            cout << "\n\t1. Dar de Baja un Legajo" << endl;
            cout << "\n\t2. Dar de Alta un Legajo" << endl;
            cout << "\n\t3. Editar Nombre" << endl;
            cout << "\n\t4. Editar Apellido" << endl;
            cout << "\n\t5. Listar Operarios" << endl;
            cout << "\n\t0. Volver al Menu de Principal" << endl<<endl;
            cout << "\nSeleccione una opcion :  ";
            cin >> opciones;
            system("cls");
            switch (opciones)
            {
            case 1:
                darBajaLegajo();
                system("pause>nul");

                break;
            case 2:
                darAltaLegajo();
                system("pause>nul");

                break;
            case 3:
                editarNombreEmpleado();
                system("pause>nul");

                break;
            case 4:
                editarApellidoEmpleado();
                system("pause>nul");

                break;
            case 5:
                listarOperarios();
                system("pause>nul");

                break;
            case 0:
                return;
            default:
                cout << "OPCION INGRESADA INCORRECTA.\n";
                system("pause>nul");
                break;
            }
        }
         */
}
