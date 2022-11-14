#include "HorasTrabajadasArchivo.h"
#include <cstring>

int HorasTrabajadasArchivo::cantidadRegistros()
{
    if (!abrirArchivo(SoloLectura))
    {
        estado = Cerrado;
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    long cant = ftell(pFile) / tamanioRegistro;
    cerrarArchivo();
    return (int)cant;
}

bool HorasTrabajadasArchivo::abrirArchivo(Modo modo)
{
    switch (estado)
    {
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:
        cerrarArchivo();
        break;
    }
    switch (modo)
    {
    case SoloLectura:
        pFile = fopen(nombreArchivo, "rb");
        if (!pFile)
            return false;
        estado = AbiertoR;
        break;
    case Escritura:
        pFile = fopen(nombreArchivo, "wb");
        if (!pFile)
            return false;
        estado = AbiertoW;
        break;
    case Agregar:
        pFile = fopen(nombreArchivo, "ab");
        if (!pFile)
            return false;
        estado = AbiertoA;
        break;
    case LecturaEscritura:
        pFile = fopen(nombreArchivo, "rb+");
        if (!pFile)
            return false;
        estado = AbiertoRW;
        break;
    }
    return true;
}

void HorasTrabajadasArchivo::cerrarArchivo()
{
    fclose(pFile);
    estado = Cerrado;
}

HorasTrabajadasArchivo::HorasTrabajadasArchivo()
{
    HorasTrabajadas registro;
    // Nombre para guardar o abrir los registros
    std::string nombre = "horasTrabajadas.dat";
    nombreArchivo = new char[strlen(nombre.c_str()) + 1];
    if (nombreArchivo == NULL)
    {
        exit(1);
    }
    strcpy(nombreArchivo, nombre.c_str());

    tamanioRegistro = registro.getSize();
    pRegistro = (void *)malloc(tamanioRegistro);
    cantRegistros = cantidadRegistros();
    estado = Cerrado;
}

HorasTrabajadasArchivo::~HorasTrabajadasArchivo()
{
    delete nombreArchivo;
    if (pFile)
    {
        fclose(pFile);
    }
    free(pRegistro);
}

HorasTrabajadas HorasTrabajadasArchivo::leer(int nroRegistro)
{
    HorasTrabajadas obj{};
    if (!abrirArchivo(SoloLectura))
    {
        return obj;
    }

    fseek(pFile, nroRegistro * obj.getSize(), SEEK_SET);
    fread(&obj, obj.getSize(), 1, pFile);
    cerrarArchivo();
    return obj;
}

bool HorasTrabajadasArchivo::leer(HorasTrabajadas &horasTrabajadas, int nroRegistro)
{
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    fseek(pFile, nroRegistro * horasTrabajadas.getSize(), SEEK_SET);
    bool ok = fread(&horasTrabajadas, horasTrabajadas.getSize(), 1, pFile);
    cerrarArchivo();
    return ok;
}

bool HorasTrabajadasArchivo::leerTodos(HorasTrabajadas horasTrabajadas[], int cantidad)
{
    if (cantRegistros == 0)
    {
        return false;
    }
    if (!abrirArchivo(SoloLectura))
    {
        return false;
    }

    bool ok = fread(horasTrabajadas, horasTrabajadas[0].getSize(), cantidad, pFile);
    cerrarArchivo();
    return ok;
}

bool HorasTrabajadasArchivo::guardar(HorasTrabajadas horasTrabajadas)
{
    if (!abrirArchivo(Agregar))
    {
        return false;
    }
    bool ok = fwrite(&horasTrabajadas, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return ok;
}

bool HorasTrabajadasArchivo::guardar(HorasTrabajadas obj, int nroRegistro)
{
    if (!abrirArchivo(LecturaEscritura))
    {
        return false;
    }
    fseek(pFile, nroRegistro * sizeof(HorasTrabajadas), SEEK_SET);
    bool ok = fwrite(&obj, sizeof(HorasTrabajadas), 1, pFile);
    fclose(pFile);
    return ok;
}

int HorasTrabajadasArchivo::getCantidadRegistros()
{
    return cantRegistros;
}

int HorasTrabajadasArchivo::buscarPorLegajo(int legajo)
{
    HorasTrabajadas *aux = new HorasTrabajadas[cantRegistros];
    for (int i = 0; i < cantRegistros; i++)
    {
        if (aux[i].getLegajo() == legajo)
        {
            return i;
        }
    }
    return -1;
}
