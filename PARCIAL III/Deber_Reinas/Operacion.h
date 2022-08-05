
#include "Reina.cpp"
#include <ctime>
#include "Archivo.h"

class Operacion{
    private:
            reinas reina;
            int tam;
            int nPosibilidad;
            int rando; 
            int fila;
            int columna;
            ListaDoble<Solucion> list;
            ListaDoble<Solucion> posibles;
    public: 
            Operacion()=default;
            void guardarReina(int);
            void iniciarReina();
            void imprimirReina();
            void compararSolucion();


            void imprimirReina2();
            void guardarArchivo1();
            
};

void Operacion::guardarReina(int _tam){
    reina.setTam(_tam);
    tam = _tam;
}

void Operacion::iniciarReina(){
    // reina.GenerarMatrizA();
    // reina.GenerarMatrizB();
    
    for(int i=0; i<tam; i++){
        reina.GenerarMatrizA();
        reina.GenerarMatrizB();
        reina.Respuesta(i,0,1);
    } 
    nPosibilidad = reina.obtenerPosibilidad();
    reina.mostrarArbol();
}

void Operacion::imprimirReina(){
    int cont = 1;
	list = reina.llamar();
}

void Operacion::compararSolucion(){
    reina.pedirReina(fila,columna);
    for(int i=0;i<list.getSize();i++){
        Solucion sol = list.buscar(i);
        for(int j=0;j<tam;j++){
            int x,y;
            x = (sol.getDireccion()+j)->getX();
            y = (sol.getDireccion()+j)->getY();
            if(fila==x && y==columna){
                posibles.insertarFinal(sol);
            }
        }
    }
    
}


void Operacion::imprimirReina2(){
    int cont = 1;
    if(posibles.empty()==false){
        posibles.recorrer([&](Solucion solucion){
			(solucion).recorrerSolucion();
			cout<<endl<<endl;
			cont++;
	});
    }
    else{
        cout<<"No hay Soluciones disponibles"<<endl;
    }
}

void Operacion::guardarArchivo1(){
    Archivo archivo("Reinas.txt",tam);
    archivo.guardarTablero(fila,columna);
    archivo.guardarTablero(posibles);
}
