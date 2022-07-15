#include <iostream>
#include "Arbol.h"
#include "Menu.h"

using namespace std;



int main(int, char**) {


    int opc, numero;
    Menu menu;

    Arbol arbol;

    

    do
    {
        opc = menu.menuPrincipal();
        switch (opc)
        {
            case 1:
                
                cout<<"\n\nIngrese el valor a insertar: ";
                cin>>numero;
                arbol.insertar(numero);
                arbol.generarGrafico();
                break;

            case 2:
                cout<<"\n\nIngrese el valor a buscar: ";
                cin>>numero;
                if (!arbol.buscar(arbol.getRaiz(),numero))
                {
                    cout<<"\nEl valor fue econtrado: "<<numero<<endl;
                }else{
                    cout<<"\nEl no valor fue econtrado: "<<endl;
                }

                system("pause");

                break;

            case 3:

                cout<<"\n\nIngrese el valor a Eliminar: ";
                cin>>numero;

                if (!arbol.buscar(arbol.getRaiz(),numero))
                {
                    cout<<"\nEl valor fue econtrado y eliminado: "<<numero<<endl;
                    arbol.eliminar(numero);
                    arbol.generarGrafico();
                }else{
                    cout<<"\nEl no valor fue econtrado: "<<endl;
                }

                system("pause");

                break;

            case 4:
                arbol.generarGrafico();
                system("pause");
            
                break;

            case 5:
                cout<<"\nRecorrido en pre-Orden: ";
                arbol.preOrden(arbol.getRaiz());
                cout<<"\nRecorrido en in-Orden: ";
                arbol.inOrden(arbol.getRaiz());
                cout<<"\nRecorrido en post-Orden: ";
                arbol.postOrden(arbol.getRaiz());
                cout<<endl;
                system("pause");
            
                break;
        }
    } while (opc != 6);
}
