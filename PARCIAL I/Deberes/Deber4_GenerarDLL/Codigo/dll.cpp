#include <iostream>
#include <windows.h>

using namespace std;

	typedef int(WINAPI *op)(int);
	typedef int(WINAPI *op1)(int);
	
int main(){
	
	op suma;
	op1 factorial;
	int cant1;
	cant1 = 5;
	
	HINSTANCE LibDLL = NULL;
	
	LibDLL = LoadLibrary("Recursividad.dll");
	
	if(LibDLL !=NULL){
		
		suma = (op)GetProcAddress(LibDLL, "suma");
		factorial = (op1)GetProcAddress(LibDLL, "factorial");
		
		if(!suma)
		{
			cout << "ERROR no se encontro la funcion \n \n";
			system("pause");
		}else{
			cout <<"LA SUMA ES" << suma(cant1) << "\n\n";
			cout <<"El FACTORIAL  ES" << factorial(cant1) << "\n\n";
			system("pause");
		}
		
		FreeLibrary(LibDLL);
		LibDLL = NULL;
		
		
	}else{
		cout<<"ERROR no se cargo la libreria \n \n" ;
		system("pause");
	}
	return 0;
}