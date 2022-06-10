/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    ALEXANDER MAILA - jamaila@espe.edu.ec
				JIMMY SIMBAÑA - jasimbana14@espe.edu.ec
	
	ENUNCIADO: REALIZAR UN PROGRAMA QUE CALCULE LA OPERACION ESPECIFICADA EN CLASE.				
				
	FECHA DE CREACION:        13-05-2022	
	FECHA DE MODIFICACION:    13-05-2022*/
#include "Cproceso.h"
/**
 * @brief Construct a new Cproceso:: Cproceso object
 * 
 * @param numerador 
 * @param denominador 
 */
Cproceso::Cproceso(int numerador,int denominador){
	this->num=numerador;
	this->den=denominador;
}
void Cproceso::setNum(int numerador){
	num=numerador;
}
void Cproceso::setDen(int denominador){
	den=denominador;
}
int Cproceso::getNum(){
	return num;
}
int Cproceso::getDen(){
	return den;
}
/**
 * @brief Generar el objeto 
 * 
 * @param obj1 
 * @param obj2 
 * @return Cproceso 
 */
Cproceso Cproceso::racional(Cproceso obj1, Cproceso obj2){
	int a,b,c,d;
	a=obj1.getNum();
	b=obj1.getDen();
	c=obj2.getNum();
	d=obj2.getDen();
	this->setNum((a*d)+(b*c));
	this->setDen(b*d);
	return *this;
}
/**
 * @brief Imprime el objeto
 * 
 * @param obj 
 */
void Cproceso::imprimirObj(Cproceso obj){
	cout<<obj.getNum()<<"/"<<obj.getDen()<<endl;
}






