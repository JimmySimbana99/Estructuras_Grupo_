#pragma once

class Nodo {
private:
    int dato = 0;
    Nodo* padre;
    Nodo* izquierdo;
    Nodo* derecho;
    int color;

public:

    Nodo() = default;
    Nodo(int _dato);

    int getDato();
    void setDato(int newDato);

    Nodo* getPadre();
    void setPadre(Nodo* newPadre);

    Nodo* getIzquierdo();
    void setIzquierdo(Nodo* newIzquierdo);

    Nodo* getDerecho();
    void setDerecho(Nodo* newDerecho);

    int getColor();
    void setColor(int newColor);
};