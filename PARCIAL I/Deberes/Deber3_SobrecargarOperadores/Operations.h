/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE
AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON METODOS BINARIOS
FECHA DE CREACION: 16/5/2022
FECHA MODIFICACION: 16/5/2022
*/
#if !defined(__Class_Diagram_1_Operaciones_h)
#define __Class_Diagram_1_Operaciones_h
#include "Data.h"
template<typename H>
class Operations
{
public:
   Operations(); 
	H operator !(Data <H>);
	H operator ->(Data <H>);	
private:
   Data <H> data;
};
#endif
