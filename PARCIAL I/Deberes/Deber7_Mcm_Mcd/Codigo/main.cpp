/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA QUE REALICE LAS OPERACIONES DE MCD Y MDC

FECHA DE CREACION: 22/5/2022
FECHA MODIFICACION: 22/5/2022


*/
#include "Data.cpp"
#include "Operations.cpp"
#include <iostream>
using namespace std;
main(){
	float value_1;
	float value_2;
	float value_3;
	Data <float> d;
	cout<<"ENTER THE FIRST NUMBER: "<<endl;
	cin>>value_1;
	d.setData(value_1);
	cout<<"ENTER THE SECOND NUMBER: "<<endl;
	cin>>value_2;
	d.setValue(value_2);
	Operations <float> op;	
	cout<<endl;
	cout<<"********"<<endl;
	cout<<"MCM: "<<op.operator /=(d)<<endl;

}