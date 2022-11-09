#include "Empleados.h"
#include <cstdio>
#include <cstring>
#include <iostream>

// CONSTRUCTORES
Empleados::Empleados()
{
	_legajo = 0;
	strcpy(_nombre, "");
	strcpy(_apellido, "");
	_disponibilidad = true;
	_estado = true;
}
/*
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
	FILE* p;
	p = fopen("Empleados.dat", "ab");
	bool grabo;
	if (p == NULL)
	{
		return false;
	}
	grabo = fwrite(this, sizeof * this, 1, p);
	fclose(p);
	return grabo;
}
bool Empleados::modificarEnDisco(int pos)
{
	FILE* p;
	p = fopen("Empleados.dat", "rb+");
	if (p == NULL)
	{
		puts("NO SE PUDO ABRIR EL ARCHIVO");
		return false;
	}
	fseek(p, sizeof * this * pos, 0);

	bool leyo = fwrite(this, sizeof * this, 1, p);
	fclose(p);
	return leyo;
}
int Empleados::cantidadRegistros()
{
	int cantidad = 0;
	while (leer(cantidad++))
	{
	}
	return cantidad - 1;
}
*/
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

std::string Empleados::toString()
{
	std::string cadena;
	cadena = std::to_string(_legajo) + "," + _nombre + "," + _apellido + "," + std::to_string(_disponibilidad) + "," + std::to_string(_estado);
	return cadena;
}

/*
// FUNCIONES PUBLICAS
bool Empleados::buscarLegajoExistente(int legajo)
{
	Empleados reg;
	int pos = 0;
	while (reg.leer(pos++))
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
	while (reg.leer(pos))
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
	reg.leer(pos);
	if ((reg.getEstado()) && (reg.getDisponibilidad()))
		return true;
	else
		return false;
}

bool Empleados::buscarLegajoInactivo(int legajo)
{
	Empleados reg;
	int pos = reg.buscarPosicionLegajo(legajo);
	reg.leer(pos);
	if (!reg.getEstado())
		return true;
	else
		return false;
}

Empleados Empleados::buscarEmpleadoPorLegajo(int legajo)
{
	Empleados aux;
	aux.leer(aux.buscarPosicionLegajo(legajo));
	return aux;
}
*/