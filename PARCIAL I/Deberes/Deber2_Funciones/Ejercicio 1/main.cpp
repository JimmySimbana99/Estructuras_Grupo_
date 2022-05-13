/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA QUE CONVIERTA A UN NUMERO STRING EN (INT, FLOTANTE, STRING)

FECHA DE CREACION: 13/5/2022
FECHA MODIFICACION: 13/5/2022


*/
#include <iostream>
#include "Operaciones.h"

using namespace std;
int main(int, char **)
{
    Operaciones op;
    char *dato;
    while (1)
    {

        dato = op.ingresar("Ingrese dato: ");
        float n_fl;
        int n_int;
        string d_str;
        bool isNumero;

        isNumero = op.indetificarDato(dato);

        cout << "\n";
        cout << " 1. Numero Flotante" << endl;
        cout << " 2. Numero Entero" << endl;
        cout << " 3. String" << endl;
        cout << " 4. SALIR" << endl;
        cout << "\n INGRESE OPCION: ";
        int opc;
        cin >> opc;

        switch (opc)
        {
        case 1:
            if (!isNumero)
            {
                cout << "\nEste dato no es un numero\n";
            }
            else
            {
                n_fl = op.convertirfloat(dato);
                cout << "\nNumero flotante: " << n_fl << "\n";
            }

            break;

        case 2:

            if (!isNumero)
            {
                cout << "\nEste dato no es un numero\n";
            }
            else
            {
                n_int = op.convertirEntero(dato);
                cout << "\nNumero entero: " << n_int << "\n";
            }
            break;

        case 3:

            d_str = op.convertirString(dato);

            cout << "\nDato carcter: " << d_str << "\n";
            break;

        default:
            break;
        }
    }
}
