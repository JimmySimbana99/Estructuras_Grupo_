#include <fstream> 
#include <iostream> 
#include "Tablero.h"

using namespace std;

class Archivo{
    private : 
        fstream entrada;
        int tam = 0;
        Tablero tablero;
        string name;
    public:
        Archivo(string,int);
        void guardarTablero(int,int);
        void guardarTablero(ListaDoble<Solucion>);
        Archivo()=default;
};

Archivo::Archivo(string _name,int _tam){
    tam = _tam;
    tablero.setN(tam);
    tablero.iniciarTablero();
    tablero.generarTablero();
    name = _name;    
}

void Archivo::guardarTablero(int _fil,int _col){
    entrada.open(name, fstream::out);
    entrada << "Tablero de " << tam << "*"<< tam <<endl<<endl;
    char _reina = 169;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(i==_fil && j==_col){
                entrada<<_reina<<"\t";
            }else{
                 entrada<<*(*(tablero.getMatriz()+i)+j)<<"\t";
            }
        }
        entrada<<endl<<endl;
    }
    entrada.close();
}
void Archivo::guardarTablero(ListaDoble<Solucion> posibles){
    entrada.open(name, fstream::app);
    int lis = posibles.getSize();
    entrada << "Tablero de " << tam << "*"<< tam <<endl<<endl;
    char _reina = 169;
    int valY=0;
    for(int i=0;i<posibles.getSize();i++){
        Solucion sol = posibles.buscar(i);
        for(int j=0;j<tam;j++){
                int x,y;
                x = (sol.getDireccion()+j)->getX();
                y = (sol.getDireccion()+j)->getY();
                *(*(tablero.getMatriz()+x)+y)=_reina;
                
                entrada<<"Reina "<<j+1<<": (Fila: "<<x<<" / Columna: "<<y<<")"<<endl;
                entrada<<endl;
        }
        for(int k=0;k<tam;k++){
            for(int l=0;l<tam;l++){
                    entrada<<*(*(tablero.getMatriz()+k)+l)<<"\t";
                }
                entrada<<endl<<endl;
            }
        entrada<<endl<<endl;
        tablero.generarTablero();
    }
entrada.close();
}

