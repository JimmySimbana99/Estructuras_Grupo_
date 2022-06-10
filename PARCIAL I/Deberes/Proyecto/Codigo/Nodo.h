template <typename T>
// clase nodo para listas circulares dobles
class Nodo
{
private:
public:
    Nodo() = default;
    T dato;
    Nodo *siguiente = nullptr;
    Nodo *anterior = nullptr;
    Nodo(T _dato);
    T getDato();
    void setDato(T newDato);

    Nodo *getSiguiente();
    void setSiguiente(Nodo *newSiguiente);

    Nodo *getAnterior();
    void setAnterior(Nodo *newAnterior);
};

template <typename T>
Nodo<T>::Nodo(T _dato)
{
    this->dato = _dato;
}

template <typename T>
T Nodo<T>::getDato()
{
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T newDato)
{
    dato = newDato;
}

template <typename T>
Nodo<T> *Nodo<T>::getSiguiente()
{
    return siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo *newSiguiente)
{
    siguiente = newSiguiente;
}

template <typename T>
Nodo<T> *Nodo<T>::getAnterior()
{
    return anterior;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo *newAnterior)
{
    anterior = newAnterior;
}
