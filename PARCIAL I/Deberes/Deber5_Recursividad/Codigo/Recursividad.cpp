
/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA 
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA EN CLASES 			
				
	FECHA DE CREACION:        16-05-2022	
	FECHA DE MODIFICACION:    16-05-2022*/
#include "Recursividad.h"
#include "Suma.h"
#include <string>
/**
 * @brief Factorial procedimeitno
 * 
 * @param n 
 * @return int 
 */
int Factorial::factorial(int n){
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}
/**
 * @brief SUma procedimeinto
 * 
 * @param n 
 * @return int 
 */
int Suma::suma(int n){
	if (n==0) {
		return 0;
	}
	else {
		return n + suma(n-1);
	}
}
