#ifndef FUNCIONEDITAREMPLEADOS_H_INCLUDED
#define FUNCIONEDITAREMPLEADOS_H_INCLUDED

void darBajaLegajo()
{
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo a dar de baja: ";
    cin >> legajo;
    // Comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    // Comprobamos si el legajo esta dado de baja o no.
    if (reg.buscarLegajoInactivo(legajo))
    {
        cout << "El legajo ingresado ya esta inactivo." << endl;
        return;
    }
    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Cambiamos el valor del estado del registro
    reg.setEstado(false);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    cout << "Legajo dado de baja con exito." << endl;
}


void darAltaLegajo()
{
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo a dar de Alta: ";
    cin >> legajo;
    // Comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    // Comprobamos si el legajo esta dado de baja o no.
    if (!reg.buscarLegajoInactivo(legajo))
    {
        cout << "El legajo ingresado ya esta activo." << endl;
        return;
    }
    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Cambiamos el valor del estado del registro
    reg.setEstado(true);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    cout << "Legajo dado de alta con exito." << endl;
}


/*void editarLegajoEmpleado()
{
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo a editar: ";
    cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarLegajo(legajo);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Reutilizamos la variable "legajo"
    cout << "Numero de legajo nuevo: ";
    cin >> legajo;
    // Comprobamos si el legajo ingresado ya existe.
    if (reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado ya existe." << endl;
        return;
    }
    // Cambiamos el valor del legajo y actualizamos el registro.
    reg.set_legajo(legajo);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    cout << "Legajo editado con exito." << endl;
}
*/

void editarNombreEmpleado()
{
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo a editar el nombre: ";
    cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    char nombre[60];
    cout << "Ingrese Nombre Nuevo: ";
    // Utilizamos la funcion cargarCadenas(mandando nombre y el tamanio -1).
    cargarCadenas(nombre, 59);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Actualizamos el nombre del registro
    reg.setNombre(nombre);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    cout << "Nombre editado con exito." << endl;
}


void editarApellidoEmpleado()
{
    Empleados reg;
    int legajo;
    cout << "Ingresar el Legajo a editar el apellido: ";
    cin >> legajo;
    // Aqui comprobamos si el legajo ingresado no existe.
    if (!reg.buscarLegajoExistente(legajo))
    {
        cout << "El legajo ingresado no existe." << endl;
        return;
    }
    // La variable "pos" guarda la posicion donde se encuentra el registro del legajo ingresado.
    int pos = reg.buscarPosicionLegajo(legajo);
    char apellido[60];
    cout << "Apellido Nuevo: ";
    // Utilizamos la funcion cargarCadenas(mandando apellido y el tamanio -1).
    cargarCadenas(apellido, 59);
    // Leemos el registro en la posicion de la variable pos para obtener el registro.
    reg.leerDeDisco(pos);
    // Actualizamos el apellido del registro
    reg.setApellido(apellido);
    // Grabamos en el registro el cambio que realizamos mandando la posicion correspondiente del registro a editar.
    reg.modificarEnDisco(pos);
    cout << "Apellido editado con exito." << endl;
}

#endif // FUNCIONEDITAREMPLEADOS_H_INCLUDED
