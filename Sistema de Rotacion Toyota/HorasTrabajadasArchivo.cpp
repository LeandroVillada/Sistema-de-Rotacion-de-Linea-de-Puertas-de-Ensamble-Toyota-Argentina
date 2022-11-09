#include "HorasTrabajadasArchivo.h"
#include <cstring>

FILE *HorasTrabajadasArchivo::abrirArchivoHT()
{
    FILE *pFile;
    pFile = fopen("horasTrabajadas.dat", "rb");
    if (pFile == NULL)
    {
        exit(1550);
    }
    return pFile;
}

HorasTrabajadas HorasTrabajadasArchivo::leer(int nroRegistro)
{
    HorasTrabajadas est;
    FILE *pFile=abrirArchivoHT();

    fseek(pFile, nroRegistro * sizeof(HorasTrabajadas), SEEK_SET);
    fread(&est, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return est;
}

bool HorasTrabajadasArchivo::leer(HorasTrabajadas &horasTrabajadas, int nroRegistro)
{
    FILE *pFile;
    pFile = abrirArchivoHT();
    fseek(pFile, nroRegistro * sizeof(HorasTrabajadas), SEEK_SET);
    fread(&horasTrabajadas, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return true;
}

bool HorasTrabajadasArchivo::leerTodos(HorasTrabajadas clases[], int cantidad)
{
    FILE *pFile;
    pFile = abrirArchivoHT();
    fread(clases, sizeof(HorasTrabajadas), cantidad, pFile);
    fclose(pFile);
    return true;
}

bool HorasTrabajadasArchivo::guardar(HorasTrabajadas clase)
{
    FILE *pFile = fopen("horasTrabajadas.dat", "ab");
    if (pFile == NULL)
    {
        return false;
    }
    bool ok = fwrite(&clase, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return ok;
}

bool HorasTrabajadasArchivo::guardar(HorasTrabajadas clase, int nroRegistro)
{
    FILE *pFile = fopen("horasTrabajadas.dat", "rb+");
    if (pFile == NULL)
    {
        return false;
    }
    fseek(pFile, nroRegistro * sizeof(HorasTrabajadas), SEEK_SET);
    bool ok = fwrite(&clase, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return ok;
}

int HorasTrabajadasArchivo::getCantidad()
{
    FILE *pFile = abrirArchivoHT();

    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(HorasTrabajadas);
    fclose(pFile);
    return cant;
}

int HorasTrabajadasArchivo::buscar(int legajo)
{
  HorasTrabajadas aux;
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

