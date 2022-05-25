#include <iostream>
#include <ctime>
using namespace std;

// Prototipos de Funciones
int cargarPosicionAleatoria(int limite);
bool validarLegajoRepetido(int *, int);
void cargarBloqueUno(int (*)[26], int *);

int main()
{
    system("color 6");
    // Variables
    int operariosParaRotar[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        operariosParaRotar[i] = i + 100;
        cout << "POSICION: " << i << " LEGAJO: " << operariosParaRotar[i] << endl;
    }
    cout << endl;
    int rotacion[4][26] = {0};
    cargarBloqueUno(rotacion, operariosParaRotar);

    // Desarrollo del Programa

    // Fin del Programa
    system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
int cargarPosicionAleatoria(int limite)
{
    return (rand() % limite);
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
    int pos = 0;
    int posicionGenerada;
    int contador = 0;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarPosicionAleatoria(26);
        cout << "NUMERO GENERADO: " << posicionGenerada << endl;
        while (validarLegajoRepetido(rotacion[0], operariosParaRotar[posicionGenerada]))
        {
            cout << "NUMERO REPETIDO: " << operariosParaRotar[posicionGenerada] << endl;
            posicionGenerada = cargarPosicionAleatoria(26);
            cout << "NUMERO GENERADO: " << posicionGenerada << endl;
            cout << "SE CAMBIO POR: " << operariosParaRotar[posicionGenerada] << endl;
            contador++;
        }

        rotacion[0][i] = operariosParaRotar[posicionGenerada];
        cout << "POSICION: " << i << "\t OCUPA EL LEGAJO: " << operariosParaRotar[posicionGenerada] << endl;
    }
    cout << "\nTOTAL REPETIDOS; " << contador << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << rotacion[0][i];
        cout << endl;
    }
}