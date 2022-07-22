#include "Nodo.h"

Nodo::Nodo(int _dato) {
    dato = _dato;
}


int Nodo::getDato() {
    return dato;
}

void Nodo::setDato(int newDato) {
    dato = newDato;
}

Nodo* Nodo::getPadre() {
    return padre;
}

void Nodo::setPadre(Nodo* newPadre) {
    padre = newPadre;
}

Nodo* Nodo::getIzquierdo() {
    return izquierdo;
}

void Nodo::setIzquierdo(Nodo* newIzquierdo) {
    izquierdo = newIzquierdo;
}

Nodo* Nodo::getDerecho() {
    return derecho;
}

void Nodo::setDerecho(Nodo* newDerecho) {
    derecho = newDerecho;
}

int Nodo::getColor() {
    return color;
}

void Nodo::setColor(int newColor) {
    color = newColor;
}