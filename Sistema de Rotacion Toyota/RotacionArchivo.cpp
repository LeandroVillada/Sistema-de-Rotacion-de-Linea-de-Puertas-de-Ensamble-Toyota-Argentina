#include "RotacionArchivo.h"

Rotacion RotacionArchivo::leer(int nroRegistro)
{
    Rotacion est;
    FILE *pFile = abrirArchivoRB();

    fseek(pFile, nroRegistro * sizeof(Rotacion), SEEK_SET);
    fread(&est, sizeof(Rotacion), 1, pFile);
    fclose(pFile);
    return est;
}

bool RotacionArchivo::leer(Rotacion &rotacion, int nroRegistro)
{
    FILE *pFile = abrirArchivoRB();

    fread(&rotacion, sizeof(Rotacion), 1, pFile);
    fclose(pFile);
    return true;
}

bool RotacionArchivo::leerTodos(Rotacion rotaciones[], int cantidad)
{
    FILE *pFile = abrirArchivoRB();

    fread(rotaciones, sizeof(Rotacion), cantidad, pFile);
    fclose(pFile);
    return true;
}

bool RotacionArchivo::guardar(Rotacion rotacion)
{
    FILE *pFile = fopen("Rotacion.dat", "ab");
    if (pFile == NULL)
    {
        return false;
    }
    bool ok = fwrite(&rotacion, sizeof(Rotacion), 1, pFile);
    fclose(pFile);
    return ok;
}

bool RotacionArchivo::guardar(Rotacion rotacion, int nroRegistro)
{
    FILE *pFile = fopen("Rotacion.dat", "rb+");
    if (pFile == NULL)
    {
        return false;
    }
    fseek(pFile, nroRegistro * sizeof(Rotacion), SEEK_SET);
    bool ok = fwrite(&rotacion, sizeof(Rotacion), 1, pFile);
    fclose(pFile);
    return ok;
}

int RotacionArchivo::getCantidad()
{
    FILE *pFile = abrirArchivoRB();

    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Rotacion);
    fclose(pFile);
    return cant;
}

FILE *RotacionArchivo::abrirArchivoRB()
{
    FILE *pFile;
    pFile = fopen("Rotacion.dat", "rb");
    if (pFile == NULL)
    {
        exit(1550);
    }
    return pFile;
}
