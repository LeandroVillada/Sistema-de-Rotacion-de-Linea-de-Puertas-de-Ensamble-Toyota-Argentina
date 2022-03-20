/// Autores: Villada Leandro, Barrios Marcos.

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int opc;

    // Desarrollo del Programa
    while (true)
    {
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "\n\t1. " << endl;
        cout << "\t2. " << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES:  ";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            system("pasuse>nul");
            break;
        case 0: // Fin del Programa
            return 0;
        default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pasuse>nul");
            break;
        }
    }
}