
/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:     ALEXANDER MAILA 
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA EN CLASES 			
				
	FECHA DE CREACION:        16-05-2022	
	FECHA DE MODIFICACION:    16-05-2022*/
#include <iostream>
#include "Suma.h"
#include "Recursividad.h"

using namespace std;

int main(){

	Suma objSuma;
	Factorial objFactorial;


	int n = 5;
	for (int i = 1; i <= n;i++) {
		cout << "SUMA: " << objSuma.suma(i)<<"	";
		cout << "FACTORIAL: " << objFactorial.factorial(i)<<endl;
	}

}
