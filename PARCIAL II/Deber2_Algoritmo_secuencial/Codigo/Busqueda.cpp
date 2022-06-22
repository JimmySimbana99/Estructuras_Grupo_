#include "Busqueda.h"

void Busqueda::ingresarElementos(int dim){
   datos=new int [dim];
   for(int i=0;i<dim;i++){
   cout<<"Digite los elementos "<<(i)<<" :";
   cin>>*(datos+i);
    }
}

void Busqueda::buscarElemento(int a, int dim){
   char band='f';
   int i=0;
   while((band=='f')&&(i<dim)){
        if(*(datos+i)==a){
            band='v';
        }
        i++;
    }

    if(band=='f'){
        cout<<"El numero no existe";
    }else if (band=='v'){
        cout<<"El numero fue encontrado en la posicion: "<<i-1<<endl;
    }
}

