#include "Empleados.h"


// CONSTRUCTORES
Empleados::Empleados()
{
    _legajo = 0;
    _nombre = "";
    _apellido = "";
    _disponibilidad = true;
    _estado = true;
}
// FUNCIONES ARCHIVOS
bool Empleados::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("Empleados.dat", "rb");
    bool leyo;
    if (p == NULL)
    {
        puts("NO SE PUDO ABRIR EL ARCHIVO");
        return false;
    }
    fseek(p, pos * sizeof *this, 0);
    leyo = fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
bool Empleados::grabarEnDisco()
{
    FILE *p;
    p = fopen("Empleados.dat", "ab");
    bool grabo;
    if (p == NULL)
    {
        return false;
    }
    grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
bool Empleados::modificarEnDisco(int pos)
{
    FILE *p;
    p = fopen("Empleados.dat", "rb+");
    if (p == NULL)
    {
        puts("NO SE PUDO ABRIR EL ARCHIVO");
        return false;
    }
    fseek(p, sizeof *this * pos, 0);

    bool leyo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
int Empleados::cantidadRegistros()
{
    int cantidad = 0;
    while (leerDeDisco(cantidad++))
    {
    }
    return cantidad - 1;
}
// SETTS
void Empleados::setLegajo(int legajo) { _legajo = legajo; }

void Empleados::setNombre(std::string nombre) { _nombre = nombre; }

void Empleados::setApellido(std::string apellido) { _apellido = apellido; }

void Empleados::setDisponibilidad(bool disponibilidad) { _disponibilidad = disponibilidad; }

void Empleados::setEstado(bool estado) { _estado = estado; }

// GETTS
int Empleados::getLegajo() { return _legajo; }

std::string Empleados::getNombre() { return _nombre; }

std::string Empleados::getApellido() { return _apellido; }

bool Empleados::getDisponibilidad() { return _disponibilidad; }

bool Empleados::getEstado() { return _estado; }

// FUNCIONES PUBLICAS
bool Empleados::buscarLegajoExistente(int legajo)
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getLegajo() == legajo)
            return true;
    }
    return false;
}
int Empleados::buscarPosicionLegajo(int legajo)
{
    Empleados reg;
    int pos = 0;
    while (reg.leerDeDisco(pos))
    {
        if (legajo == reg.getLegajo())
            return pos;
        pos++;
    }
    return -1;
}
bool Empleados::LegajoDisponible(int legajo)
{
    Empleados reg;
    int pos = buscarPosicionLegajo(legajo);
    reg.leerDeDisco(pos);
    if ((reg.getEstado())&&(reg.getDisponibilidad()))
        return true;
    else
        return false;
}

bool Empleados::buscarLegajoInactivo(int legajo)
{
        Empleados reg;
        int pos = reg.buscarPosicionLegajo(legajo);
        reg.leerDeDisco(pos);
        if (!reg.getEstado())
            return true;
        else
            return false;
    }


