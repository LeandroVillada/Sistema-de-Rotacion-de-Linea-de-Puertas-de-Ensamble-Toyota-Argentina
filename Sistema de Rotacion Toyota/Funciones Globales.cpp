#include "Funciones Globales.h"

#ifdef _WIN32
#include <windows.h>
void esperar(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void esperar(int ms) { usleep(ms * 1000); }
#endif

void vectorEnCero(int *vector, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

int cargarAleatorio(int limite)
{
    return (rand() % limite);
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