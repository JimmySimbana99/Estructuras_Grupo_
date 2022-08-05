/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION

INGENIERIA DE SOFTWARE

AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA DEL JUEGO LAS REINAS

FECHA DE CREACION: 3/8/2022
FECHA MODIFICACION: 5/8/2022


*/
#include "Reina.h"
#include "Validacion.cpp"

reinas::reinas(int t) {
    tam = t;
}

void reinas::GenerarMatrizA() {
    matrizA = (char**) malloc(tam * sizeof (char*));
    for (int i = 0; i < tam; i++) {
        matrizA[i] = (char *) malloc(tam * sizeof (char));
    }

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matrizA[i][j] = ' ';
        }
    }
}

void reinas::GenerarMatrizB() {
    matrizB = (bool**) malloc(tam * sizeof (bool*));
    for (int i = 0; i < tam; i++) {
        matrizB[i] = (bool *) malloc(tam * sizeof (bool));
    }

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matrizB[i][j] = false;
        }
    }
}

void reinas::Reglas(int filas, int columnas) {
    x = columnas;
    y = filas;
    
    int aux1 = x;
    int aux2 = 0;
    while (aux2 < tam) {
        matrizB[aux2][aux1] = true;
        aux2++;
    }
    
    aux1 = 0;
    aux2 = y;
    while (aux1 < tam) {
        matrizB[aux2][aux1] = true;
        aux1++;
    }

    
    aux1 = x;
    aux2 = y;
    while (aux1 > 0 && aux2 > 0) {
        aux1--;
        aux2--;
    }
    while (aux1 < tam && aux2 < tam) {
        matrizB[aux2][aux1] = true;
        aux1++;
        aux2++;
    }

    
    aux1 = x;
    aux2 = y;
    if (aux1 == tam - 1 && aux2 == tam - 1) {
    } else {
        while (aux1 < tam && aux2 > 0) {
            aux1++;
            aux2--;
        }
        if (x + y >= tam) {
            aux1--;
            aux2++;
        }
        while (aux1 >= 0 && aux2 < tam) {
            matrizB[aux1][aux2] = true;
            aux1--;
            aux2++;
        }
    }
}

void reinas::Llenar(int filas, int columnas) {
    matrizA[filas][columnas] = ' ';

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matrizB[i][j] = false;
        }
    }
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (matrizA[i][j] == 'R') {
                Reglas(i, j);
            }
        }
    }
}

void reinas::Imprimir(bool opcion) {
    
    int cont = 0;

    Solucion solucion;
    solucion.asignarMemoria(tam);
    if (opcion) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if(matrizA[i][j]=='R'){
                    Direccion dir;
                    dir.guardarDireccion(i,j);
                    solucion.guardar(dir,cont);
                    cont++;
                }
            }
        }
    } 
    numPosibilidad++;
    listSol.insertarFinal(solucion);
}

void reinas::PonerReina(int filas, int columnas) {
    matrizA[filas][columnas] = 'R';
}

void reinas::Respuesta(int filas, int columnas, int n) {
    PonerReina(filas, columnas);
    Reglas(filas, columnas);
        
    if (n == tam) {
        arbol.insertar(cont);
        cont++;
        Imprimir(true);
    } else {
        for (int i = 0; i < tam; i++) {
            if (matrizB[i][columnas + 1] == false) {
                Respuesta(i, columnas + 1, n + 1);
            }
        }
        Llenar(filas, columnas);
    }
}

int reinas::obtenerPosibilidad(){
    return numPosibilidad;
}

ListaDoble<Solucion> reinas::llamar(){
    return listSol;
}


void reinas::setTam(int _tam){
    tam = _tam;
}

void reinas::pedirReina(int &fila,int &columna){
    Validacion validacion;
    do{
        system("cls");
        cout<<"Ingresar la posicion de su primera reina: "<<endl;
        fila=validacion.validarNum("Fila: ");
        cout<<endl;
        columna=validacion.validarNum("Columna: "); 
        cout<<endl;
    }while((fila<0 || fila>7)||(columna<0 || columna>7));
    
}

void reinas::mostrarArbol(){
    arbol.generarGrafico();
}