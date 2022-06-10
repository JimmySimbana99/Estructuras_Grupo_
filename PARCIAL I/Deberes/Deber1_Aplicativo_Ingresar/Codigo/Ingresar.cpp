	/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA QUE CALCULE LA OPERACION ESPECIFICADA EN CLASE Y EL MODELO REALIZADO LLEVARLO A CODIGO.				
				
	FECHA DE CREACION:        10-05-2022	
	FECHA DE MODIFICACION:    10-05-2022*/	
#include "Ingresar.h"
#include <string>
#include <iostream>
using namespace std;
/**
 * @brief  El metodo siguiente hace que se convierta un numero entero en string
 * 
 * @param msj 
 */
void Ingresar::ingresar(char* msj){
    int numero;
	string dato;
	cout<<msj <<endl;
	cin>>dato;
	numero=stoi(dato);
	cout<<numero<<endl;
}
