#include "Empleados.h"
#include <cstring>

// CONSTRUCTORES
Empleados::Empleados()
{
	_legajo = 0;
	strcpy(_nombre, "");
	strcpy(_apellido, "");
	_disponibilidad = true;
	_estado = true;
}

// SETTS
void Empleados::setLegajo(int legajo) { _legajo = legajo; }

void Empleados::setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }

void Empleados::setApellido(std::string apellido) { strcpy(_apellido, apellido.c_str()); }

void Empleados::setDisponibilidad(bool disponibilidad) { _disponibilidad = disponibilidad; }

void Empleados::setEstado(bool estado) { _estado = estado; }

// GETTS
int Empleados::getLegajo() { return _legajo; }

std::string Empleados::getNombre()
{
	std::string nombre = _nombre;
	return nombre;
}

std::string Empleados::getApellido()
{
	std::string apellido = _apellido;
	return apellido;
}

bool Empleados::getDisponibilidad() { return _disponibilidad; }

bool Empleados::getEstado() { return _estado; }

int Empleados::getSize()
{
	return sizeof *this;
}

std::string Empleados::toString()
{
	std::string cadena;
	cadena = std::to_string(_legajo) + "," + _nombre + "," + _apellido + "," + std::to_string(_disponibilidad) + "," + std::to_string(_estado);
	return cadena;
}

std::string Empleados::toStringDisponibilidad()
{
	std::string cadena;
	if (_disponibilidad)
	{
		cadena = "SI";
	}
	else
	{
		cadena = "NO";
	}
	return cadena;
}

void Empleados::operator=(Empleados *obj)
{
	_legajo = obj->_legajo;
	strcpy(_nombre, obj->_nombre);
	strcpy(_apellido, obj->_apellido);
	_disponibilidad = obj->_disponibilidad;
	_estado = obj->_estado;
}

bool Empleados::comparaID(Empleados *temp)
{
	Empleados *aux = temp;
	if (_legajo == aux->_legajo)
	{
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &salida, Empleados &obj)
{
	std::cout << "LEGAJO: ";
	salida << obj._legajo << std::endl;
	std::cout << "NOMBRE: ";
	salida << obj._nombre << std::endl;
	std::cout << "APELLIDO: ";
	salida << obj._apellido << std::endl;
	std::cout << "DISPONIBILIDAD: ";
	salida << obj._disponibilidad << std::endl;
	std::cout << "ESTADO: ";
	salida << obj._estado << std::endl;
	return salida;
}

std::istream &operator>>(std::istream &entrada, Empleados &obj)
{
	std::cout << "LEGAJO: ";
	entrada >> obj._legajo;
	std::cout << "NOMBRE: ";
	entrada >> obj._nombre;
	std::cout << "APELLIDO: ";
	entrada >> obj._apellido;
	std::cout << "DISPONIBILIDAD: ";
	entrada >> obj._disponibilidad;
	std::cout << "ESTADO: ";
	entrada >> obj._estado;
	return entrada;
}
