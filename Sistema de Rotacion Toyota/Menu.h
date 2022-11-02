#pragma once
#include<iostream>
using std::cout;
using std::cin;
#include"rlutil.h"


class Menu
{
private:
	int _cantidadOpciones;
	std::string *_opciones;
	bool crearOpciones();
public:
	Menu();
	~Menu();
	// SETTERS
	void setOpcion(int opcion, std::string texto);
	void setTitulo(std::string texto);
	void setSalida(std::string texto);

	// GETTERS
	std::string getOpcion(int pos);
	std::string getTitulo();
	std::string getSalida();

	void agregarOpcion(std::string);
	int dibujarMenu(short colorTexto, short colorFondo);
	int aclararBackground(int colorFondo);

	void showItem(const char* text, int posX, int posY, bool selected);
	void showItem(std::string text, int posX, int posY, bool selected, short colorFondo);
	void mostrarMensaje(std::string mensaje, int color, int colorFondo);
	
	void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo);
	void separadorH(short iniX, short iniY, short ancho, short colorLinea, short colorFondo);
	void separadorV(short iniX, short iniY, short alto, short colorLinea, short colorFondo);
	bool AjustarVentana(int Ancho, int Alto);
};

