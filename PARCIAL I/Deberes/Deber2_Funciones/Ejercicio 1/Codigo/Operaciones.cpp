/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA QUE CONVIERTA A UN NUMERO STRING EN (INT, FLOTANTE, STRING)

FECHA DE CREACION: 13/5/2022
FECHA MODIFICACION: 13/5/2022


*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include <string.h>
using namespace std;
/**
 * @brief Operacion ingresar datos
 * 
 * @param msj 
 * @return char* 
 */
char *Operaciones::ingresar(char *msj)
{
    cout << msj;
    char *dato = new char[20];
    char c;
    int i = 0;
    while ((c = getch()) != 13)
    {
        printf("%c", c);
        dato[i++] = c;
    }
    dato[i] = '\0';
    return dato;
}
/**
 * @brief Operacion identificar datos
 * 
 * @param dato 
 * @return true 
 * @return false 
 */
bool Operaciones::indetificarDato(char *dato)
{
    string datoC(dato);
    int dim = datoC.size();
    int cont = 0;

    for (int i = 0; i < dim; i++)
    {
        if (i == 0 && dato[i] == 46)
        {
            return false;
        }
        else if (dato[i] == 46)
        {
            if (cont == 0)
            {
                cont++;
            }
            else
            {
                return false;
            }
        }
        else if ((dato[i] < 48 || dato[i] >= 57))
        {
            return false;
        }
    }

    return true;
}
/**
 * @brief Operaciones convertir entero
 * 
 * @param dato 
 * @return int 
 */
int Operaciones::convertirEntero(char *dato)
{

    float numero;
    numero = stof(dato);
    int int_n = (int)numero;

    return int_n;
}
/**
 * @brief Convertir a flotante
 * 
 * @param dato 
 * @return float 
 */
float Operaciones::convertirfloat(char *dato)
{
    float numero;
    numero = stof(dato);
    return numero;
}
/**
 * @brief Convertir a string
 * 
 * @param dato 
 * @return string 
 */
string Operaciones::convertirString(char *dato)
{
    return dato;
}