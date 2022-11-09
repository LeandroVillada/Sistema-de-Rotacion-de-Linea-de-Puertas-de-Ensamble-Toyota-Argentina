#include "EmpleadosArchivo.h"
#include <cstring>
Empleados EmpleadosArchivo::leer(int nroRegistro)
{
    Empleados est;
    FILE *pFile = abrirArchivoRB();

    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    fread(&est, sizeof(Empleados), 1, pFile);
    fclose(pFile);
    return est;
}

bool EmpleadosArchivo::leer(Empleados &empleado, int nroRegistro)
{
    FILE *pFile = abrirArchivoRB();

    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    fread(&empleado, sizeof(Empleados), 1, pFile);
    fclose(pFile);
    return true;
}

bool EmpleadosArchivo::leerTodos(Empleados clases[], int cantidad)
{
    FILE *pFile = abrirArchivoRB();

    fread(clases, sizeof(Empleados), cantidad, pFile);
    fclose(pFile);
    return true;
}

bool EmpleadosArchivo::guardar(Empleados clase)
{
    FILE *pFile = fopen("Empleados.dat", "ab");
    if (pFile == NULL)
    {
        return false;
    }
    bool ok = fwrite(&clase, sizeof(Empleados), 1, pFile);
    fclose(pFile);
    return ok;
}

bool EmpleadosArchivo::guardar(Empleados clase, int nroRegistro)
{
    FILE *pFile = fopen("Empleados.dat", "rb+");
    if (pFile == NULL)
    {
        return false;
    }
    fseek(pFile, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool ok = fwrite(&clase, sizeof(Empleados), 1, pFile);
    fclose(pFile);
    return ok;
}

int EmpleadosArchivo::getCantidad()
{
    FILE *pFile = abrirArchivoRB();

    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Empleados);
    fclose(pFile);
    return cant;
}

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

int EmpleadosArchivo::buscarPosicionEmpleadoPorLegajo(int legajo)
{
    EmpleadosArchivo Archivo;
    int cantidad = Archivo.getCantidad();
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
    int cantidad = Archivo.getCantidad();
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
    int cantidad = Archivo.getCantidad();
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
    int cantidad = Archivo.getCantidad();
    Empleados* empleado = new Empleados[cantidad];
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
