#include "Fecha.h"
#include <iostream>
// COSNTRUCTORES
Fecha::Fecha()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    _anio = now->tm_year + 1900;
    _mes = now->tm_mon + 1;
    _dia = now->tm_mday;
    _fecha_correcta = true;
    _dia_maximo = 0;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
    _fecha_correcta = true;
    _dia_maximo = 0;
}
// SETTERS
void Fecha::setDia(int d) { _dia = d; }
void Fecha::setMes(int m) { _mes = m; }
void Fecha::setAnio(int a) { _anio = a; }
// GETTERS
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }
// OPERADORES
void Fecha::operator=(Fecha aux)
{
    _anio = aux._anio;
    _mes = aux._mes;
    _dia = aux._dia;
}
bool Fecha::operator==(Fecha aux)
{
    if (_anio != aux._anio)
        return false;
    if (_mes != aux._mes)
        return false;
    if (_dia != aux._dia)
        return false;
    return true;
}
bool Fecha::operator!=(Fecha aux)
{
    if (_anio == aux._anio)
        return false;
    if (_mes == aux._mes)
        return false;
    if (_dia == aux._dia)
        return false;
    return true;
}
bool Fecha::operator>(Fecha aux)
{
    if (_anio < aux._anio)
        return false;
    if (_mes < aux._mes)
        return false;
    if (_dia < aux._dia)
        return false;
    return true;
}
bool Fecha::operator<(Fecha aux)
{
    if (_anio > aux._anio)
        return false;
    if (_mes > aux._mes)
        return false;
    if (_dia > aux._dia)
        return false;
    return true;
}
// FUNCIONES
bool Fecha::Cargar()
{
    std::cout << "DIA: ";
    std::cin >> _dia;
    std::cout << "MES: ";
    std::cin >> _mes;
    std::cout << "ANIO: ";
    std::cin >> _anio;
    if (_mes >= 1 && _mes <= 12)
    {
        switch (_mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            _dia_maximo = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            _dia_maximo = 30;
            break;
        case 2:
            if (((_anio % 4 == 0) && (_anio % 100 != 0)) || (_anio % 400 == 0))
            {
                _dia_maximo = 29;
            }
            else
            {
                _dia_maximo = 28;
            }
            break;
        }
        if (_dia >= 1 && _dia <= _dia_maximo)
        {
            _fecha_correcta = 1;
        }
    }
    return _fecha_correcta;
}
void Fecha::Mostrar()
{
    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}