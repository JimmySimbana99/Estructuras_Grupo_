#pragma once
#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <windows.h>

using namespace cv;

using namespace std;
class Imagen {
private:
    Mat imagen;
    string nombre;
    int alto;
    int ancho;
public:
    Imagen() = default;
    bool cargarImagen(string nombre);
    void mostrarImagen();
    void obtenerPixeles();
};
