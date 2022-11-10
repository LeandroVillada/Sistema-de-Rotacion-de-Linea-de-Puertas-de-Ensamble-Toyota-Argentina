#include <iostream>
#include "LicenciasArchivo.h"

FILE *LicenciasArchivo::abrirArchivoL()
{
    FILE *pFile;
    pFile = fopen("Licencias.dat", "rb");
    if (pFile == NULL)
    {
        exit(1550);
    }
    return pFile;
}

Licencias LicenciasArchivo::leer(int nroRegistro)
{
    Licencias est;
    FILE *pFile=abrirArchivoL();

    fseek(pFile, nroRegistro * sizeof(Licencias), SEEK_SET);
    fread(&est, sizeof(Licencias), 1, pFile);
    fclose(pFile);
    return est;
}

bool LicenciasArchivo::leer(Licencias &licencias, int nroRegistro)
{
    FILE *pFile;
    pFile = abrirArchivoL();
    fseek(pFile, nroRegistro * sizeof(Licencias), SEEK_SET);
    fread(&licencias, sizeof(Licencias), 1, pFile);
    fclose(pFile);
    return true;
}

bool LicenciasArchivo::leerTodos(Licencias clases[], int cantidad)
{
    FILE *pFile;
    pFile = abrirArchivoL();
    fread(clases, sizeof(Licencias), cantidad, pFile);
    fclose(pFile);
    return true;
}

bool LicenciasArchivo::guardar(Licencias clase)
{
    FILE *pFile = fopen("Licencias.dat", "ab");
    if (pFile == NULL)
    {
        return false;
    }
    bool ok = fwrite(&clase, sizeof(Licencias), 1, pFile);
    fclose(pFile);
    return ok;
}

bool LicenciasArchivo::guardar(Licencias clase, int nroRegistro)
{
    FILE *pFile = fopen("Licencias.dat", "rb+");
    if (pFile == NULL)
    {
        return false;
    }
    fseek(pFile, nroRegistro * sizeof(Licencias), SEEK_SET);
    bool ok = fwrite(&clase, sizeof(Licencias), 1, pFile);
    fclose(pFile);
    return ok;
}

int LicenciasArchivo::getCantidad()
{
    FILE *pFile = abrirArchivoL();

    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Licencias);
    fclose(pFile);
    return cant;
}

int LicenciasArchivo::buscar(int legajo)
{
  Licencias aux;
  int i = 0;
  int cantHoras = getCantidad();
  for (i = 0; i < cantHoras; i++) {
    aux = leer(i);
    if (aux.getLegajo() == legajo) {
      return i;
    }
  }
  return -1;
}

