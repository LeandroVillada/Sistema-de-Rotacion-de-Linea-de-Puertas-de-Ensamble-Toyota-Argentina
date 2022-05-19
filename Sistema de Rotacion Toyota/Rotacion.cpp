#include "Rotacion.h"

// FUNCIONES ARCHIVOS

bool Rotacion::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("Rotacion.dat", "rb");
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
bool Rotacion::grabarEnDisco()
{
    FILE *p;
    p = fopen("Rotacion.dat", "ab");
    bool grabo;
    if (p == NULL)
    {
        return false;
    }
    grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
bool Rotacion::modificarEnDisco(int pos)
{
    FILE *p;
    p = fopen("Rotacion.dat", "rb+");
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
int Rotacion::cantidadRegistros()
{
    int cantidad = 0;
    while (leerDeDisco(cantidad++))
    {
    }
    return cantidad - 1;
}
bool Rotacion::grabarEnBackUp()
{
    FILE *p;
    p = fopen("Rotacion.bkp", "wb");
    if (p == NULL)
        return false;
    Rotacion reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (fwrite(&reg, sizeof reg, 1, p) == 0)
        {
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}
bool Rotacion::restaurarBackUP()
{
    FILE *p;
    p = fopen("Rotacion.dat", "wb");
    if (p == NULL)
        return false;
    Rotacion reg;
    fclose(p);
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (!reg.grabarEnDisco())
        {
            return false;
        }
    }
    return true;
}
bool Rotacion::exportar() //Esto no sirve para imprimir. para que funcione hay que hacer una funcion externa a la clase con la libreria fstream.
{
    FILE *p;
    p = fopen("Rotacion.txt", "wb");
    if (p == NULL)
        return false;
    Rotacion reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (fwrite(&reg, sizeof reg, 1, p) == 0)
        {
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}