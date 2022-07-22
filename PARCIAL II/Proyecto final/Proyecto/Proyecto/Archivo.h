#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <string>



using namespace std;

class Archivo
{
private:

public:
    Archivo() = default;

    void agregar(string ruta,string nombreArchivo, string dato);
    void agregarLista(string nombreArchivo, string dato);
    vector<string> leer(string ruta, string nombreArchivo);
    void eliminar(string ruta, string nombreArchivo, string dato);
    bool buscarArchivo(string name, string ruta);
};

void Archivo::agregar(string ruta, string nombreArchivo, string dato)
{
    ofstream escritura;
    escritura.open(ruta + "\\" + nombreArchivo + ".txt", ios::out | ios::app);
    escritura << dato << "\n";
    escritura.close();
}

void Archivo::agregarLista(string nombreArchivo, string dato) {
    ofstream escritura;
    escritura.open(nombreArchivo + ".txt", ios::out | ios::app);
    escritura << dato << "\n";
    escritura.close();
}

vector<string> Archivo::leer(string ruta,string nombreArchivo) {
    ifstream lectura;
    system("cls");


    lectura.open(ruta + "\\" + nombreArchivo + ".txt", ios::in);

    vector<string> lineas;
    string linea;
    while (getline(lectura, linea))
    {
        if (!(linea == "")) {
            lineas.push_back(linea);
        }
    }
    return lineas;
}

void Archivo::eliminar(string ruta, string nombreArchivo, string dato) {
    ifstream lectura;
    ofstream escritura;
    lectura.open(ruta + "\\" + nombreArchivo + ".txt", ios::in);
    escritura.open(ruta + "\\" + "aux.txt", ios::out);

    string linea;
    while (getline(lectura, linea))
    {
        if (!(linea == "")) {
            if (linea != dato) {
                escritura << linea << "\n";
            }
        }
    }
    lectura.close();
    escritura.close();
    string rutaAux = ruta + "\\" + "aux.txt";
    //cout << "\nruta: " << ruta << endl;
    //cout << "\nraux: " << rutaAux << endl;
    remove((ruta + "\\" + nombreArchivo + ".txt").c_str());
    //cout << "\ndl: " << ruta + "\\" + nombreArchivo + ".txt" << endl;
    int n = rename(rutaAux.c_str(), (ruta + "\\" + nombreArchivo + ".txt").c_str());
}

bool Archivo::buscarArchivo(string nombre,string ruta) {
    ifstream f(ruta + "\\" + nombre + "\\" + nombre + ".txt");
    return f.good();
}