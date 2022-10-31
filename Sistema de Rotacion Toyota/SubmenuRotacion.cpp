#include "SubmenuRotacion.h"
void submenuRotation()
{
    int opciones;

    int *legajosDisponibles;
    legajosDisponibles = new int[contarLegajosActivosDisponibles()];
    vectorEnCero(legajosDisponibles, contarLegajosActivosDisponibles());

    int operariosParaRotar[26];
    vectorEnCero(operariosParaRotar, 26);

    while (true)
    {
        system("color 4");
        system("cls");
        cout << "\t\t\tARMADO DE ROTACION" << endl;
        cout << "\n\t1. Agregar TM a Disponibles para rotar" << endl;
        cout << "\n\t2. Armar Rotacion Semanal" << endl;
        cout << "\n\t3. Mostrar Lista Completa de TM Disponibles para Rotacion" << endl;
        cout << "\n\t4. Mostrar rotacion" << endl;
        cout << "\n\t0. Volver al Menu Principal" << endl<<endl;

        cout << "\nSeleccione una Opcion:  ";
        cin >> opciones;
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

        case 0:
            delete legajosDisponibles;
            return;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}
