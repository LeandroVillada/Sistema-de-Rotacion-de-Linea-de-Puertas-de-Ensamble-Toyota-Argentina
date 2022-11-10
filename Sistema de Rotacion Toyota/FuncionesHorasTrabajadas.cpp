#include <iostream>
#include <cstring>
using namespace std;

#include "FuncionesHorasTrabajadas.h"
#include "Empleados.h"
#include "EmpleadosArchivo.h"


void sumaHorasPorLegajo(int legajo)
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    int i;
    float sumaHorasTrabajadas = 0;

    for (i = 0; i < cant; i++) {
        if (ht[i].getLegajo() == legajo)
        {
            sumaHorasTrabajadas += ht[i].getHorasTrabajadas();
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

void agregarRegistros()
{
    EmpleadosArchivo archivo;
    HorasTrabajadasArchivo archivoHT;
    HorasTrabajadas ht;

    int _legajo, _horasTrabajadas;
    Fecha fechaHorasTrabajadas;
    cout << "Legajo: ";
    cin >> _legajo;
    if (archivo.buscarLegajoExistente(_legajo) == true)
    {

        ht.setLegajo(_legajo);

        cin>>fechaHorasTrabajadas;
        ht.setFechaHoraTrabajadas(fechaHorasTrabajadas);

        cout << "Horas Trabajadas: ";
        cin >> _horasTrabajadas;
        ht.setHorasTrabajadas(_horasTrabajadas);
        cout << endl;

        archivoHT.guardar(ht);
    }
    else
    {
        cout << "El legajo ingresado no existe" << endl;
        system("pause");
    }
}

void mostrarRegistros()
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);
    int i;
    for (i = 0; i < cant; i++)
    {
        ht[i].Mostrar();
    }
}

void promedioGeneral()
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    float promedio = 0;
    int cantP = 0, i;

    for (i = 0; i < cant; i++)
    {
        promedio += ht[i].getHorasTrabajadas();
        cantP++;
    }
    cout << "Promedio General: " << promedio / cantP << " horas";
}

void promedioPorLegajo(int legajo)
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    float promedio = 0;
    int cantP = 0, i;
    for (i = 0; i < cant; i++)
    {
        if (ht[i].getLegajo() == legajo)
        {
            promedio += ht[i].getHorasTrabajadas();
            cantP++;
        }
    }
    cout << "Promedio del Legajo " << legajo << ": " << promedio / cantP << " horas";
}

void promedioPorLegajoYAnio(int legajo, int anio)
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    float promedio = 0;
    int cantP = 0, i;
    for (i = 0; i < cant; i++)
    {
        if (ht[i].getLegajo() == legajo && ht[i].getFechaHoraTrabajadas().getAnio() == anio)
        {
            promedio += ht[i].getHorasTrabajadas();
            cantP++;
        }
    }
    cout << "Promedio del Legajo " << legajo << " en el anio " << anio << ": " << promedio / cantP << " horas";
}

void promedioPorLegajoYMes(int legajo, int mes)
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    float promedio = 0;
    int cantP = 0, i;

    for (i = 0; i < cant; i++)
    {
        if (ht[i].getLegajo() == legajo && ht[i].getFechaHoraTrabajadas().getMes() == mes)
        {
            promedio += ht[i].getHorasTrabajadas();
            cantP++;
        }
    }
    cout << "Promedio del Legajo " << legajo << " en el mes " << mes << ": " << promedio / cantP << " horas";
}

void mostrarRegistrosPorLegajo(int legajo)
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);

    int i;
    for (i = 0; i < cant; i++)
    {
        if (ht[i].getLegajo() == legajo){
            ht[i].Mostrar();
        }
    }
}
/*
TENGO QUE TRATAR DE QUE ANDE!
IDEA: SACAR EL LEGAJO CON MENOS HORAS TRABAJADAS
int minCantHoras(HorasTrabajadas *v, int tam)
{
    int posMin=0, i;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]){
            posMin=i;
        }
    }
    return posMin;
}

void mostrarElMenorHorasLegajo()
{
    HorasTrabajadasArchivo archivoHT;
    int cant= archivoHT.getCantidad();
    HorasTrabajadas* ht=new HorasTrabajadas[cant];
    archivoHT.leerTodos(ht,cant);
    int i;
    float cantH=0;
    for (i = 0; i < cant; i++)
    {
        cantH+=ht[i].getHorasTrabajadas();
        ht[cantH];
    }

    cout<<"El legajo con menor horas trabajadas en los registros es: "<<minCantHoras(ht,cant)+1;
}
*/
