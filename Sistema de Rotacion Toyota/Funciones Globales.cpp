#include "Funciones Globales.h"

void cargarCadenas(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = std::cin.get();
        if (pal[i] == '\n')
        {
            break;
        }
    }
    pal[i] = '\0';
    fflush(stdin);
}

void vectorEnCero(int *vector, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

void gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void mostrarMensaje(std::string mensaje, int color, int colorFondo)
{
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    std::cout << mensaje;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void confirmarSalida()
{
    char confirmarSalida;
    mostrarMensaje("Confirmar salida (S/N): ", 15, 4);
    // std::cout << endl;
    std::cin >> confirmarSalida;
    if (tolower(confirmarSalida) == 's')
    {
        return;
    }
}