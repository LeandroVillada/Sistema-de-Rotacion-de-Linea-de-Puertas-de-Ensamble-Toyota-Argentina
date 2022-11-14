#include "RotacionArchivo.h"
#include <cstring>

int RotacionArchivo::cantidadRegistros()
{
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    long cant = ftell(pFile) / tamanioRegistro;
    cerrarArchivo();
    return (int)cant;
}

bool RotacionArchivo::abrirArchivo(Modo modo)
{
    switch (estado)
    {
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:
        cerrarArchivo();
        break;
    }
    switch (modo)
    {
    case SoloLectura:
        pFile = fopen(nombreArchivo, "rb");
        if (!pFile)
            return false;
        estado = AbiertoR;
        break;
    case Escritura:
        pFile = fopen(nombreArchivo, "wb");
        if (!pFile)
            return false;
        estado = AbiertoW;
        break;
    case Agregar:
        pFile = fopen(nombreArchivo, "ab");
        if (!pFile)
            return false;
        estado = AbiertoA;
        break;
    case LecturaEscritura:
        pFile = fopen(nombreArchivo, "rb+");
        if (!pFile)
            return false;
        estado = AbiertoRW;
        break;
    }
    return true;
}

void RotacionArchivo::cerrarArchivo()
{
    fclose(pFile);
    estado = Cerrado;
}

RotacionArchivo::RotacionArchivo()
{
    Rotacion registro;
    // Nombre para guardar o abrir los registros
    std::string nombre = "Rotacion.dat";
    nombreArchivo = new char[strlen(nombre.c_str()) + 1];
    if (nombreArchivo == NULL)
    {
        exit(1);
    }
    strcpy(nombreArchivo, nombre.c_str());

    tamanioRegistro = registro.getSize();
    pRegistro = (void *)malloc(tamanioRegistro);
    cantRegistros = cantidadRegistros();
    estado = Cerrado;
}

RotacionArchivo::~RotacionArchivo()
{
    delete nombreArchivo;
    if (pFile)
    {
        fclose(pFile);
    }
    free(pRegistro);
}

Rotacion RotacionArchivo::leer(int nroRegistro)
{
    Rotacion obj{};
    if (!abrirArchivo(SoloLectura))
    {
        return obj;
    }

    fseek(pFile, nroRegistro * sizeof(Rotacion), SEEK_SET);
    fread(&obj, sizeof(Rotacion), 1, pFile);
    cerrarArchivo();
    return obj;
}

bool RotacionArchivo::leer(Rotacion &rotacion, int nroRegistro)
{
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Rotacion), SEEK_SET);
    bool ok = fread(&rotacion, sizeof(Rotacion), 1, pFile);
    cerrarArchivo();
    return ok;
}

bool RotacionArchivo::leerTodos(Rotacion rotaciones[], int cantidad)
{
    if (cantRegistros == 0)
    {
        return false;
    }
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    bool ok = fread(rotaciones, sizeof(Rotacion), cantidad, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

bool RotacionArchivo::guardar(Rotacion rotacion)
{
    // if (!abrirArchivo(Agregar))
    if (!abrirArchivo(Escritura))
    {
        return false;
    }

    bool ok = fwrite(&rotacion, sizeof(Rotacion), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

bool RotacionArchivo::guardar(Rotacion rotacion, int nroRegistro)
{
    if (!abrirArchivo(LecturaEscritura))
    {
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Rotacion), SEEK_SET);
    bool ok = fwrite(&rotacion, sizeof(Rotacion), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

int RotacionArchivo::getCantidadRegistros()
{
    // FILE *pFile = fopen("Rotacion.dat", "rb");
    // if (pFile == NULL)
    // {
    //     return false;
    // }

    // fseek(pFile, 0, SEEK_END);
    // int cant = ftell(pFile) / sizeof(Rotacion);
    // fclose(pFile);
    // return cant;
    return cantRegistros;
}

bool RotacionArchivo::exportar()
{
    if (cantRegistros == 0)
    {
        return false;
    }
    FILE *p;
    p = fopen("Rotacion.txt", "wb");
    if (p == NULL)
    {
        return false;
    }
    Rotacion *registros = new Rotacion[cantRegistros];
    leerTodos(registros, cantRegistros);

    bool ok = fwrite(&registros, registros[0].getSize(), cantRegistros, p);

    fclose(p);
    return ok;
}
