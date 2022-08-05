#include "Nodo.h"
#include <iostream>
#include <fstream>

using namespace std; 

template <typename T>
class Arbol{
    private:
        Nodo<T>* raiz=nullptr;
        ofstream archivo;
        
    public:
        Arbol()=default;
        bool estaVacio();
        void imprimirArbolBin(Nodo<T>* arbol);
        void insertar(T valor);
        Nodo<T>* crearNuevoNodo(T);      
        Nodo<T>* getArbol();
        void setArbol(Nodo<T>*);
        void displayArbol();
        void eliminarNodo(Nodo<T>* nodoElimina);
        void mostrarArbol(Nodo<T>* arbol,int cont);
        Nodo<T>* buscar(int,Nodo<T>*);
        bool buscar(int valor);
        void eliminar(T);
        void eliminarNodoPrivado(T,Nodo<T>*);
        void eliminarCoincidencias();
        Nodo<T>* getmin(Nodo<T>* raiz);
        int encontrarMinimo(Nodo<T>*);
        void removerEntre(Nodo<T>*,Nodo<T>*,bool);
        //grafico
        void generarGrafico();
        void graficarArbol(Nodo<T> *nodo);
        //Recorridos
        void preOrden(Nodo<T> *nodo);
        void inOrden(Nodo<T> *nodo);
        void postOrden(Nodo<T> *nodo);
};
template<typename T>
bool Arbol<T>::estaVacio() {
        return(raiz==nullptr);
}

template<typename T>
Nodo<T>* Arbol<T>::crearNuevoNodo(T valor1){
    Nodo<T>* temp = new Nodo<T>();
    temp->setValor(valor1);
    return temp;
}

template<typename T>
Nodo<T>* Arbol<T>::getArbol(){
    return this->raiz;
}

template<typename T>
void Arbol<T>::setArbol(Nodo<T>* _arbol){
    this->raiz = _arbol;
}


template<typename T>
void Arbol<T>::insertar(T valor){
    Nodo<T>* nuevo = new Nodo<T>();
    Nodo<T>* padre; 
    nuevo->setValor(valor);
    nuevo->setNodoIzquierdo(nullptr);
    nuevo->setNodoDerecho(nullptr);
    padre = nullptr;
    if(estaVacio()){
        raiz = nuevo;
    }else{
        Nodo<T>* temp;
        temp = raiz; 
        while(temp!=nullptr){
            padre = temp;
            if(valor>temp->getValor()){
                temp = temp->getNodoDerecho();
            }
            else{
                temp = temp->getNodoIzquierdo();
            }
        }
        if(valor<padre->getValor()){
            padre->setNodoIzquierdo(nuevo);
        }
        else{
            padre->setNodoDerecho(nuevo);
        }
    }
}

template<typename T>
void Arbol<T>::displayArbol(){
    imprimirArbolBin(raiz);
    cout<<endl<<endl;
    cout<<endl<<endl;
    mostrarArbol(raiz,0);
}
template<typename T>
void Arbol<T>::imprimirArbolBin(Nodo<T>* arbol){
    if(arbol!=NULL){
        imprimirArbolBin(arbol->getNodoIzquierdo());
        cout<<"  "<<arbol->getValor()<<"     ";
        imprimirArbolBin(arbol->getNodoDerecho());
    }
}

template<typename T>
void Arbol<T>::mostrarArbol(Nodo<T>* arbol,int cont){
    if(arbol==nullptr){
        return;
    }
    else{
        mostrarArbol(arbol->getNodoDerecho(),cont+1);
        for(int i=0;i<cont;i++){
            cout<<"   ";
        }
        cout<<arbol->getValor()<<endl;
        mostrarArbol(arbol->getNodoIzquierdo(),cont+1);
    }
}

template<typename T>
Nodo<T>* Arbol<T>::buscar(int valor,Nodo<T> *temp)
{
  if(temp!=nullptr)
  {
    if(valor==temp->getValor())
      return temp;
    if(valor<temp->getValor())
      return buscar(valor,temp->getNodoIzquierdo());
    else
      return buscar(valor,temp->getNodoDerecho());
  }
    else 
    {
        return nullptr;
    }
}

template<typename T>
bool Arbol<T>::buscar(int valor)
{
  Nodo<T>* temp = buscar(valor,raiz);
  if(temp==nullptr){
      return false;
  }
  else if(temp->getValor()==valor){
      return true;
  }else{
      return false;
  }
}
template<typename T>
void Arbol<T>::eliminar(T dato){
    eliminarNodoPrivado(dato,raiz);
}

template<typename T>
void Arbol<T>::eliminarNodoPrivado(T dato,Nodo<T>* privado){
    if (raiz != nullptr){
        if (raiz->getValor() == dato)
            eliminarCoincidencias();
        else{
            if (dato < privado->getValor() && privado->getNodoIzquierdo() != nullptr){
                privado->getNodoIzquierdo()->getValor() == dato ? removerEntre(privado,privado->getNodoIzquierdo(),true) : eliminarNodoPrivado(dato,privado->getNodoIzquierdo());
            }
            else if (dato > privado->getValor() && privado->getNodoDerecho() != nullptr){
                privado->getNodoDerecho()->getValor() == dato ? removerEntre(privado,privado->getNodoDerecho(),false) : eliminarNodoPrivado(dato,privado->getNodoDerecho());
            }
            else
                cout << "No se ha encontrado el dato en el arbol" << endl;
        }
    }
    else
        cout << "El arbol esta vacío" << endl;
}


