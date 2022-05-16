/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE
AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON METODOS BINARIOS
FECHA DE CREACION: 16/5/2022
FECHA MODIFICACION: 16/5/2022
*/
#include "Data.cpp"
#include "Operations.cpp"
#include <iostream>
using namespace std;
main(){
	float value_1;
	float value_2;
	Data <float> d;
	cout<<"INGRESE EL PRIMER NUMERO: "<<endl;
	cin>>value_1;
	d.setData(value_1);
	cout<<"INGRESE EL SEGUNDO NUMERO: "<<endl;
	cin>>value_2;
	d.setValue(value_2);
	Operations <float> op;	
	cout<<endl;
	cout<<"********"<<endl;
	cout<<"Desigualdad: "<<op.operator !(d)<<endl;
	cout<<"Seleccion de Miembro: "<<op.operator ->(d)<<endl;	
}
