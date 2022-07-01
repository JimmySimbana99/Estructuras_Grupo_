#include <iostream>
#include <string>
#include "Busqueda.h"
#include "Validar.h"

using namespace std;

int main()
{
    Busqueda busc;
	Validar val;
	int opcion;
    bool repetir = true;
    int dim=0,dato=0;
    while(1){

    system ("cls");
    printf("\t\t===================================\n");
    printf("\t\t\tMENU DE OPCIONES\n");
    printf("\t\t===================================\n");
    cout << "\t\t Busqueda secuencial " << endl;
    printf("\t\t===================================\n");
    switch (opcion) {
            if (opcion > 1 || opcion < 0) {
                repetir = true;
            }
        case 1:

    dim=val.validarNumeros("Digite la cantidad de numeros a ingresar: ",5);
    cout<<endl;
    busc.ingresarElementos(dim);
    dato=val.validarNumeros("Digite el numero que desea buscar: ",5);
    cout<<endl;
    busc.buscarElemento(dato,dim);
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    }

    return 0;

}

