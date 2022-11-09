#ifndef HORASTRABAJADASARCHIVO_H_INCLUDED
#define HORASTRABAJADASARCHIVO_H_INCLUDED
#include "HorasTrabajadas.h"

class HorasTrabajadasArchivo{
public:
    // FUNCIONES ARCHIVOS
    FILE *abrirArchivoHT();
    HorasTrabajadas leer(int nroRegistro);
    bool leer(HorasTrabajadas &horasTrabajadas, int nroRegistro);
    bool leerTodos(HorasTrabajadas horasTrabajadas[], int cantidad);
    bool guardar(HorasTrabajadas horasTrabajadas);
    bool guardar(HorasTrabajadas horasTrabajadas, int nroRegistro);
    int getCantidad();
    int buscar(int);
    //void mostrar(HorasTrabajadas);

    void mostrarArchivo();

    // FUNCIONES PUBLICAS
    bool cargar();
    void mostrar();
};

#endif // HORASTRABAJADASARCHIVO_H_INCLUDED
