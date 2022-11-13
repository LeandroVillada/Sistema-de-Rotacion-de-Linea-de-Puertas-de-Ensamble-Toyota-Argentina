#include "Cadena.h"
#include <cstring>
// DESARROLLO DE LOS METODOS
// CONSTRUCTOR
Cadena::Cadena(const char* cad = NULL)
{
	if (cad == NULL)
	{
		p = NULL;
		tam = 0;
		return;
	}
	tam = strlen(cad) + 1;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, cad);
}

// SETS
void Cadena::setP(const char* cad)
{
	if (p)
		delete p;
	tam = strlen(cad) + 1;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, cad);
}

void Cadena::setP(const Cadena& cad)
{
	if (p)
		delete p;
	tam = cad.tam;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, cad.p);
}

// MOSTRAR
void Cadena::Mostrar()
{
	std::cout << p;
}

bool Cadena::vacio()
{
	if (p[0] == '\0')
	{
		// No cargo nada
		return false;
	}
	return true;
}

// SOBRECARGAS
/*void Cadena::operator=(const char *cad)//Para asignar un objeto a otro
	{
	tam=strlen(cad)+1;
	delete p;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,cad);
	 }
*/
// ASIGNACION
Cadena& Cadena::operator=(const char* cad) // Para asignar a un objeto una cadena
{
	if (p)
		delete p;
	tam = strlen(cad) + 1;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, cad);
	return *this;
}

Cadena& Cadena::operator=(const Cadena& c)
{
	if (this != &c)
	{
		delete p;
		if (c.p)
		{
			p = new char[c.tam];
			strcpy(p, c.p);
		}
		else
			p = NULL;
	}
	return *this;
}

//==
bool Cadena::operator==(const Cadena& obj) // Para comparar dos objetos
{
	if (strcmp(p, obj.p) == 0)
		return true;
	return false;
}

bool Cadena::operator==(const char* obj) // Para comparar un objeto con una cadena
{
	if (strcmp(p, obj) == 0)
		return true;
	return false;
}

//+
Cadena Cadena::operator+(const Cadena& obj) // Para concatenar dos objetos Cadena en un 3
{
	Cadena aux;
	aux.tam = tam + obj.tam - 1;
	aux.p = new char[aux.tam];
	if (aux.p == NULL)
		exit(1);
	strcpy(aux.p, p);
	strcat(aux.p, obj.p);
	return aux;
}

Cadena Cadena::operator+(const char* obj) // Para concatenar un objeto con una cadena
{
	Cadena aux;
	aux.tam = strlen(p) + strlen(obj) + 1;
	aux.p = new char[aux.tam];
	if (aux.p == NULL)
		exit(1);
	strcpy(aux.p, p);
	strcat(aux.p, obj);
	return aux;
}

//+=
void Cadena::operator+=(const char* obj) // Para concatenar un objeto con una cadena
{
	char* temp;
	temp = new char[tam];
	if (temp == NULL)
		exit(1);
	strcpy(temp, p);
	tam = tam + strlen(obj) + 1;
	delete p;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, temp);
	strcat(p, obj);
	delete temp;
}

void Cadena::operator+=(const Cadena& cad) // Para concatenar dos objetos cadena
{
	char* temp;
	temp = new char[tam];
	if (temp == NULL)
		exit(1);
	strcpy(temp, p);
	tam = tam + cad.tam - 1;
	delete p;
	p = new char[tam];
	if (p == NULL)
		exit(1);
	strcpy(p, temp);
	strcat(p, cad.p);
	delete temp;
}

// FUNCIONES AMIGAS PARA USAR CIN Y COUT
// NOTESE QUE DENTRO DE ESTAS FUNCIONES NO EXISTE this
// YA QUE NO SON FUNCIONES DE LAS CLASES
std::ostream& operator<<(std::ostream& salida, Cadena& obj)
{
	salida << obj.p;
	return salida;
}

std::istream& operator>>(std::istream& entrada, Cadena& obj)
{
	fflush(stdin);
	std::string palabra;
	// entrada >> palabra;
	int pos = 0;
	while (true)
	{
		palabra[pos] = std::cin.get();
		if (palabra[pos] == '\n')
		{
			break;
		}
		pos++;
	}
	palabra[pos] = '\0';
	delete obj.p;
	obj.tam = strlen(palabra.c_str()) + 1;
	obj.p = new char[obj.tam];
	strcpy(obj.p, palabra.c_str());
	fflush(stdin);
	return entrada;
}
