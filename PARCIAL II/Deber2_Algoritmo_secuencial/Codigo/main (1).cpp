#include <iostream>
#include "Busqueda.h"
using namespace std;

int main()
{
    Busqueda busc;
    int n,dato;
    cout<<"Digite la cantidad de numeros a ingresar: \n";
    cin>>n;
    busc.ingresarElementos(n);
    cout<<"Digite el numero que desea buscar: ";
    cin>>dato;
    busc.buscarElemento(dato,n);
    return 0;
}
