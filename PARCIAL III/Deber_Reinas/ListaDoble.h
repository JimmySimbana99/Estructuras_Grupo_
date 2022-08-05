#pragma once
#include "Node.h"
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class ListaDoble{
    
    private:
        int size = 0;
        Node<T> *head = nullptr;
        Node<T> *getLastNode();
        Node<T> *getNode(int index);
    public:
        ListaDoble() = default;
        void insertarPrincipio(T data);
        void insertarFinal(T data);
        void insertarEntre(T data,int index);
        void eliminarNodo(int index);
        void imprimirLista();
        int getSize();
        void setSize(int _size);
        bool empty();
        T sacarPrimerValor();
        int sacarUltimoValor();
        void eliminarPrimerValor();
        T sacarSValor();
        void recorrer(function<void(T data)> obtenerDatos);

        T buscar(int);
};
template<typename T>
T ListaDoble<T>::buscar(int _dim){
    Node<T> *aux = head;
    int j=0;
    while (aux != nullptr){
        if(j==_dim){
            return aux->getValor();
        }
        aux = aux->getNext();
        j++;
    }
    return aux->getValor();
}


template<typename T>
void ListaDoble<T>::recorrer(function<void(T data)> obtenerDatos){
    Node<T> *aux = head;
    while (aux != nullptr){
        obtenerDatos(aux->getValor());
        aux = aux->getNext();
    }
}


template<typename T>
void ListaDoble<T>::eliminarPrimerValor(){
       Node<T> *temp = head;
        head = head->getNext();
        delete(temp);
}
template<typename T>
T ListaDoble<T>::sacarPrimerValor(){
    Node<T> *aux = head;
    return aux->getValor();
}

template <typename T>
T ListaDoble<T>::sacarSValor(){
    Node<T> *aux=head;
    aux = aux->getNext();
    return aux->getValor();
}

template<typename T>
int ListaDoble<T>::sacarUltimoValor(){
    Node<T> *aux = head;
    while (aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux->getValor();
}

template<typename T>
bool ListaDoble<T>::empty(){
    Node<T> *aux = head;
    if(aux != nullptr){
        return false; 
    }else{
        return true;
    }
}

template <typename T>
void ListaDoble<T>::insertarPrincipio(T data){
    Node<T> *newNode = new Node<T>(data);
    if(head == nullptr){
        this->head = newNode;
    }else{
        head->setPrevious(newNode);
        newNode->setNext(head);
        head = newNode;
    }
    size++;
}

template <typename T>
void ListaDoble<T>::insertarFinal(T data){
    
    Node<T> *newNode = new Node<T>(data);

    if(head == nullptr){
        this->head = newNode;
    }else{
        Node<T> *last = getLastNode();
        last->setNext(newNode);
        newNode->setPrevious(last);
    }

    size++;

}

template <typename T>
void ListaDoble<T>::insertarEntre(T dato,int indice){

    if(indice < 0 || indice > size){
        cout<<"Indice fuera de rango"<<endl;
    }

    if(indice == 0 || size== 0){
        return insertarPrincipio(dato);
    }else if(indice == size){
        return insertarFinal(dato);
    }

    Node<T> *now = getNode(indice);
    Node<T> *anterior = now->getPrevious();
    Node<T> *siguiente = now->getNext();

    Node<T> *node = new Node<T>(dato);
    
    anterior->setNext(node);
    node->setNext(now);
    node->setPrevious(anterior);
    now->setPrevious(node);
    size++;
    
}

template <typename T>
void ListaDoble<T>::eliminarNodo(int index){

    if(index < 0 || index > size){
        cout<<"Indice fuera de rango"<<endl;
    }

    if (index == 0) {
        Node<T> *temp = head;
        head = head->getNext();
        head->setPrevious(nullptr);
        delete temp;
    } else if (index == size - 1) {
        Node<T> *node = getLastNode();
        Node<T> *previous = node->getPrevious();
        
        previous->setNext(nullptr);
        delete node;
    } else {
        Node<T> *now = getNode(index);
        Node<T> *previous = now->getPrevious();
        Node<T> *next = now->getNext();
        
        previous->setNext(next);
        next->setPrevious(previous);
        delete now;
    }

    size--;
}

template <typename T>
void ListaDoble<T>::imprimirLista(){
    Node<T> *aux = head;
    while (aux != nullptr){
        cout<<aux->getValor()<<"->";
        aux = aux->getNext();
    }
}

template <typename T>
Node<T>* ListaDoble<T>::getLastNode(){

    Node<T> *aux = head;
    while (aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux;
    
}

template <typename T>
Node<T> *ListaDoble<T>::getNode(int index) {
    if (index < 0 || index >= size) {
        cout<<"Indice fuera de rango"<<endl;
    }

    if (index == 0) {
        return head;
    }

    int indexNow = 0;
    Node<T> *last = head;

    while (last->getNext() != nullptr) {
        if (indexNow == index) {
            break;
        }

        indexNow++;
        last = last->getNext();
    }

    return last;
}

template<typename T>
int ListaDoble<T>::getSize(){
    return this->size; 
}

template<typename T>
void ListaDoble<T>::setSize(int _size){
    this->size = _size; 
}