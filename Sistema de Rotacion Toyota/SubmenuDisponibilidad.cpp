#include "SubmenuDisponibilidad.h"
#include "Licencias.h"

void subMenuDisponibilidad()
{

    /// En este menu modifico a los operarios activos y los agrego a la disponibilidad para rotacion

    int opcion;
    while (true)
    {
        system("color 2");
        system("cls");
        cout << "MENU CAMBIO DE DISPONIBILIDAD" << endl;

        cout << "\n\t1. Listar Operarios Activos para rotacion" << endl;
        cout << "\n\t2. Confirmar disponibilidad" << endl;
        cout << "\n\t3. Eliminar disponibilidad" << endl;
        cout << "\n\t4. Licencia" << endl;
        cout << "\n\t0. Volver al Menu Principal" << endl<<endl;

        cout << "\nSeleccione una opcion :  ";
        cin >> opcion;
        system("cls");
        switch (opcion)
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

        case 4:
            licencia();
            system("pause>nul");
            break;

        case 0:
            return;
            system("pause>nul");
            break;

        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
        }
    }
}
