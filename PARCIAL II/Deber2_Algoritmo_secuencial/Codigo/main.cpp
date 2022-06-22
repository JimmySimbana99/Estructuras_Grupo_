/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE
AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON FUNCIONES TRIGNONOMETRICAS
FECHA DE CREACION: 16/5/2022
FECHA MODIFICACION: 16/5/2022
*/
#include<iostream>
#include "Operaciones.h"
using namespace std;


int main(){
	int valor,valAprox;
	float res;
	cout<<"Ingrese el valor de aproximacion (50 o mas para mayor aproximacion): ";
	cin>>valAprox;
	cout << "Ingrese el valor del f(x): ";
	cin>>valor;
	cout<<endl;
	Operaciones op;
	//Cos 
	res=op.calc_cos(valAprox,valor);
	cout.setf(ios::fixed);
    cout.precision(9);
	cout<<"Resultado Cos(x): "<<res<<endl;
	//Sen 
	res=op.calc_sen(valAprox,valor);
	cout.setf(ios::fixed);
    cout.precision(9);
    cout<<"Resultado Sen(x): "<<res<<endl;
	//Csc
	res=op.calc_csc(valAprox,valor);
	cout.setf(ios::fixed);
    cout.precision(9);
	cout<<"Resultado Csc(x): "<<res<<endl;
	//Sec 
	res=op.calc_sec(valAprox,valor);
	cout.setf(ios::fixed);
    cout.precision(9);
	cout<<"Resultado Sec(x): "<<res<<endl;
	//Tan
	res=op.calc_tan(valAprox,valor);
	cout.setf(ios::fixed);
    cout.precision(9);
	cout<<"Resultado Tang(x): "<<res<<endl;
	return 0;
}