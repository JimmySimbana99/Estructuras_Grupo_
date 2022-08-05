/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA DEL JUEGO LAS REINAS

FECHA DE CREACION: 3/8/2022
FECHA MODIFICACION: 5/8/2022


*/
/***********************************************************************
 * Module:  Validaciones.cpp
 * Author:  Kenneth Andrade 
 * Modified: jueves, 10 de junio de 2021 19:02:46
 * Purpose: Implementation of the class Validaciones
 ***********************************************************************/

#include "Validacion.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std; 
////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::validarNum(char * msj)
// Purpose:    Implementation of Validaciones::validarNum()
// Parameters:
// - msj
// Return:     int
////////////////////////////////////////////////////////////////////////

int Validacion::validarNum(char * msj)
{
    char dat[8];
    int i=0,valor;
    char c;
    printf("%s",msj);
    while((c=getch())!=13){
        if(c>='0' && c<='9'){
            printf("%c",c);
            dat[i++]=c;
        }
    }
    dat[i]='\0';
    valor=atoi(dat);
    return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::validarLet(std::string letra)
// Purpose:    Implementation of Validaciones::validarLet()
// Parameters:
// - letra
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Validacion::validarLet(std::string letra)
{
   string aux;
	int letra2;
	while (((letra2 = _getch()) != 13) || (aux.length() == 0)) {
		if ('A' <= letra2 && letra2 <= 'Z' || 'a' <= letra2 && letra2 <= 'z') {
			aux += (char)letra2;
			printf("%c", letra2);
		}
		else if (letra2 == 8) {
			system("cls");
			aux = borrarFunct(aux);
			cout << letra;
			cout << aux;
		}
	}
	printf("\n");
	return aux;
}

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::borrarFunct(std::string elementoBorrar)
// Purpose:    Implementation of Validaciones::borrarFunct()
// Parameters:
// - elementoBorrar
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Validacion::borrarFunct(std::string elementoBorrar) {
	string aux = "";
	for (int i = 0; i < elementoBorrar.length() - 1 && elementoBorrar != ""; i++) {
		aux += elementoBorrar[i];
	}
	return aux;
}
