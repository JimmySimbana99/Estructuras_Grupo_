#include "Imagen.h"

bool Imagen::cargarImagen(string nombre) {
    bool verificador;
    imagen = imread(nombre);

    if (imagen.empty()) {
        verificador = false;
    }
    else {
        verificador = true;
        alto = imagen.rows;
        ancho = imagen.cols;
    }
    return verificador;
}

void Imagen::mostrarImagen() {
    imshow("Logo espe", imagen);
    waitKey(0);
}

void Imagen::obtenerPixeles() {
    int k = 0;
    HWND myconsole = GetConsoleWindow();
    COLORREF COLOR;
    HDC mydc = GetDC(myconsole);

    for (int i = 0; i < alto; i++) {
        k = 0;
        for (int j = 0; j < ancho; j++) {
            Vec3b pixel = imagen.at<Vec3b>(i, j);
            int b = pixel[0];
            int g = pixel[1];
            int r = pixel[2];
            COLOR = RGB(r, g, b);
            SetPixel(mydc, k, i * 2, COLOR);
            k += 3;
        }
    }
    ReleaseDC(myconsole, mydc);
    cin.ignore();
}