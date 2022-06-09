#pragma once
#include <iostream>
class Empleados
{
private:
    int _legajo;
    char _nombre[50];
    char _apellido[50];
    bool _disponibilidad;
    bool _estado;

public:
    // CONSTRUCTORES
    Empleados();
    // FUNCIONES ARCHIVOS
    bool leerDeDisco(int);
    bool grabarEnDisco();
    bool modificarEnDisco(int);
    int cantidadRegistros();
    // SETS
    void setLegajo(int);
    void setNombre(std::string);
    void setApellido(std::string);
    void setDisponibilidad(bool);
    void setEstado(bool);
    // GETS
    int getLegajo();
    const char *getNombre();
    const char *getApellido();
    bool getDisponibilidad();
    bool getEstado();
    // FUNCIONES PUBLICAS
    bool buscarLegajoExistente(int);
    int buscarPosicionLegajo(int);
    bool LegajoDisponible(int);
    bool cargar();
    void mostrar();
    bool buscarLegajoInactivo(int);
    const char*buscarApellidoPorLegajo(int);
    const char*buscarNombrePorLegajo(int);
};
