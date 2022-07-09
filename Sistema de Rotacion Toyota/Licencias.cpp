#include "Empleados.h"
#include "Fecha.h"
#include "Licencias.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


bool Licencias::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("Licencias.dat", "rb");
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

bool Licencias::grabarEnDisco()
{
    FILE *p;
    p = fopen("Licencias.dat", "ab");
    bool grabo;
    if (p == NULL)
    {
        return false;
    }
    grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

bool Licencias::modificarEnDisco(int pos)
{
    FILE *p;
    p = fopen("Licencias.dat", "rb+");
    if (p == NULL)
    {
        puts("NO SE PUDO ABRIR EL ARCHIVO");
        return false;
    }
    fseek(p, sizeof *this * pos, 0);
    bool leyo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

void licencia(){
    Empleados reg;
    Licencias lic;
    Fecha(9,7,22);
    int legajo, desde, hasta, mesD, mesH;
    std::cout << "Ingresar el Legajo: ";
    std::cin >> legajo;
    if (reg.buscarLegajoExistente(legajo)==false)
    {
        std::cout << "El legajo ingresado no existe." << std::endl;
        return;
    }
    if (reg.LegajoDisponible(legajo)==false)
    {
        std::cout << "El legajo ingresado ya se encuentra con licencia." << std::endl;
        return;
    }
    std::cout << "Ingresar Fecha Desde: ";
    std::cin >> desde;
    /*std::cout << "Ingresar Fecha Hasta: ";
    std::cin >> hasta;*/
    std::cout << "Ingresar Fecha Mes desde: ";
    std::cin >> mesD;
    /*std::cout << "Ingresar Fecha Mes hasta: ";
    std::cin >> mesH;*/

    ///NO ANDA ESTA PARTE POR EL MOMENTO//////////////////////////////////////////////
/*
    if(lic.getFechaInicioLicencia().getDia()==desde && lic.getFechaInicioLicencia().getMes()==mesD){
        int pos = reg.buscarPosicionLegajo(legajo);
        lic.leerDeDisco(pos);
        lic.setDisponibilidad(false);
        lic.modificarEnDisco(pos);
    }
*/
}

