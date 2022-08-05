/***********************************************************************
 * Module:  Validaciones.h
 * Author:  Kenneth Andrade 
 * Modified: jueves, 10 de junio de 2021 19:02:46
 * Purpose: Declaration of the class Validaciones
 ***********************************************************************/
#include <iostream>

using namespace std; 

#if !defined(__Validacion_Validacion_h)
#define __Validacion_Validacion_h

class Validacion
{
public:
   int validarNum(char *);
   std::string validarLet(std::string);
	std::string borrarFunct(std::string);
protected:
private:

};

#endif
