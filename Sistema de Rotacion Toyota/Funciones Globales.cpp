#include "Funciones Globales.h"

void cargarCadenas(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = std::cin.get();
        if (pal[i] == '\n')
        {
            break;
        }
    }
    pal[i] = '\0';
    fflush(stdin);
}

void vectorEnCero(int *vector, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

void gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void mostrarMensaje(std::string mensaje, int color, int colorFondo)
{
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    std::cout << mensaje;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void confirmarSalida()
{
    char confirmarSalida;
    mostrarMensaje("Confirmar salida (S/N): ", 15, 4);
    // std::cout << endl;
    std::cin >> confirmarSalida;
    if (tolower(confirmarSalida) == 's')
    {
        return;
    }
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=15, short colorFondo=11){
    setlocale(LC_ALL, "C");
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            rlutil::locate(i, j);
            rlutil::setColor(colorLinea);
            rlutil::setBackgroundColor(colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                std::cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                std::cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                std::cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                std::cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                std::cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                std::cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                std::cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}

void separadorH(short iniX, short iniY, short ancho, short colorLinea=rlutil::WHITE, short colorFondo=rlutil::BLACK){
    setlocale(LC_ALL, "C");
    int i;
    rlutil::locate(iniX,iniY);
    std::cout<<(char)204;
    for(i=1; i<ancho; i++){
        std::cout<<(char)205;
    }
    std::cout<<(char)185;
    setlocale(LC_ALL, "spanish");
}

void separadorV(short iniX, short iniY, short alto, short colorLinea=rlutil::WHITE, short colorFondo=rlutil::BLACK){
    setlocale(LC_ALL, "C");
    int i;
    rlutil::locate(iniX,iniY);
    std::cout<<(char)203;
    for(i=1; i<alto; i++){
        rlutil::locate(iniX,iniY+i);
        std::cout<<(char)186;
    }
    rlutil::locate(iniX,iniY+alto);
    std::cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tama�o
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tama�o de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}