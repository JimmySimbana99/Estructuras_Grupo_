#pragma once

#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arbol {
private:
    Nodo* raiz = nullptr;
    Nodo* nulo;
    ofstream archivo;
    string ruta = "D:\\ProyectoTerminado2PEstruturas\\Proyecto\\Proyecto";
public:

    Arbol();
    //funciones basicas
    void insertar(int dato);
    bool buscar(Nodo* nodo, int valor);
    void eliminar(int dato);

    //Fuciones para arreglar arbol
    void arreglar(Nodo* nodo);
    void arreglarEliminar(Nodo* nodo);

    //Rotaciones
    void rotarIzquierda(Nodo* nodo);
    void rotarDerecha(Nodo* nodo);

    //Recorridos
    void preOrden(Nodo* nodo);
    void inOrden(Nodo* nodo);
    void postOrden(Nodo* nodo);

    //Mostras arbol
    void mostrarArbol(Nodo* raiz, string index, bool last);

    //get y set
    Nodo* getRaiz();

    //Funciones extras a funcoones
    void intercambiar(Nodo* nodo1, Nodo* nodo2);
    Nodo* obtenerMinimo(Nodo* nodo);

    void generarGrafico(string nombre);
    void graficarArbol(Nodo* nodo);

    void borrarArbol();
};