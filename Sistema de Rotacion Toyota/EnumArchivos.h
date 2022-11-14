#pragma once

///////////////////////////
// TIPOS ENUMERADOS PARA USAR CON LA CLASE ARCHIVO
enum Estado
{ // DEFINE LOS ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
    NoExiste,
    Cerrado,
    AbiertoR,
    AbiertoW,
    AbiertoA,
    AbiertoRW
};

enum Modo
{ // DEFINE LOS MODOS DE APERTURA DE UN ARCHIVO
    SoloLectura,
    Escritura,
    Agregar,
    LecturaEscritura
};
