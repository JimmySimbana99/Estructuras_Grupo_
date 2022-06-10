	/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR LA TORRE DE HANOI			
				
	FECHA DE CREACION:        30-05-2022	
	FECHA DE MODIFICACION:    2-06-2022*/
#include "Aplicacion.h"
#include <iterator>
#include <charconv>
using namespace std;
template<typename N>
/**
 * @brief Movilidad de los bloques ya sea A, B , C 
 * 
 * @param num 
 * @param a 
 * @param b 
 * @param c 
 */
void Hanoi<N>::hanoi(N num,N a,N b,N c){
	char A,B,C;
	
	
	if(num==1){
		cout<<"Mover del bloque "<<num<<" Desde "<<char(a)<<" Hasta "<< char(c)<< endl;
	}
	else{
		hanoi(num-1,a,b,c);
		cout<<"Mover del bloque "<<num<<" Desde "<<char(a)<<" Hasta "<< char(c)<< endl;
		hanoi(num-1,b,c,a);
	}
}
template<typename N>
int Hanoi<N>::pasos(N discos){
		if(discos==1){
			return 1;
		}
		else{
			return 2*pasos(discos-1)+1;
		}
	}