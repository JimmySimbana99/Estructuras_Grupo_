	/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR LA TORRE DE HANOI			
				
	FECHA DE CREACION:        30-05-2022	
	FECHA DE MODIFICACION:    2-06-2022*/
#include <iostream>
#include <iostream>
#include "Aplicacion.cpp"
using namespace std;
int main(int argc, char** argv) {

	int n,num,movimientos;
	Hanoi<int> torres;
	
	cout<<"\n															TORRE DE HANOI \n";
	cout<<"\n\n";
	cout<<"\nDiscos A, B, C\n";
	cout<<"\nIngrese el numero de discos ";
	cin>>num;
	torres.hanoi(num,'A','B','C');
	cout<<"\nTotal movimientos "<<torres.pasos(num);

	return 0;
}