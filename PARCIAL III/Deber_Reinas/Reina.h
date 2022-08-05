#include <iostream> 
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include "Solucion.h"
#include "ListaDoble.h"
#include "Arbol.h"

using namespace std;

class reinas{
private:
    int tam;
    int x;
    int y;
    char **matrizA;
    bool **matrizB;
    int numPosibilidad = 0;
    int **mat;
    int **mat2;
    ListaDoble<Solucion> listSol;
    int cont = 0;
    Arbol<int> arbol;
public:
    reinas()=default;
    reinas(int);
    void GenerarMatrizA();
    void GenerarMatrizB();
    void Reglas(int, int);
    void Llenar(int, int);
    void Imprimir(bool);
    void PonerReina(int, int);
    void Respuesta(int, int, int);
    int obtenerPosibilidad();
    void generarReina(int val);

    void obtenerMatriz();

    void guardarSolucion(Direccion,int);
    void iniciarVecDireccion();
    ListaDoble<Solucion> llamar();
    void setTam(int);

    void pedirReina(int&,int&);

    void mostrarArbol();

};