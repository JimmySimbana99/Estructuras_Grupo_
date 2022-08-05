#include "Direccion.h"

class Solucion{
    private:    
            Direccion *direccion;
            int tam;
    public:
            Solucion()=default;
            Direccion *getDireccion();
            void setDireccion(Direccion*);
            void guardar(Direccion,int);
            void asignarMemoria(int);
            void recorrerSolucion();
};

void Solucion::guardar(Direccion _direccion,int _contador){
    *(direccion+_contador)=_direccion;
}

Direccion* Solucion::getDireccion(){
    return direccion;
}

void Solucion::setDireccion(Direccion* _direccion){
    direccion = _direccion;
}

void Solucion::asignarMemoria(int _tam){
    tam = _tam;
    direccion = new Direccion[_tam];
}

void Solucion::recorrerSolucion(){
    for(int i=0;i<tam;i++){
        cout<<"Reina "<<i+1<<" : ";
        (direccion+i)->imprimirDireccion();
        cout<<endl;
    }
}
