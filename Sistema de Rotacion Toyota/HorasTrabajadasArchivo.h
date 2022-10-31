#ifndef HORASTRABAJADASARCHIVO_H_INCLUDED
#define HORASTRABAJADASARCHIVO_H_INCLUDED
#include "HorasTrabajadas.h"

class HorasTrabajadasArchivo{
public:
  HorasTrabajadas leer(int nroRegistro);
  //bool guardar(HorasTrabajadas ht);
  //bool guardar(HorasTrabajadas ht, int nroRegistro);
  int getCantidad();
  int buscar(int id);
  bool grabarEnDisco();
};


#endif // HORASTRABAJADASARCHIVO_H_INCLUDED
