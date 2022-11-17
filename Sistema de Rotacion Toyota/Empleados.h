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
    int getSize();
    std::string toString();
    std::string toStringDisponibilidad();
    // OPERADORES
    void operator=(Empleados *obj);
    friend std::ostream &operator<<(std::ostream &salida, Empleados &obj);
    friend std::istream &operator>>(std::istream &entrada, Empleados &obj);

    // FUNCIONES PUBLICAS
    bool comparaID(Empleados *temp);
};
