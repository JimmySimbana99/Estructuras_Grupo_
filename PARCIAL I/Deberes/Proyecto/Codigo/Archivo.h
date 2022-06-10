#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Archivo
{
private:
    
    

public:
    Archivo() = default;

    void agregar(string nombreArchivo, string dato);
    vector<string> leer(string nombreArchivo);
};

void Archivo::agregar(string nombreArchivo, string dato)
{
    ofstream escritura;
    escritura.open(nombreArchivo + ".txt", ios::out | ios::app);
    escritura << dato << "\n";
    escritura.close();
}

vector<string> Archivo::leer(string nombreArchivo){
    ifstream lectura;
    system("cls");


    lectura.open(nombreArchivo + ".txt", ios::in);

    vector<string> lineas;
    string linea;
    while (getline(lectura, linea))
    {
        if(!(linea == "")){
            lineas.push_back(linea);
        }
    }
    return lineas;    
}