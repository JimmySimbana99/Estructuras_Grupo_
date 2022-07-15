class Nodo{
    private:
        int dato = 0;
        Nodo *padre;
        Nodo *izquierdo;
        Nodo *derecho;
        int color;
        
    public:
        
        Nodo() = default;
        Nodo(int _dato);

        int getDato();
        void setDato(int newDato);

        Nodo *getPadre();
        void setPadre(Nodo *newPadre);

        Nodo *getIzquierdo();
        void setIzquierdo(Nodo *newIzquierdo);

        Nodo *getDerecho();
        void setDerecho(Nodo *newDerecho);

        int getColor();
        void setColor(int newColor);
};

Nodo::Nodo(int _dato){
    dato = _dato;
}


int Nodo::getDato(){
    return dato;
}

void Nodo::setDato(int newDato){
    dato = newDato;
}

Nodo *Nodo::getPadre(){
    return padre;
}

void Nodo::setPadre(Nodo *newPadre){
    padre = newPadre;
}

Nodo *Nodo::getIzquierdo(){
    return izquierdo;
}

void Nodo::setIzquierdo(Nodo *newIzquierdo){
    izquierdo = newIzquierdo;
}

Nodo *Nodo::getDerecho(){
    return derecho;
}

void Nodo::setDerecho(Nodo *newDerecho){
    derecho = newDerecho;
}

int Nodo::getColor(){
    return color;
}

void Nodo::setColor(int newColor){
    color = newColor;
}


