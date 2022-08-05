#include <iostream>

using namespace std;
class Direccion{
    private:
            int x;
            int y;
            int tam; 
    public:
            Direccion()=default;
            int getX();
            void setX(int);
            int getY();
            void setY(int);
            void guardarDireccion(int,int);
            void imprimirDireccion();
};  

void Direccion::imprimirDireccion(){
    cout<<"(Fila = "<<x<<" /"<<" Columna = "<<y<<")";
}
void Direccion::guardarDireccion(int _x,int _y){
    this->x=_x;
    this->y=_y;
}

int Direccion::getX(){
    return x;
}

void Direccion::setX(int _x){
    this->x = _x;
}

int Direccion::getY(){
    return y;
}

void Direccion::setY(int _y){
    this->y = _y;
}