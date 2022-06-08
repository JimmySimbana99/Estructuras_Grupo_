/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA QUE CONVIERTA A UN NUMERO STRING EN (INT, FLOTANTE, STRING)

FECHA DE CREACION: 13/5/2022
FECHA MODIFICACION: 13/5/2022


*/
#include "iostream"

using namespace std;
class Operaciones
{
public:
    char *ingresar(char *msj);
    bool indetificarDato(char *);
    int convertirEntero(char *);
    float convertirfloat(char *);
    string convertirString(char *);
};
