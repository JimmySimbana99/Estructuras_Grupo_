/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA DEL JUEGO LAS REINAS

FECHA DE CREACION: 3/8/2022
FECHA MODIFICACION: 5/8/2022


*/
#include <iostream>
#include "Operacion.h"
#include <ctime>
#include "Menu.cpp"

using namespace std;

int main(){
	Menu menu;
	int n_reinas;
	Validacion validacion;
	int opc=0;
    do
    {
        opc = menu.menuPrincipal();
			do{
		system("cls");
		n_reinas=validacion.validarNum("\n Ingrese el numero de reinas[4:8]: ");
	}while(n_reinas<4 || n_reinas>8);
        switch (opc)
        {
			case 1:
				Operacion operacion;
				operacion.guardarReina(n_reinas);
				cout<<endl;
        		operacion.iniciarReina();
				operacion.imprimirReina();
				operacion.compararSolucion();
				operacion.imprimirReina2();
				operacion.guardarArchivo1();
				system("pause");
				break;
        }
    } while (opc != 2);
}

