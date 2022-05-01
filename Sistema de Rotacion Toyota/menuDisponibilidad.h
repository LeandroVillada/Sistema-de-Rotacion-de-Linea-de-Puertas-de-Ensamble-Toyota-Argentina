#ifndef MENUDISPONIBILIDAD_H_INCLUDED
#define MENUDISPONIBILIDAD_H_INCLUDED

void modidicarDisponibilidadRotacion(){

    /// En este menu modifico a los operarios activos y los agrego a la disponibilidad para rotacion

    int opcion;
    while (true){
        system("cls");
        cout << "MENU CAMBIO DE DISPONIBILIDAD" << endl;
        cout << "\n\t1. Listar Operarios Activos para rotacion." << endl;
        cout << "\n\t2. Confirmar disponibilidad." << endl;
        cout << "\n\t3. Eliminar disponibilidad." << endl;
        cout << "\n\t0. Volver al Menu Principal." << endl;

        cin >> opcion;

        switch (opcion){

            case 1:
            //funcio
            system("pause>nul");
            break;

            case 2:
            //funcion
            system("pause>nul");
            break;

            case 0:
            return;
            system("pause>nul");
            break;

            default:
            cout << "OPCION INGRESADA INCORRECTA.";
            system("pause>nul");
            break;
    }



}
}
#endif // MENUDISPONIBILIDAD_H_INCLUDED
