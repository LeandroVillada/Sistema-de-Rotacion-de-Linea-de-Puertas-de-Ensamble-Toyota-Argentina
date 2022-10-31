#include "HorasTrabajadasArchivo.h"

HorasTrabajadas HorasTrabajadasArchivo::leer(int nroRegistro){
  HorasTrabajadas aux;
  FILE* p;
  p = fopen("horasTrabajadas.dat", "rb");
  if (p == NULL){
    return aux;
  }
  fseek(p, sizeof(HorasTrabajadas) * nroRegistro, SEEK_SET);
  fread(&aux, sizeof(HorasTrabajadas), 1, p);
  fclose(p);
  return aux;
}

bool HorasTrabajadasArchivo::grabarEnDisco()
{
    FILE *p;
    p = fopen("horasTrabajadas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool grabo;
    grabo = fwrite(this, sizeof(HorasTrabajadas), 1, p);
    fclose(p);
    return grabo;
}
/*
bool HorasTrabajadasArchivo::guardar(HorasTrabajadas ht)
{
  FILE* p;
  p = fopen("horasTrabajadas.dat", "ab");
  if (p == NULL) {
    return false;
  }
  fwrite(&ht, sizeof(HorasTrabajadas), 1, p);
  fclose(p);
  return true;
}

bool HorasTrabajadasArchivo::guardar(HorasTrabajadas ht, int nroRegistro)
{
  FILE* p;
  p = fopen("horasTrabajadas.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, sizeof(HorasTrabajadas) * nroRegistro, SEEK_SET);
  fwrite(&ht, sizeof(HorasTrabajadas), 1, p);
  fclose(p);
  return true;
}
*/
int HorasTrabajadasArchivo::getCantidad()
{
  FILE* p;
  p = fopen("horasTrabajadas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(HorasTrabajadas);
  fclose(p);
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
