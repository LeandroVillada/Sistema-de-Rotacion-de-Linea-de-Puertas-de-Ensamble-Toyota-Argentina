#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

void cargarCadenas(char *pal, int tam);

class Fecha
{
private:
    int dia, mes, anio, dia_maximo;
    bool fecha_correcta;

public:
    Fecha()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        anio = now->tm_year + 1900;
        mes = now->tm_mon + 1;
        dia = now->tm_mday;
        fecha_correcta = false;
    }
    bool Cargar()
    {
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;
        if (mes >= 1 && mes <= 12)
        {
            switch (mes)
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
                if (((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0))
                {
                    dia_maximo = 29;
                }
                else
                {
                    dia_maximo = 28;
                }
                break;
            }
            if (dia >= 1 && dia <= dia_maximo)
            {
                fecha_correcta = 1;
            }
        }
        return fecha_correcta;
    }
    void Mostrar()
    {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
    // Sets
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAnio(int a) { anio = a; }
    // Gets
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
    // OPERADOR
    void operator=(Fecha aux)
    {
        anio = aux.anio;
        mes = aux.mes;
        dia = aux.dia;
    }
    bool operator==(Fecha aux)
    {
        if (anio != aux.anio)
            return false;
        if (mes != aux.mes)
            return false;
        if (dia != aux.dia)
            return false;
        return true;
    }
    bool operator!=(Fecha aux)
    {
        if (anio == aux.anio)
            return false;
        if (mes == aux.mes)
            return false;
        if (dia == aux.dia)
            return false;
        return true;
    }
    bool operator>(Fecha aux)
    {
        if (anio < aux.anio)
            return false;
        if (mes < aux.mes)
            return false;
        if (dia < aux.dia)
            return false;
        return true;
    }
    bool operator<(Fecha aux)
    {
        if (anio > aux.anio)
            return false;
        if (mes > aux.mes)
            return false;
        if (dia > aux.dia)
            return false;
        return true;
    }
};

class Empleados
{
private:
    int legajo;
    char nombreEmpleado[60];
    char apellidoEmpleado[60];
    bool estado;
    bool disponibilidad;
    int operacionesaprendidas [26];
    // Direccion direccion;

public:
    Empleados(int legajo = 0, const char *nombreEmpleado = "NO INGRESADO", const char *apellidoEmpleado = "NO INGRESADO")
    {

        if (legajo != 0)
            this->legajo = legajo;
        else
            this->legajo = cantidadRegistros();
        strcpy(this->nombreEmpleado, nombreEmpleado);
        strcpy(this->apellidoEmpleado, apellidoEmpleado);
        estado = true;
    }
    // ~Empleados() {}
    // FUNCIONES ARCHIVOS
    bool leerDeDisco(int pos)
    {
        FILE *p;
        p = fopen("Empleados.dat", "rb");
        bool leyo;
        if (p == NULL)
        {
            cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
            return false;
        }
        fseek(p, pos * sizeof *this, 0);
        leyo = fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
    }
    bool grabarEnDisco()
    {
        FILE *p;
        p = fopen("Empleados.dat", "ab");
        bool grabo;
        if (p == NULL)
        {
            return false;
        }
        grabo = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return grabo;
    }
    bool modificarEnDisco(int pos)
    {
        FILE *p;
        p = fopen("Empleados.dat", "rb+");
        if (p == NULL)
        {
            cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
            return false;
        }
        fseek(p, sizeof *this * pos, 0);

        bool leyo = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
    }
    int cantidadRegistros()
    {
        int cantidad = 0;
        while (leerDeDisco(cantidad++))
        {
        }
        return cantidad - 1;
    }
    void crearArchivo()
    {
        FILE *p;
        p = fopen("Empleados.dat", "wb");
        fclose(p);
    }
    // SETS
    void set_legajo(int legajo) { this->legajo = legajo; }
    void set_nombreEmpleado(const char *nombre) { strcpy(nombreEmpleado, nombre); }
    void set_apellidoEmpleado(const char *apellido) { strcpy(apellidoEmpleado, apellido); }
    void set_estado(bool estado) { this->estado = estado; }
    // void set_direccion(Direccion direccion) { this->direccion = direccion; }
    // GETS
    int get_legajo() { return legajo; }
    const char *get_nombreEmpleado() { return nombreEmpleado; }
    const char *get_apellidoEmpleado() { return apellidoEmpleado; }
    bool get_estado() { return estado; }
    // Direccion get_direccion() { return direccion; }
    // FUNCIONES
    bool cargar()
    {
        cout << "LEGAJO: ";
        cin >> legajo;
        if (buscarLegajoExistente(legajo))
        {
            puts("ESE LEGAJO YA EXISTE.");
            return false;
        }
        cout << "NOMBRES DEL EMPLEADO: ";
        cargarCadenas(nombreEmpleado, 59);
        cout << "APELLIDOS DEL EMPLEADO: ";
        cargarCadenas(apellidoEmpleado, 59);
        grabarEnDisco();
        return true;
    }
    void mostrar()
    {
        cout << "LEGAJO: " << legajo << endl;
        cout << "NOMBRES DEL EMPLEADO: " << nombreEmpleado << endl;
        cout << "APELLIDOS DEL EMPLEADO: " << apellidoEmpleado << endl;
    }
    bool buscarLegajoExistente(int legajo)
    {
        Empleados reg;
        int pos = 0;
        while (reg.leerDeDisco(pos++))
        {
            if (reg.get_legajo() == legajo)
                return true;
        }
        return false;
    }
    int buscarLegajo(int legajo)
    {
        Empleados reg;
        int pos = 0;
        while (reg.leerDeDisco(pos))
        {
            if (legajo == reg.get_legajo())
                return pos;
            pos++;
        }
        return -1;
    }
    bool buscarLegajoInactivo(int legajo)
    {
        Empleados reg;
        int pos = buscarLegajoExistente(legajo);
        reg.leerDeDisco(pos);
        if (!reg.get_estado())
            return true;
        else
            return false;
    }
};

#endif // CLASES_H_INCLUDED
