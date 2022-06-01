#pragma once

class Rotacion
{
private:
    int _operarios[26];
    int _semanaUno[26];
    int _semanaDos[26];
    int _semanaTres[26];
    int _semanaCuatro[26];

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
    void setSemanaUno(int *);
    void setSemanaDos(int *);
    void setSemanaTres(int *);
    void setSemanaCuatro(int *);
    // GETTS
    int *getOperarios();
    int *getSemanaUno();
    int *getSemanaDos();
    int *getSemanaTres();
    int *getSemanaCuatro();
};
