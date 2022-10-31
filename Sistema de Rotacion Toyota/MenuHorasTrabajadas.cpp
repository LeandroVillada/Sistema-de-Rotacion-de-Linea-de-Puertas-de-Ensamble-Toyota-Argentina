#include "HorasTrabajadas.h"
#include "Empleados.h"
#include "MenuHorasTrabajadas.h"
using namespace std;

void MenuHoraTrabajadas(){
    HorasTrabajadas reg;
    Empleados aux;
    int opcion, legajo=0, anio=0, mes=0;
    while (true)
    {
        system("color 4");
        system("cls");
        cout << "MENU HORAS TRABAJADAS" << endl;

        cout << "\n\t1. Agregar registro" << endl;
        cout << "\n\t2. Mostrar registros (todos)" << endl;
        cout << "\n\t3. Mostrar registros (por Legajo)" << endl;
        cout << "\n\t4. Mostrar horas trabajadas (por Legajo)" << endl;
        cout << "\n\t5. Promedio general" << endl;
        cout << "\n\t6. Promedio total (por Legajo)" << endl;
        cout << "\n\t7. Promedio por mes (por Legajo)" << endl;
        cout << "\n\t8. Promedio por anio (por Legajo)" << endl;
        cout << "\n\t0. Volver al Menu Principal" << endl<<endl;

        cout << "\nSeleccione una opcion :  ";
        cin >> opcion;
        system("cls");
        switch (opcion){

        case 1:
            reg.agregarRegistros();
            break;

        case 2:
            reg.mostrarRegistros();
            system("pause>nul");
            break;

        case 3:
            cout<<"Que legajo desea saber las horas trabajadas: ";
            cin>>legajo;
            if(aux.buscarLegajoExistente(legajo)==true){
                reg.mostrarRegistrosPorLegajo(legajo);
            }
            else{
                cout<<"El legajo no existe!!";
            }
            system("pause>nul");
            break;

        case 4:
            cout<<"Que legajo desea saber las horas trabajadas: ";
            cin>>legajo;
            if(aux.buscarLegajoExistente(legajo)==true){
                reg.sumaHorasPorLegajo(legajo);
            }
            else{
                cout<<"El legajo no existe!!";
            }
            system("pause>nul");
            break;

        case 5:
            reg.PromedioGeneral();
            system("pause>nul");
            break;

        case 6:
            cout<<"Que legajo desea saber las horas trabajadas: ";
            cin>>legajo;
            if(aux.buscarLegajoExistente(legajo)==true){
                reg.PromedioPorLegajo(legajo);
            }
            else{
                cout<<"El legajo no existe!!";
            }
            system("pause>nul");
            break;

        case 7:
            cout<<"Que legajo desea saber las horas trabajadas: ";
            cin>>legajo;
            if(aux.buscarLegajoExistente(legajo)==true){
                cout<<"Que mes desea saber las horas trabajadas: ";
                cin>>mes;
                reg.PromedioPorLegajoYMes(legajo,mes);
            }
            else{
                cout<<"El legajo no existe!!";
            }
            system("pause>nul");
            break;

        case 8:
            cout<<"Que legajo desea saber las horas trabajadas: ";
            cin>>legajo;
            if(aux.buscarLegajoExistente(legajo)==true){
                cout<<"Que anio desea saber las horas trabajadas: ";
                cin>>anio;
                reg.PromedioPorLegajoYAnio(legajo,anio);
            }
            else{
                cout<<"El legajo no existe!!";
            }
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
