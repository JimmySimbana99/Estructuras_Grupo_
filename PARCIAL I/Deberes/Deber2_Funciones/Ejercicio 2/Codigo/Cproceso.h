/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA QUE CALCULE LA OPERACION ESPECIFICADA EN CLASE.				
				
	FECHA DE CREACION:        13-05-2022	
	FECHA DE MODIFICACION:    13-05-2022*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class Cproceso{
	private:
		int num;
		int den;
	public:
		void setNum(int);
		void setDen(int);
		int getNum();
		int getDen();
		Cproceso(int, int);
		Cproceso racional(Cproceso, Cproceso);
		void imprimirObj(Cproceso);
};