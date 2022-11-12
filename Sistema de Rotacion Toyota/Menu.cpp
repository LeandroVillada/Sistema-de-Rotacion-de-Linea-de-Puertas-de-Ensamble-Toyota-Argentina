#include "Menu.h"

bool Menu::crearOpciones()
{
    if (_opciones == nullptr)
    {
        _opciones = new std::string[_cantidadOpciones];
    }
    if (_opciones == nullptr)
    {
        exit(10);
        return false;
    }
    return true;
}

void Menu::resetColor()
{
    // ELEGIMOS EL COLOR DE FONDO QUE DESEAMOS
    rlutil::setBackgroundColor(_colorFondoPrincipal);
    // ELEGIMOS EL COLOR DEL TEXTO QUE DESEAMOS
    rlutil::setColor(_colorTextoPrincipal);
}

Menu::Menu()
{
    _cantidadOpciones = 2;
    _opciones = nullptr;
    _cursor = 1;
    _colorTextoPrincipal = rlutil::COLOR::WHITE;
    _colorFondoPrincipal = rlutil::COLOR::BLACK;
}

Menu::~Menu()
{
    if (_opciones != nullptr)
    {
        // delete _opciones;
    }
}

void Menu::setOpcion(int opcion, std::string texto)
{
    crearOpciones();
    if (opcion > _cantidadOpciones || opcion < 1)
    {
        exit(5);
        return;
    }
    _opciones[opcion] = texto;
}

std::string Menu::getOpcion(int pos)
{
    return _opciones[pos];
}

void Menu::setTitulo(std::string texto)
{
    crearOpciones();
    _opciones[0] = texto;
}

std::string Menu::getTitulo()
{
    return _opciones[0];
}

void Menu::setSalida(std::string texto)
{
    crearOpciones();
    _opciones[_cantidadOpciones - 1] = texto;
}

void Menu::setColorTextoPrincipal(short colorTexto)
{
    _colorTextoPrincipal = colorTexto;
}

void Menu::setColorFondoPrincipal(short colorFondo)
{
    _colorFondoPrincipal = colorFondo;
}

std::string Menu::getSalida()
{
    return _opciones[_cantidadOpciones - 1];
}

short Menu::getColorTextoPrincipal()
{
    return _colorTextoPrincipal;
}

short Menu::getColorFondoPrincipal()
{
    return _colorFondoPrincipal;
}

void Menu::agregarOpcion(std::string texto)
{
    std::string *pBuffer;
    pBuffer = new std::string[_cantidadOpciones + 1];

    // COPIAR TITULO
    pBuffer[0] = getTitulo();

    // COPIAR OPCIONES
    for (int i = 1; i <= _cantidadOpciones - 2; i++)
    {
        pBuffer[i] = _opciones[i];
    }

    // COPIAR NUEVA OPCION
    pBuffer[_cantidadOpciones - 1] = texto;

    // COPIAR MENSAJE DE SALIDA
    pBuffer[_cantidadOpciones] = getSalida();

    _opciones = pBuffer;

    _cantidadOpciones++;
}

int Menu::dibujarMenu(short colorTexto = 15, short colorFondo = 0)
{
    rlutil::hidecursor();
    bool dibujar = true;
    while (dibujar)
    {
        // TITULO
        rlutil::locate(39, 3);
        mostrarMensaje(getTitulo(), colorTexto, colorFondo);

        // OPCIONES
        int i;
        for (i = 1; i < _cantidadOpciones - 1; i++)
        {
            showItem(getOpcion(i), 21, (6 + i), _cursor == i, colorFondo);
        }

        // SALIDA
        // showItem(" SALIR ", 21, (8 + i), y == i);
        showItem(getSalida(), 21, (7 + i), _cursor == i, rlutil::COLOR::RED);

        switch (rlutil::getkey())
        {
        case rlutil::KEY_UP:
            _cursor--;
            if (_cursor < 1)
            {
                _cursor = _cantidadOpciones - 1;
                // y = 1;
            }
            break;
        case rlutil::KEY_DOWN:
            _cursor++;
            if (_cursor > (_cantidadOpciones - 1))
            {
                // y = (_cantidadOpciones - 1);
                _cursor = 1;
            }
            break;
        case rlutil::KEY_ENTER:
            dibujar = false;
            break;
        case rlutil::KEY_ESCAPE:
            _cursor = _cantidadOpciones - 1;
            showItem(getSalida(), 21, (7 + i), _cursor == i, rlutil::COLOR::RED);
            rlutil::showcursor();
            Menu::resetColor();
            return _cursor;
            break;
        }
    }
    rlutil::showcursor();
    Menu::resetColor();
    return _cursor;
}

