/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON DLL

FECHA DE CREACION: 15/5/2022
FECHA MODIFICACION: 15/5/2022


*/
/* Replace "dll.h" with the name of your header */

#include "dll.h"
#include <windows.h>

DllClass::DllClass()
{

}

DllClass::~DllClass()
{

}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

extern "C" __declspec(dllexport)
int suma(int n){
	
	return n + suma(n-1);
}


extern "C" __declspec(dllexport)
int factorial(int n){
	
	return n * factorial(n-1);

}

