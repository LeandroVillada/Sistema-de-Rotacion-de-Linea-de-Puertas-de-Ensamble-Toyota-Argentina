#include "SubmenuRotacion.h"
void submenuRotation()
{
    int *legajosDisponibles;
    legajosDisponibles = new int[contarLegajosActivosDisponibles()];
    if (legajosDisponibles == NULL)
    {
        return;
    }
    vectorEnCero(legajosDisponibles, contarLegajosActivosDisponibles());

    int operariosParaRotar[26];
    vectorEnCero(operariosParaRotar, 26);

    // Le damos el nombre que quieramos al objeto
    Menu MenuRotacion;
    // Agregamos la Opcion para salir o volver al menu anterior
    MenuRotacion.setSalida("Volver al Menu de Principal");
    // Agregamos el Titulo del menu
    MenuRotacion.setTitulo("ARMADO DE ROTACION");

    // AGREGAMOS LAS OPCIONES CON UNA FUNCION
    // OPCION 1
    MenuRotacion.agregarOpcion("Agregar TM a Disponibles para rotar");
    // OPCION 2
    MenuRotacion.agregarOpcion("Armar Rotacion Semanal");
    // OPCION 3
    MenuRotacion.agregarOpcion("Mostrar Lista Completa de TM Disponibles para Rotacion");
    // OPCION 4
    MenuRotacion.agregarOpcion("Mostrar rotacion");

    // Aqui generamos un while en true en caso de que quieramos que dibuje nuevamente el menu
    while (true)
    {
        system("cls");
        // Elegimos el color del texto del menu y el Fondo del texto
        int opciones = MenuRotacion.dibujarMenu(rlutil::COLOR::WHITE, rlutil::COLOR::BLUE);
        system("cls");
        switch (opciones)
        {
        case 1:
            agregarEmpleadosDisponiblesParaRotar(legajosDisponibles, operariosParaRotar);
            system("pause>nul");
            break;

        case 2:
            armarRotacion(operariosParaRotar);
            system("pause>nul");
            break;

        case 3:
            listarLegajosCargadosParaRotacion(operariosParaRotar);
            listarLegajosDisponiblesParaRotacion(legajosDisponibles, contarLegajosActivosDisponibles());
            system("pause>nul");
            break;

        case 4:
            mostrarRotacion();
            system("pause>nul");
            break;
        default:
            // delete legajosDisponibles;
            // VOLVER AL MENU ANTERIOR O SALIR
            return;
            break;
        }
    }
}
