#include <iostream>

using namespace std;

class Tablero{
    private:
            char **matriz;
            int n;
    public:
            Tablero(int);
            void iniciarTablero();
            void generarTablero();
            void mostrarTablero();
            Tablero()=default;
            void setN(int);

            char** getMatriz();
};

Tablero::Tablero(int _n){
    this->n=_n;
}

void Tablero::iniciarTablero(){
    matriz = new char*[n];
    for(int i=0;i<n;i++){
        *(matriz+i)=new char[n];
    }
}

void Tablero::generarTablero(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(matriz+i)+j)='0';
        }
    }
}

void Tablero::mostrarTablero(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(matriz+i)+j)<<"\t";
        }
        cout<<endl<<endl;
    }
}

void Tablero::setN(int _n){
    n=_n;
}

char** Tablero::getMatriz(){
    return matriz;
}