int Menu::aclararBackground(int colorFondo)
{
    if (colorFondo > 0 && colorFondo < 6)
    {
        colorFondo += 8;
    }
    return colorFondo;
}

void Menu::showItem(const char *text, int posX, int posY, bool selected)
{
    if (selected)
    {
        rlutil::locate(posX - 2, posY);
        std::cout << (char)175;
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTRED);
        rlutil::locate(posX, posY);
        std::cout << text;
    }
    else
    {
        rlutil::locate(posX - 2, posY);
        std::cout << " ";
        rlutil::locate(posX, posY);
        std::cout << text;
    }
    Menu::resetColor();
}

void Menu::showItem(std::string text, int posX, int posY, bool selected, short colorFondo)
{
    if (selected)
    {
        rlutil::locate(posX - 2, posY);
        std::cout << (char)175;
        rlutil::setBackgroundColor(aclararBackground(colorFondo));
        rlutil::locate(posX, posY);
        std::cout << text;
    }
    else
    {
        rlutil::locate(posX - 2, posY);
        std::cout << " ";
        rlutil::locate(posX, posY);
        std::cout << text;
    }
    Menu::resetColor();
}

void Menu::mostrarMensaje(std::string mensaje, int color, int colorFondo)
{
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    std::cout << mensaje;
    Menu::resetColor();
}

void Menu::recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea = 15, short colorFondo = 11)
{
    setlocale(LC_ALL, "C");
    int i, j;
    for (i = iniX; i <= iniX + ancho; i++)
    {
        for (j = iniY; j <= iniY + alto; j++)
        {
            rlutil::locate(i, j);
            rlutil::setColor(colorLinea);
            rlutil::setBackgroundColor(colorFondo);
            // Arriba izquierda
            if (i == iniX && j == iniY)
            {
                cout << (char)201;
            }
            // Arriba derecha
            else if (i == iniX + ancho && j == iniY)
            {
                cout << (char)187;
            }
            // Abajo izquierda
            else if (i == iniX && j == iniY + alto)
            {
                cout << (char)200;
            }
            // Abajo derecha
            else if (i == iniX + ancho && j == iniY + alto)
            {
                cout << (char)188;
            }
            // Lineas arriba y abajo
            else if (j == iniY || j == iniY + alto)
            {
                cout << (char)205;
            }
            // Lineas izquierda y derecha
            else if (i == iniX || i == iniX + ancho)
            {
                cout << (char)186;
            }
            // Dentro del recuadro
            else
            {
                cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}

void Menu::separadorH(short iniX, short iniY, short ancho, short colorLinea = rlutil::WHITE, short colorFondo = rlutil::BLACK)
{
    setlocale(LC_ALL, "C");
    int i;
    rlutil::locate(iniX, iniY);
    cout << (char)204;
    for (i = 1; i < ancho; i++)
    {
        cout << (char)205;
    }
    cout << (char)185;
    // setlocale(LC_ALL, "spanish");
}

void Menu::separadorV(short iniX, short iniY, short alto, short colorLinea = rlutil::WHITE, short colorFondo = rlutil::BLACK)
{
    setlocale(LC_ALL, "C");
    int i;
    rlutil::locate(iniX, iniY);
    cout << (char)203;
    for (i = 1; i < alto; i++)
    {
        rlutil::locate(iniX, iniY + i);
        cout << (char)186;
    }
    rlutil::locate(iniX, iniY + alto);
    cout << (char)202;
    setlocale(LC_ALL, "spanish");
}

bool Menu::AjustarVentana(int Ancho, int Alto)
{
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