template<typename T>
void Arbol<T>::eliminarCoincidencias(){
    if (raiz != nullptr){
        Nodo<T>* datoPrivado = raiz; 
        int datoRaiz = raiz->getValor();
        int datoMinimo;
        if (raiz->getNodoIzquierdo()== nullptr && raiz->getNodoDerecho() == nullptr){
            delete datoPrivado;
            raiz = nullptr;
        }
        else if (raiz->getNodoIzquierdo() != nullptr && raiz->getNodoDerecho() == nullptr){
            raiz = raiz->getNodoIzquierdo();
            datoPrivado->setNodoIzquierdo(nullptr);
            delete datoPrivado;
        }
        else if (raiz->getNodoIzquierdo() == nullptr && raiz->getNodoDerecho() != nullptr){
            raiz = raiz->getNodoDerecho();
            datoPrivado->setNodoDerecho(nullptr);
            delete datoPrivado;     
        }
        else if (raiz->getNodoIzquierdo() != nullptr && raiz->getNodoDerecho()!= nullptr){ 
            datoMinimo = encontrarMinimo(raiz->getNodoDerecho());
            eliminarNodoPrivado(datoMinimo, raiz);
            raiz->setValor(datoMinimo);
        }
    }
    else
        cout << "No se puede remover arbol  vacio" << endl;
}

template<typename T>
void Arbol<T>::removerEntre(Nodo<T>* padre,Nodo<T>* marca,bool izquierdo){
    if (raiz != nullptr){
        Nodo<T>* principal; 
        int datoMarcado = marca->getValor();
        int datoMinimo;
        if (marca->getNodoIzquierdo() == nullptr && marca->getNodoDerecho() == nullptr){
            principal = marca;
            izquierdo == true ? padre->setNodoIzquierdo(nullptr) : padre->setNodoDerecho(nullptr);
            delete principal;
        }
        else if (marca->getNodoIzquierdo() == nullptr && marca->getNodoDerecho()!= nullptr){
            izquierdo == true ? padre->setNodoIzquierdo(marca->getNodoDerecho()) : padre->setNodoDerecho(marca->getNodoDerecho());
            marca->setNodoDerecho(nullptr);
            principal = marca;
            delete principal;
        }
        else if (marca->getNodoIzquierdo() != nullptr && marca->getNodoDerecho()== nullptr){
            izquierdo == true ? padre->setNodoIzquierdo(marca->getNodoIzquierdo()) : padre->setNodoDerecho(marca->getNodoIzquierdo());
            marca->setNodoIzquierdo(nullptr);
            principal = marca;
            delete principal;
        }
        else{
            datoMinimo = encontrarMinimo(marca->getNodoDerecho());
            eliminarNodoPrivado(datoMinimo, marca);
            marca->setValor(datoMinimo);
        }
    }
    else
        cout << "Can not remove match. The tree is Empty" << endl;
        system("pause");
}


template<typename T>
Nodo<T>* Arbol<T>::getmin(Nodo<T>* raiz)
{
    Nodo<T>* curr = raiz;
    while (curr && curr->getNodoIzquierdo()) {
        curr = curr->getNodoIzquierdo();
    }
    return curr;
}

template<typename T>
int Arbol<T>::encontrarMinimo(Nodo<T>* privado){
    if (raiz == nullptr)
        return 0;
    else{
        if (privado->getNodoIzquierdo() != nullptr)
            return encontrarMinimo(privado->getNodoIzquierdo());
        else
            return privado->getValor();
    }
}

template<typename T>
void Arbol<T>::generarGrafico(){
    
    archivo.open("Binario.dot", ios::out);
    archivo<<"digraph G {\n";
    graficarArbol(raiz);
    archivo<<"}";
    archivo.close();

    system("dot.exe -Tpng Binario.dot -o Binario.png");

    
}

template<typename T>
void Arbol<T>::graficarArbol(Nodo<T> *nodo){
    if (nodo == nullptr)
    {
        return;
    }
    archivo<<"x"<<nodo<<"[label=\""<<nodo->getValor()<<"\"];"<<endl;
    if (nodo->getNodoIzquierdo() != nullptr)
    {
        archivo<<"x"<<nodo<<"->"<<"x"<<nodo->getNodoIzquierdo()<<"[arrowhead = normaltee];"<<endl;
    }

    if (nodo->getNodoDerecho() != nullptr)
    {
        archivo<<"x"<<nodo<<"->"<<"x"<<nodo->getNodoDerecho()<<"[arrowhead = normaltee];"<<endl;
    }

    graficarArbol(nodo->getNodoIzquierdo());
    graficarArbol(nodo->getNodoDerecho());
}


template<typename T>
void Arbol<T>::preOrden(Nodo<T> *nodo) {
    if (nodo != nullptr) {
      cout << nodo->getValor() << " ";
      preOrden(nodo->getNodoIzquierdo());
      preOrden(nodo->getNodoDerecho());
    }
}

template<typename T>
void Arbol<T>::inOrden(Nodo<T> *nodo) {
    if (nodo != nullptr) {
      inOrden(nodo->getNodoIzquierdo());
      cout << nodo->getValor() << " ";
      inOrden(nodo->getNodoDerecho());
    }
}

template<typename T>
void Arbol<T>::postOrden(Nodo<T> *nodo) {
    if (nodo != nullptr) {
      postOrden(nodo->getNodoIzquierdo());
      postOrden(nodo->getNodoDerecho());
      cout << nodo->getValor() << " ";
    }
}
