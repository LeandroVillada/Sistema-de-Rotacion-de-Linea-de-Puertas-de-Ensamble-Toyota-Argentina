#pragma once
#include <iostream>

class Cadena
{
private:
	char *p;
	int tam;

public:
	Cadena(const char *);							  // constructor
	Cadena(const Cadena &c) : p(NULL) { *this = c; }; // constructor de copia
	~Cadena()
	{
		if (p)
		{
			delete p;
		}
	};
	const char *getP() { return p; }
	void setP(const char *cad);
	void setP(const Cadena &);
	void Mostrar();
	bool vacio();
	// SOBRECARGAS
	// void operator=(Cadena &);// Limita la asignacion a uno a uno a=b
	Cadena &operator=(const Cadena &); // Permita apilar a=b=c=d
	Cadena &operator=(const char *);   // Para asignar una cadena a un objeto Cadena

	bool operator==(const Cadena &obj);
	bool operator==(const char *obj);

	void operator+=(const char *obj);
	void operator+=(const Cadena &);

	Cadena operator+(const Cadena &); // Para sumar 2 objetos Cadena
	Cadena operator+(const char *);	  // Para sumar un objeto Cadena con una cadena

	friend std::ostream &operator<<(std::ostream &salida, Cadena &obj);
	friend std::istream &operator>>(std::istream &entrada, Cadena &obj);
};
