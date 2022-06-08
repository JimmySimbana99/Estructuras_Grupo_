/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE
AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON METODOS BINARIOS
FECHA DE CREACION: 16/5/2022
FECHA MODIFICACION: 16/5/2022
*/
#include "Operations.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/**
 * @brief Construct a new Operations< H>:: Operations object
 * 
 * @tparam H 
 */
template<typename H>
Operations<H>::Operations(){	
}
/**
 * @brief This function add two numbers
 * 
 * @tparam H 
 * @param info 
 * @return H 
 */
template<typename H>
H Operations<H>::operator !(Data <H> info){
   return(info.getData()!H(info.getValue()));
}
/**
 * @brief This function subtract two numbers
 * 
 * @tparam H 
 * @param info 
 * @return H 
 */
template<typename H>
H Operations<H>::operator ->(Data <H> info){
	long int num1=info.getData();
 	long int num2=info.getValue();
	return(num1->num2);
}
