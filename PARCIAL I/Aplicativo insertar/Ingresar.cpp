/*	UNIVERSITY OF THE ARMED FORCES ESPE
	COMPUTER SCIENCE DEPARTMENT
    SOFTWARE ENGINEER
                
	AUTHORS:   	ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	STATEMENT: 	CHANGE STRING TO INTEGER		
				
	CREATION DATE:        10-05-22 	
	MODIFICATION DATE:    10-05-22*/
	
//LIBRARY STATEMENT	
#include "Ingresar.h"
#include <string>
#include <iostream>
using namespace std;
void Ingresar::ingresar(char* msj){
    int numero;
	string dato;
	cout<<msj <<endl;
	cin>>dato;
	numero=stoi(dato);
	cout<<numero<<endl;
}
