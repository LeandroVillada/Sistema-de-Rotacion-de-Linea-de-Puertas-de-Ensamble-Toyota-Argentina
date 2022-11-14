#include <iostream>
#include <cstring>
#include "LicenciasArchivo.h"

int LicenciasArchivo::cantidadRegistros()
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

bool LicenciasArchivo::abrirArchivo(Modo modo)
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

void LicenciasArchivo::cerrarArchivo()
{
    fclose(pFile);
    estado = Cerrado;
}

LicenciasArchivo::LicenciasArchivo()
{
    Licencias registro;
    // Nombre para guardar o abrir los registros
    std::string nombre = "Licencias.dat";
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

LicenciasArchivo::~LicenciasArchivo()
{
    delete nombreArchivo;
    if (pFile)
    {
        fclose(pFile);
    }
    free(pRegistro);
}

Licencias LicenciasArchivo::leer(int nroRegistro)
{
    Licencias obj{};
    if (!abrirArchivo(SoloLectura))
    {
        return obj;
    }

    fseek(pFile, nroRegistro * obj.getSize(), SEEK_SET);
    fread(&obj, obj.getSize(), 1, pFile);
    cerrarArchivo();
    return obj;
}

bool LicenciasArchivo::leer(Licencias &licencias, int nroRegistro)
{
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Licencias), SEEK_SET);
    bool ok = fread(&licencias, sizeof(Licencias), 1, pFile);
    cerrarArchivo();
    return ok;
}

bool LicenciasArchivo::leerTodos(Licencias registros[], int cantidad)
{
    if (cantRegistros == 0)
    {
        return false;
    }
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    bool ok = fread(registros, sizeof(Licencias), cantidad, pFile);
    cerrarArchivo();
    return ok;
}

bool LicenciasArchivo::guardar(Licencias registro)
{
    if (!abrirArchivo(Escritura))
    {
        return false;
    }
    bool ok = fwrite(&registro, sizeof(Licencias), 1, pFile);
    fclose(pFile);
    return ok;
}

bool LicenciasArchivo::guardar(Licencias registro, int nroRegistro)
{
    if (!abrirArchivo(LecturaEscritura))
    {
        return false;
    }

    fseek(pFile, nroRegistro * sizeof(Licencias), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Licencias), 1, pFile);
    cerrarArchivo();
    return ok;
}

int LicenciasArchivo::getCantidadRegistros()
{
    return cantRegistros;
}

int LicenciasArchivo::buscarPorLegajo(int legajo)
{
    Licencias *aux = new Licencias[cantRegistros];
    for (int i = 0; i < cantRegistros; i++)
    {
        if (aux[i].getLegajo() == legajo)
        {
            return i;
        }
    }
    return -1;
}
