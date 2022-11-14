#include "HorasTrabajadas.h"
#include "EmpleadosArchivo.h"
#include "HorasTrabajadasArchivo.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// CONSTRUCTORES
HorasTrabajadas::HorasTrabajadas()
{
    _legajo = 0;
    _horasTrabajadas = 0;
}

// SETTS
void HorasTrabajadas::setLegajo(int legajo) { _legajo = legajo; }

void HorasTrabajadas::setHorasTrabajadas(float horas) { _horasTrabajadas = horas; }

void HorasTrabajadas::setFechaHoraTrabajadas(Fecha fecha){ fechaHoraTrabajadas=fecha; }

// GETTS
int HorasTrabajadas::getLegajo() { return _legajo; }

float HorasTrabajadas::getHorasTrabajadas() { return _horasTrabajadas; }

Fecha HorasTrabajadas::getFechaHoraTrabajadas(){return fechaHoraTrabajadas; }
int HorasTrabajadas::getSize()
{
    return sizeof * this;
}
// FUNCIONES PUBLICAS
/*
void HorasTrabajadas::Cargar() {
    Empleados reg;
    //cout << "Dia: ";
    cout << "Legajo: ";
    cin >> _legajo;
    if (reg.buscarLegajoExistente(_legajo)==true){
        setLegajo(_legajo);
        cin >> fechaHoraTrabajadas;
        //if(getFechaHoraTrabajada().getDia()!=dia){
            cout << "Horas Trabajadas: ";
            cin >> _horasTrabajadas;
            setHorasTrabajadas(_horasTrabajadas);
            cout<<endl;
        //}
        //else{
        //    cout<<"Las horas de ese dia ya fue cargado";
        //}

    }
    else{
        cout<<"El legajo ingresado no existe"<<endl;
    }
}
*/

void HorasTrabajadas::Mostrar()
{
    cout << "Legajo: ";
    cout << _legajo << endl;
    cout << fechaHoraTrabajadas;
    cout << "Horas Trabajadas: ";
    cout << _horasTrabajadas << endl
    << endl;
}
/*
bool HorasTrabajadas::grabarEnDisco()
{
    FILE *p;
    p = fopen("horasTrabajadas.dat", "ab");
    if (p == NULL)
        return -1;
    bool escribio;
    escribio = fwrite(this, sizeof(HorasTrabajadas), 1, p);
    fclose(p);
    return escribio;
}

bool HorasTrabajadas::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("horasTrabajadas.dat", "rb");
    if (p == NULL)
        return -1;
    fseek(p, sizeof(HorasTrabajadas) * pos, 0);
    bool leyo;
    leyo = fread(this, sizeof(HorasTrabajadas), 1, p);
    fclose(p);
    return leyo;
}
/*
int HorasTrabajadasArchivo::getCantidadRegistros()
{
  FILE* p;
  p = fopen("horasTrabajadas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(HorasTrabajadas);
  fclose(p);
  return cant;
}
*/
/*
void HorasTrabajadas::sumaHorasPorLegajo(int legajo)
{
    int pos = 0;
    float sumaHorasTrabajadas = 0;
    // int cantHoras = ht.getCantidadRegistros();
    // for (i = 0; i < cantHoras; i++) {
    // ht = htA.leer(i);
    while (leerDeDisco(pos++))
    {
        if (getLegajo() == legajo)
        {
            sumaHorasTrabajadas += getHorasTrabajadas();
        }
    }
    if (sumaHorasTrabajadas > 0)
    {
        cout << "Horas Trabajadas: " << sumaHorasTrabajadas;
    }
    else
    {
        cout << "No se registran horas";
    }
}
/*
void HorasTrabajadas::MostrarHoras(float cant){
    if(cant>0){
        cout<<"Horas Trabajadas: "<<cant;
    }
    else{
        cout<<"No se registran horas";
    }
}
*/
/*
void HorasTrabajadas::agregarRegistros()
{
    Empleados reg;
    EmpleadosArchivo archivo;
    // cout << "Dia: ";
    cout << "Legajo: ";
    cin >> _legajo;
    if (archivo.buscarLegajoExistente(_legajo) == true)
    {

        setLegajo(_legajo);

        cin >> fechaHoraTrabajadas;
        cout << "Horas Trabajadas: ";
        cin >> _horasTrabajadas;
        setHorasTrabajadas(_horasTrabajadas);
        cout << endl;

        grabarEnDisco();
    }
    else
    {
        cout << "El legajo ingresado no existe" << endl;
    }
}

void HorasTrabajadas::mostrarRegistros()
{
    int pos = 0;
    while (leerDeDisco(pos++))
    {
        Mostrar();
    }
}

void HorasTrabajadas::PromedioGeneral()
{
    float promedio = 0;
    int cant = 0, pos = 0;
    while (leerDeDisco(pos++))
    {
        promedio += getHorasTrabajadas();
        cant++;
    }
    cout << "Promedio General: " << promedio / cant << " horas";
}

void HorasTrabajadas::PromedioPorLegajo(int legajo)
{
    float promedio = 0;
    int cant = 0, pos = 0;
    while (leerDeDisco(pos++))
    {
        if (getLegajo() == legajo)
        {
            promedio += getHorasTrabajadas();
            cant++;
        }
    }
    cout << "Promedio del Legajo " << legajo << ": " << promedio / cant << " horas";
}

void HorasTrabajadas::PromedioPorLegajoYAnio(int legajo, int anio)
{
    float promedio = 0;
    int cant = 0, pos = 0;
    while (leerDeDisco(pos++))
    {
        if (getLegajo() == legajo && getFechaHoraTrabajada().getAnio() == anio)
        {
            promedio += getHorasTrabajadas();
            cant++;
        }
    }
    cout << "Promedio del Legajo " << legajo << " en el anio " << anio << ": " << promedio / cant << " horas";
}

void HorasTrabajadas::PromedioPorLegajoYMes(int legajo, int mes)
{
    float promedio = 0;
    int cant = 0, pos = 0;

    while (leerDeDisco(pos++))
    {
        if (getLegajo() == legajo && getFechaHoraTrabajada().getMes() == mes)
        {
            promedio += getHorasTrabajadas();
            cant++;
        }
    }
    cout << "Promedio del Legajo " << legajo << " en el mes " << mes << ": " << promedio / cant << " horas";
}

void HorasTrabajadas::mostrarRegistrosPorLegajo(int legajo)
{
    int pos = 0;
    while (leerDeDisco(pos++))
    {
        if (getLegajo() == legajo)
        {
            Mostrar();
        }
    }
}
*/
