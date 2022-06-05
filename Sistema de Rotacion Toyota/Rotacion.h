#pragma once

class Rotacion
{
private:
    int _operarios[26];
    int _bloqueUno[26];
    int _bloqueDos[26];
    int _bloqueTres[26];
    int _bloqueCuatro[26];

public:
    // FUNCIONES ARCHIVOS
    bool leerDeDisco(int);
    bool grabarEnDisco();
    bool modificarEnDisco(int);
    int cantidadRegistros();
    bool leerDeDiscoBKP(int);
    bool grabarEnBackUp();
    bool restaurarBackUP();
    bool exportar();
    // SETTS
    void setOperarios(int *);
    void setBloqueUno(int *);
    void setBloqueDos(int *);
    void setBloqueTres(int *);
    void setBloqueCuatro(int *);
    // GETTS
    int *getOperarios();
    int *getBloqueUno();
    int *getBloqueDos();
    int *getBloqueTres();
    int *getBloqueCuatro();
};
