#include "SubmenuDisponibilidad.h"
#include "MenuLicencias.h"


/// En este menu modifico a los operarios activos
void subMenuDisponibilidad()
{
    // Le damos el nombre que quieramos al objeto
    Menu MenuDisponibilidad;
    // Agregamos el Titulo del menu
    MenuDisponibilidad.setTitulo("MENU CAMBIO DE ESTADO");
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuDisponibilidad.setSalida("Volver al Menu de Principal ");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuDisponibilidad.agregarOpcion("Listar operarios disponibles para rotacion");
    // OPCION 2
    MenuDisponibilidad.agregarOpcion("Alta de disponibilidad");
    // OPCION 3
    MenuDisponibilidad.agregarOpcion("Baja de disponibilidad");

    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuDisponibilidad.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::GREEN);
        system("cls");
        switch (opciones)
        {
        case 1:
            listarOperariosDisponiblesParaRotar();
            system("pause>nul");
            break;

        case 2:
            disponible();
            system("pause>nul");
            break;

        case 3:
            NOdisponible();
            system("pause>nul");
            break;

        default:
            // VOLVER AL MENU ANTERIOR O SALIR
            return;
            break;
        }
    }
}
