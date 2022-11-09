#pragma once
#include <iostream>
#include <string>
class Empleados
{
protected:
    int _legajo;
    char _nombre[50];
    char _apellido[50];
    bool _disponibilidad;
    bool _estado;

public:
    // CONSTRUCTORES
    Empleados();
    /*
    // FUNCIONES ARCHIVOS
    //bool leerDeDisco(int);
    bool grabarEnDisco();
    bool modificarEnDisco(int);
    int cantidadRegistros();
    */
    // SETS
    void setLegajo(int);
    void setNombre(std::string);
    void setApellido(std::string);
    void setDisponibilidad(bool);
    void setEstado(bool);
    // GETS
    int getLegajo();
    std::string getNombre();
    std::string getApellido();
    bool getDisponibilidad();
    bool getEstado();
    std::string toString();
    /*
    // FUNCIONES PUBLICAS
    bool buscarLegajoExistente(int);
    int buscarPosicionLegajo(int);
    bool LegajoDisponible(int);
    bool cargar();
    void mostrar();
    bool buscarLegajoInactivo(int);
    Empleados buscarEmpleadoPorLegajo(int);
    */
};
