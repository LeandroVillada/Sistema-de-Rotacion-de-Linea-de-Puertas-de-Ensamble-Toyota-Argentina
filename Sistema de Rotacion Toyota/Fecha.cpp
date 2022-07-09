#include "Fecha.h"
// COSNTRUCTORES
Fecha::Fecha()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    _anio = now->tm_year + 1900;
    _mes = now->tm_mon + 1;
    _dia = now->tm_mday;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
// FUNCIONES PRIVADAS
bool Fecha::esbisiesto(int a)
{
    bool bisiesto = false;
    if (a % 4 == 0)
    {
        bisiesto = true;
    }
    if ((a % 100 == 0) && (a % 400 != 0))
    {
        bisiesto = false;
    }
    return bisiesto;
}
void Fecha::NumeroSerieaFecha(int ns)
{
    int suma = 0, dia_adicional, suma_ant{};
    int anio_real = 1900;
    while (ns > suma)
    {
        dia_adicional = (esbisiesto(anio_real) ? 1 : 0);
        suma_ant = suma;
        suma += 365 + dia_adicional;
        anio_real++;
    }
    _anio = anio_real - 1;
    // Cantidad de dias pasados desde anio
    int dias_anio_actual = ns - suma_ant, i = 0;
    int vmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esbisiesto(_anio))
        vmes[1] = 29;
    suma = 0;
    while (dias_anio_actual > suma)
        suma += vmes[i++];
    _mes = i;
    _dia = dias_anio_actual - (suma - vmes[i - 1]);
}
/*
void Fecha::FechaHora(int hora){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    hora = timeinfo.tm_hour;
}
*/

// SETTERS
void Fecha::setDia(int d) { _dia = d; }
void Fecha::setMes(int m) { _mes = m; }
void Fecha::setAnio(int a) { _anio = a; }
//void Fecha::setHora(int h) {hora=h;}
// GETTERS
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }
//int Fecha::getHora() {return hora;}
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
int Fecha::operator==(const char *diaSemana)
{
    int cantdias = NumeroSerie() - 1; // cantidad de dias transcurridos desde 01/01/1900
    // El 01/01/1900 fue Lunes
    int numerodia = cantdias % 7;

    char mdia[7][10];
    strcpy(mdia[0], "Lunes");
    strcpy(mdia[1], "Martes");
    strcpy(mdia[2], "Miercoles");
    strcpy(mdia[3], "Jueves");
    strcpy(mdia[4], "Viernes");
    strcpy(mdia[5], "Sabado");
    strcpy(mdia[6], "Domingo");
    if (strcmp(mdia[numerodia], diaSemana) == 0)
        return 1;
    return 0;
}
istream &operator>>(istream &entra, Fecha &f)
{
    std::cout << "DIA: ";
    entra >> f._dia;
    std::cout << "MES: ";
    entra >> f._mes;
    std::cout << "ANIO: ";
    entra >> f._anio;
    return entra;
}
ostream &operator<<(ostream &sale, Fecha &f)
{
    std::cout << "DIA: ";
    sale << f._dia << endl;
    std::cout << "MES: ";
    sale << f._mes << endl;
    std::cout << "ANIO: ";
    sale << f._anio << endl;
    return sale;
}
Fecha Fecha::operator+(int masdias)
{
  Fecha aux;
  int ns = NumeroSerie() + masdias;
  aux.NumeroSerieaFecha(ns);
  return aux;
}
void Fecha::operator+=(int masdias)
{
  int ns = NumeroSerie() + masdias;
  NumeroSerieaFecha(ns);
}
int Fecha::operator-(Fecha &obj)
{
  return NumeroSerie() - obj.NumeroSerie();
}
int Fecha::cantDiasMes()
{
  int vmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (esbisiesto(_anio))
    vmes[1] = 29;
  return vmes[_mes - 1];
}


// FUNCIONES
int Fecha::NumeroSerie() // Devuelve la cantidad de dias transcurridos desde el 01/01/1900
{
    int cont = 0, i;
    for (i = 1900; i < _anio; i++)
        if (esbisiesto(i))
            cont++;
    int vmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, suma = 0;
    if (esbisiesto(_anio))
        vmes[1] = 29;
    for (int i = 0; i < _mes - 1; i++)
        suma += vmes[i];
    int cantdias = (_anio - 1900) * 365 + cont + suma + _dia;
    return cantdias;
}
int Fecha::cantDiasHabilesMes()
{
  int totDias = cantDiasMes();
  int dia, cant = 0;
  Fecha aux = *this;
  for (int i = 1; i <= totDias; i++)
  {
    dia = (aux.NumeroSerie() - 1) % 7;
    if (dia < 5)
      cant++;
    aux += 1;
  }
  return cant;
}
int Fecha::cantAniosHastaHoy()
{
  Fecha aux; // por usar un constructor por defecto tiene la fecha de hoy;
  int cant = aux._anio - _anio;
  if (_mes > aux._mes)
    return cant - 1;
  if (_mes == aux._mes && _dia > aux._dia)
    return cant - 1;
  return cant;
}
bool Fecha::validarFecha()
{
    int dia_maximo = 0;
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
            dia_maximo = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dia_maximo = 30;
            break;
        case 2:
            if (((_anio % 4 == 0) && (_anio % 100 != 0)) || (_anio % 400 == 0))
            {
                dia_maximo = 29;
            }
            else
            {
                dia_maximo = 28;
            }
            break;
        }
        if (_dia >= 1 && _dia <= dia_maximo)
        {
            return true;
        }
    }
    return false;
}
void Fecha::MostrarFecha()
{
    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}
void Fecha::MostrarFechaTexto()
{
    char mmes[12][11];
    strcpy(mmes[0], "Enero");
    strcpy(mmes[1], "Febrero");
    strcpy(mmes[2], "Marzo");
    strcpy(mmes[3], "Abril");
    strcpy(mmes[4], "Mayo");
    strcpy(mmes[5], "Junio");
    strcpy(mmes[6], "Julio");
    strcpy(mmes[7], "Agosto");
    strcpy(mmes[8], "Septiembre");
    strcpy(mmes[9], "Octubre");
    strcpy(mmes[10], "Noviembre");
    strcpy(mmes[11], "Diciembre");

    int cantdias = NumeroSerie() - 1; // cantidad de dias transcurridos desde 01/01/1900
    // El 01/01/1900 fue Lunes
    int numerodia = cantdias % 7;

    char mdia[7][10];
    strcpy(mdia[0], "Lunes");
    strcpy(mdia[1], "Martes");
    strcpy(mdia[2], "Miercoles");
    strcpy(mdia[3], "Jueves");
    strcpy(mdia[4], "Viernes");
    strcpy(mdia[5], "Sabado");
    strcpy(mdia[6], "Domingo");

    cout << endl
         << mdia[numerodia] << " " << _dia << " de " << mmes[_mes - 1] << " de " << _anio << endl;
}
