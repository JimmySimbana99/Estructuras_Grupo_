/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA QUE CALCULE LA OPERACION ESPECIFICADA EN CLASE.				
				
	FECHA DE CREACION:        13-05-2022	
	FECHA DE MODIFICACION:    13-05-2022*/
#include <iostream>
#include "Cproceso.h"
int main(int argc, char** argv) {
	int a=18,b=3;
	Cproceso *obj1=new Cproceso(a,b);
	Cproceso *obj2=new Cproceso(15,5);
	Cproceso *obj3=new Cproceso(0,0);
	obj3->racional(*obj1,*obj2);
	obj1->imprimirObj(*obj1);
	obj2->imprimirObj(*obj2);
	obj3->imprimirObj(*obj3);
	return 0;
}