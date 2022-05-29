#include <iostream>
#include <ctime>
using namespace std;

// Prototipos de Funciones
int cargarPosicionAleatoria(int limite);
bool validarLegajoRepetido(int *, int);
void cargarBloqueUno(int (*)[26], int *);
void cargarBloqueDos(int (*)[26], int *);
void cargarBloqueTres(int (*)[26], int *);
void cargarBloqueCuatro(int (*)[26], int *);

void mostrarMatriz(int v[][26], int nf, int nc)
{
    for (int i = 0; i < nf; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

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
    cout << endl;
    system("pause>nul");
    cargarBloqueDos(rotacion, operariosParaRotar);
    system("pause>nul");
    cargarBloqueTres(rotacion, operariosParaRotar);
    system("pause>nul");
    cargarBloqueCuatro(rotacion, operariosParaRotar);
    system("pause>nul");
    system("cls");
    mostrarMatriz(rotacion,4,26);
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

    int pos = 0;
    int posicionGenerada;
    int contador = 0;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarPosicionAleatoria(26);
        cout << "NUMERO GENERADO: " << posicionGenerada << endl;
        while (validarLegajoRepetido(rotacion[1], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i))
        {
            cout << "NUMERO REPETIDO: " << operariosParaRotar[posicionGenerada] << endl;
            posicionGenerada = cargarPosicionAleatoria(26);
            cout << "NUMERO GENERADO: " << posicionGenerada << endl;
            cout << "SE CAMBIO POR: " << operariosParaRotar[posicionGenerada] << endl;
            contador++;
        }

        rotacion[1][i] = operariosParaRotar[posicionGenerada];
        cout << "POSICION: " << i << "\t OCUPA EL LEGAJO: " << operariosParaRotar[posicionGenerada] << endl;
    }
    cout << "\nTOTAL REPETIDOS; " << contador << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << rotacion[1][i];
        cout << endl;
    }
}

void cargarBloqueTres(int rotacion[][26], int *operariosParaRotar)
{

    int pos = 0;
    int posicionGenerada;
    int contador = 0;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarPosicionAleatoria(26);
        cout << "NUMERO GENERADO: " << posicionGenerada << endl;
        while (validarLegajoRepetido(rotacion[2], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[1], operariosParaRotar[posicionGenerada], i))
        {
            cout << "NUMERO REPETIDO: " << operariosParaRotar[posicionGenerada] << endl;
            posicionGenerada = cargarPosicionAleatoria(26);
            cout << "NUMERO GENERADO: " << posicionGenerada << endl;
            cout << "SE CAMBIO POR: " << operariosParaRotar[posicionGenerada] << endl;
            contador++;
        }
        rotacion[2][i] = operariosParaRotar[posicionGenerada];
        cout << "POSICION: " << i << "\t OCUPA EL LEGAJO: " << operariosParaRotar[posicionGenerada] << endl;
    }
    cout << "\nTOTAL REPETIDOS; " << contador << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << rotacion[2][i];
        cout << endl;
    }
}

void cargarBloqueCuatro(int rotacion[][26], int *operariosParaRotar)
{

    int pos = 0;
    int posicionGenerada;
    int contador = 0;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
    {
        posicionGenerada = cargarPosicionAleatoria(26);
        cout << "NUMERO GENERADO: " << posicionGenerada << endl;
        while (validarLegajoRepetido(rotacion[3], operariosParaRotar[posicionGenerada]) || validarOperacionEspejosRepetidas(rotacion[0], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[1], operariosParaRotar[posicionGenerada], i) || validarOperacionEspejosRepetidas(rotacion[2], operariosParaRotar[posicionGenerada], i))
        {
            cout << "NUMERO REPETIDO: " << operariosParaRotar[posicionGenerada] << endl;
            posicionGenerada = cargarPosicionAleatoria(26);
            cout << "NUMERO GENERADO: " << posicionGenerada << endl;
            cout << "SE CAMBIO POR: " << operariosParaRotar[posicionGenerada] << endl;
            contador++;
        }

        rotacion[3][i] = operariosParaRotar[posicionGenerada];
        cout << "POSICION: " << i << "\t OCUPA EL LEGAJO: " << operariosParaRotar[posicionGenerada] << endl;
    }
    cout << "\nTOTAL REPETIDOS; " << contador << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << rotacion[3][i];
        cout << endl;
    }
}