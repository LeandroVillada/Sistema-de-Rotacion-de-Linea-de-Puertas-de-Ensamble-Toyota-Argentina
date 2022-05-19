#ifndef FUNCIONESARMADOROTACION_H_INCLUDED
#define FUNCIONESARMADOROTACION_H_INCLUDED

int *asignarLegajosDisponibles(){
    Empleados reg;
    int pos = 0, contador = 0, posi = 0, cont = 0;
    /// Generador de cantidad de disponibles
    while (reg.leerDeDisco(pos++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            contador++;
        }
    }
    /// Asignacion de legajos a vector
    int *vectorDisponibles;
    vectorDisponibles = new int[contador];
    pos = 0;
    while (reg.leerDeDisco(posi++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            vectorDisponibles[cont] = reg.getLegajo();
            cont++;
        }
    }
    return vectorDisponibles;
}

void menuArmadoRotacion(int cantDisp, int *legajosDisponibles, int *operariosParaRotar ) {
    ponercero(operariosParaRotar, 26);
    int legRotar, contDisp=0, contIngre=0,
    r=0 ;
    bool listDispo=true, buscadorDisp=false;

    while( listDispo == true){
    contDisp=0,contIngre=0,r=0;

    ///lista de disponibles para agregar a la rotacion
    for(int q=0; q<cantDisp ; q++){
        gotoxy(3,3);
        cout << "Operarios Disponibles Para Agregar a Rotacion: "<<endl;
        if(legajosDisponibles[q]!= 0){
            gotoxy(5,5+contDisp);
            cout <<legajosDisponibles[q] <<endl;
            contDisp++;
        }
    }

    /// lista de operarios ingresados para rotar
    for(int w=0 ; w<=25 ; w++){
        gotoxy(80,3);
        cout << "Operarios Ingresados Para Rotar: "<<endl;
        if(operariosParaRotar[w]!= 0){
            gotoxy(80,5+contIngre);
            cout <<operariosParaRotar[w] <<endl;
            contIngre++;
        }
    }
    gotoxy(3,40);
    cout << "ingresar legajo de los disponibles para rotar: ";
    cin >>legRotar;
    cout<<endl;

    ///asignacion de una lista a la otra
    for (int e=0 ; e<= cantDisp ; e++){
        if(legajosDisponibles[e] == legRotar){
            legajosDisponibles[e]=0;
            buscadorDisp=true;
        }
        }
    while(buscadorDisp && r!=26){
        if(operariosParaRotar[r]==0){
            operariosParaRotar[r]=legRotar;
            buscadorDisp=false;
        }else{
            r++;
        }
        }
        system("cls");

    /// contador de disponibles
        if(operariosParaRotar[25]!=0){
            listDispo=false;
            break;
        }
        }
            gotoxy(3,28);
            cout << "Todos los Puestos Fueron Cargados"<<endl;
            system("pause");
            system("cls");
            return ;
}

int contarLegajosActivosDisponibles()
{
    Empleados reg;
    int pos = 0, contador = 0;
    while (reg.leerDeDisco(pos++))
    {
        if ((reg.getEstado()) && (reg.getDisponibilidad()))
        {
            contador++;
        }
    }
    return contador;
}
#endif // FUNCIONESARMADOROTACION_H_INCLUDED
