#include "EmpleadosArchivo.h"
#include <cstring>
int EmpleadosArchivo::cantidadRegistros()
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

// abrirArchivo(Modo modo)
// ABRE EL ARCHIVO EN EL MODO ESTABLECIDO POR EL PARAMETRO modo.
// DEVUELVE TRUE SI PUDO ABRIR Y FALSE SI NO PUDO ABRIR
bool EmpleadosArchivo::abrirArchivo(Modo modo)
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

void EmpleadosArchivo::cerrarArchivo()
{
    fclose(pFile);
    estado = Cerrado;
}

EmpleadosArchivo::EmpleadosArchivo()
{
    Empleados registro;
    // Nombre para guardar o abrir los registros
    std::string nombre = "Empleados.dat";
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

EmpleadosArchivo::~EmpleadosArchivo()
{
    delete nombreArchivo;
    if (pFile)
    {
        fclose(pFile);
    }
    free(pRegistro);
}

Empleados EmpleadosArchivo::leer(int nroRegistro)
{
    // FILE *pFile = abrirArchivoRB();
    abrirArchivo(SoloLectura);
    
    Empleados obj;

    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    fread(&obj, sizeof(Empleados), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return obj;
}

bool EmpleadosArchivo::leer(Empleados &empleado, int nroRegistro)
{
    // FILE *pFile = abrirArchivoRB();
    abrirArchivo(SoloLectura);

    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool ok = fread(&empleado, sizeof(Empleados), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

bool EmpleadosArchivo::leerTodos(Empleados clases[], int cantidad)
{
    // FILE *pFile = abrirArchivoRB();
    abrirArchivo(SoloLectura);

    bool ok = fread(clases, sizeof(Empleados), cantidad, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

bool EmpleadosArchivo::guardar(Empleados clase)
{
    // FILE *pFile = fopen("Empleados.dat", "ab");
    // if (pFile == NULL)
    // {
    //     return false;
    // }

    abrirArchivo(Agregar);
    bool ok = fwrite(&clase, sizeof(Empleados), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

bool EmpleadosArchivo::guardar(Empleados clase, int nroRegistro)
{
    // FILE *pFile = fopen("Empleados.dat", "rb+");
    // if (pFile == NULL)
    // {
    //     return false;
    // }
    
    abrirArchivo(LecturaEscritura);
    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool ok = fwrite(&clase, sizeof(Empleados), 1, pFile);
    // fclose(pFile);
    cerrarArchivo();
    return ok;
}

int EmpleadosArchivo::getCantidadRegistros()
{
    // FILE *pFile = abrirArchivoRB();

    // fseek(pFile, 0, SEEK_END);
    // int cant = ftell(pFile) / sizeof(Empleados);
    // fclose(pFile);
    // return cant;
    
    return cantRegistros;
}
/* 
FILE *EmpleadosArchivo::abrirArchivoRB()
{
    FILE *pFile;
    pFile = fopen("Empleados.dat", "rb");
    if (pFile == NULL)
    {
        exit(1550);
    }
    return pFile;
}
 */
int EmpleadosArchivo::buscarPosicionEmpleadoPorLegajo(int legajo)
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *empleado = new Empleados[cantidad];
    Archivo.leerTodos(empleado, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (legajo == empleado[i].getLegajo())
        {
            return i;
        }
    }
    return -1;
}

Empleados EmpleadosArchivo::buscarEmpleadoPorLegajo(int legajo)
{
    Empleados aux;
    leer(aux, buscarPosicionEmpleadoPorLegajo(legajo));
    return aux;
}

int EmpleadosArchivo::BuscarPor(std::string codigo)
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *clase = new Empleados[cantidad];
    Archivo.leerTodos(clase, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(codigo.c_str(), clase[i].getNombre().c_str()) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool EmpleadosArchivo::bajaLogica()
{
    cout << "NUMERO DE LEGAJO A DAR DE BAJA: ";
    int numero;
    cin >> numero;
    int pos = buscarPosicionEmpleadoPorLegajo(numero);
    if (pos == -1)
    {
        cout << "NUMERO DE LEGAJO NO EXISTE.\n";
        return false;
    }
    Empleados registroModificado;
    leer(registroModificado, pos);
    registroModificado.setEstado(false);
    if (guardar(registroModificado, pos))
    {
        return false;
    }
    return true;
}

bool EmpleadosArchivo::modificar()
{
    int _numero = 1;
    int pos = buscarPosicionEmpleadoPorLegajo(_numero);
    if (pos == -1)
    {
        cout << "NUMERO DE LEGAJO NO EXISTE.\n";
        return false;
    }
    Empleados registroModificado;
    leer(registroModificado, pos);
    // MODIFICAR
    if (guardar(registroModificado, pos))
    {
        return false;
    }
    return true;
}

void EmpleadosArchivo::mostrar(Empleados registro)
{
    cout << registro.toString();
}

void EmpleadosArchivo::mostrarArchivo()
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *clase = new Empleados[cantidad];
    Archivo.leerTodos(clase, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        cout << clase[i].toString() << endl;
        cout << endl;
    }
}

// FUNCIONES PUBLICAS
bool EmpleadosArchivo::buscarLegajoExistente(int legajo)
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidadRegistros();
    Empleados *empleado = new Empleados[cantidad];
    Archivo.leerTodos(empleado, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (legajo == empleado[i].getLegajo())
        {
            return true;
        }
    }
    return false;
}
bool EmpleadosArchivo::LegajoDisponible(int legajo)
{
    EmpleadosArchivo Archivo;
    Empleados reg;
    int pos = buscarPosicionEmpleadoPorLegajo(legajo);
    leer(reg, pos);
    if ((reg.getEstado()) && (reg.getDisponibilidad()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool EmpleadosArchivo::buscarLegajoInactivo(int legajo)
{
    EmpleadosArchivo Archivo;
    Empleados reg;
    int pos = buscarPosicionEmpleadoPorLegajo(legajo);
    leer(reg, pos);
    if (!reg.getEstado())
        return true;
    else
        return false;
}