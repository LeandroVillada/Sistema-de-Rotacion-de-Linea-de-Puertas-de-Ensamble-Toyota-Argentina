#pragma once
#include <string>
class Empleados
{
private:
    int _legajo;
    std::string _nombre;
    std::string _apellido;
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
    std::string getNombre();
    std::string getApellido();
    bool getDisponibilidad();
    bool getEstado();
    // FUNCIONES PUBLICAS
    bool buscarLegajoExistente(int);
    int buscarPosicionLegajo(int);
    bool LegajoDisponible(int);
    bool cargar();
    void mostrar();
    bool buscarLegajoInactivo(int);
};
