
template <typename T>
class Nodo{
    private:
        T valor;
        Nodo<T> *derecha = nullptr;
        Nodo<T> *izquierda = nullptr;
    public:
        Nodo()=default;
        T getValor();
        void setValor(T _valor);

        Nodo<T>* getNodoDerecho();
        void setNodoDerecho(Nodo<T>* _nodoDerecho);

        Nodo<T>* getNodoIzquierdo();
        void setNodoIzquierdo(Nodo<T>* _nodoIzquierdo);
};

template <typename T>
Nodo<T>* Nodo<T>::getNodoDerecho(){
    return this->derecha;
}

template <typename T>
Nodo<T>* Nodo<T>::getNodoIzquierdo(){
    return this->izquierda;
}

template <typename T>
T Nodo<T>::getValor(){
    return this->valor;
}

template <typename T>
void Nodo<T>::setNodoDerecho(Nodo<T> *_nodoDerecho){
    this->derecha = _nodoDerecho;
}

template <typename T>
void Nodo<T>::setNodoIzquierdo(Nodo<T> *_nodoIzquierdo){
    this->izquierda=_nodoIzquierdo;
}

template<typename T>
void Nodo<T>::setValor(T val){
    this->valor = val; 
}

