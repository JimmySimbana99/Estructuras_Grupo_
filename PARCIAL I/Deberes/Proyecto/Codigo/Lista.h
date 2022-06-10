#include <iostream>
#include <functional>
#include "Nodo.h"

// clase lista doble circular
using namespace std;
template <typename T>
class Lista
{
private:
    int dimension;
    Nodo<T> *cabeza = nullptr;
    Nodo<T> *cola = nullptr;
    Nodo<T> *obtenerUltimoNodo();
    Nodo<T> *obtenerNodo(int indice);

public:
    Lista() = default;
    void insertar(T dato);
    void Buscar();
    void recorrer(function<void(T valor)> callback);
    void recorrerNodos(function<void(Nodo<T> *nodo)> callback);
    void vaciarLista();

    void insertEntre(T dato, int indice);
    void eliminarNodo(int indice);
    void imprimirListaInicio();
    void imprimirListaFin();
};

template <typename T>
void Lista<T>::insertar(T dato)
{
    Nodo<T> *nuevo = new Nodo<T>(dato);

    if (cabeza == nullptr)
    {
        this->cabeza = nuevo;
        this->cola = nuevo;
        this->cabeza->siguiente = cabeza;
        this->cabeza->anterior = cola;
    }
    else
    {
        this->cola->siguiente = nuevo;
        nuevo->anterior = this->cola;
        nuevo->siguiente = this->cabeza;
        this->cola = nuevo;
        this->cabeza->anterior = this->cola;
    }

    dimension++;
}

template <typename T>
void Lista<T>::Buscar()
{

    Nodo<T> *actual = this->cabeza;

    if (this->cabeza != nullptr)
    {
        do
        {
            cout << actual->dato << "->";

            actual = actual->siguiente;
        } while (actual != this->cabeza);
    }
    else
    {
        cout << "\nLista Vacia";
    }
}

template <typename T>
void Lista<T>::recorrer(function<void(T valor)> callback)
{

    Nodo<T> *actual = this->cabeza;

    if (this->cabeza != nullptr)
    {
        do
        {
            callback(actual->dato);
            actual = actual->siguiente;
        } while (actual != this->cabeza);
    }
    else
    {
        cout << "\nLista Vacia";
    }
}

template <typename T>
void Lista<T>::vaciarLista(){
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
void Lista<T>::eliminarNodo(int indice)
{
}

// Imprime los datos desde el primero al ultimo
template <typename T>
void Lista<T>::imprimirListaInicio()
{
    Nodo<T> *actual = this->cabeza;

    if (this->cabeza != nullptr)
    {
        do
        {
            cout << actual->dato << "->";

            actual = actual->siguiente;
        } while (actual != this->cabeza);
    }
    else
    {
        cout << "\nLista Vacia";
    }
}

template <typename T>
void Lista<T>::imprimirListaFin()
{
    Nodo<T> *actual = this->cola;

    if (this->cabeza != nullptr)
    {
        do
        {
            cout << actual->dato << "->";

            actual = actual->anterior;
        } while (actual != this->cola);
    }
    else
    {
        cout << "\nLista Vacia";
    }
}

template <typename T>
Nodo<T> *Lista<T>::obtenerUltimoNodo()
{
}

template <typename T>
Nodo<T> *Lista<T>::obtenerNodo(int indice)
{
}
