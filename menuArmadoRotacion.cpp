#include<iostream>
#include<cstdlib>

using namespace std;
#include <windows.h>

void gotoxy(short x, short y){

    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void ponercero(int v[], int tam){
int i;
for(i=0;i<(tam-1);i++){
v[i]=0;
}
}


int main() {

    int cantDisp=5,
    legajosDisponibles[cantDisp]={1111,0,3333,4444,5555},
    operariosParaRotar[5]={4,5,0,0,8}, legRotar,t=0, contDisp=0, contIngre=0,
    r=0, contdisp=0;
    //ponercero(operariosParaRotar, 6);
    bool listDispo=true, buscadorDisp=true;

    while(listDispo=true){
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
    for(int w=0 ; w<=5 ; w++){
        gotoxy(80,3);
        cout << "Operarios Ingresados Para Rotar: "<<endl;

        if(operariosParaRotar[w]!= 0){
            gotoxy(80,5+contIngre);
            cout <<operariosParaRotar[w] <<endl;
            contIngre++;
        }
    }

    gotoxy(3,30);
    cout << "ingresar legajo de los disponibles para rotar: ";
    cin >>legRotar;

    cout<<endl;
    ///asignacion de una lista a la otra
    for (int e=0 ; e<=cantDisp ; e++){
        if(legajosDisponibles[e] == legRotar){
            legajosDisponibles[e]=0;
        }
        }
    buscadorDisp=true;
    while(buscadorDisp && r!=6){
        if(operariosParaRotar[r]==0){
            operariosParaRotar[r]=legRotar;
            buscadorDisp=false;
        }else{
            r++;
        }
        }
        system("cls");

        contDisp=0;
        for(int a=0 ; a<=5 ; a++){
            if(operariosParaRotar[a]==0){
                contDisp++;
            }
        }
        if(contDisp==0){
            gotoxy(3,28);
            cout << "Todos los Puestos Fueron Cargados"<<endl;
            listDispo=false;
        }

        }






	return 0;
}
