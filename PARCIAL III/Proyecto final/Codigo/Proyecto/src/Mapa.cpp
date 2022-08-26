#include <ctime>
#include "Mapa.h"
#include <conio.h>
#include <iostream>  
#include <windows.h> 
using namespace std;

void Mapa::iniciar(RenderWindow *_ventana){
    filas = 20;
    columnas = 10;
    dim = 40;
    ventana = _ventana;

    tex = new Texture;
    spr = new Sprite;

    if (!tex->loadFromFile("../resources/images/fondo.png"))
    {
        cout<<"\n No se pudo cargar la imagen";
    }else{
        spr->setTexture(*tex);
    }
    bl = new Bloque;

}

void Mapa::iniciar_tablero(){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // *(*(tablero + i) + j) = 0;
            tablero[i][j] = 0;
        }   
    }
    
}

void Mapa::encajar_pieza(Pieza pieza){
    Vector2f posicion;
    int x,y;
    // for (int i = 0; i < 4; i++)
    // {
        posicion = pieza.obtener_posicionBloque(0);
        x = posicion.x;
        y = posicion.y;
        tablero[y][x] = pieza.getColor();
    // }
    
}



void Mapa::dibujar(){
    spr->setPosition(94,54);
    float x_1 = 413.f / spr->getTexture()->getSize().x;
    float y_1 = 813.f / spr->getTexture()->getSize().y;
    spr->setScale(x_1,y_1);
    ventana->draw(*spr);


    RectangleShape linea_vertical(Vector2f(1,filas * dim));
    RectangleShape linea_horizontal(Vector2f(columnas * dim,1));

    int x, y;

    x = 100;
    y = 60;

    for (int  i = 0; i <= columnas; i++)
    {
        if (i == 0 || i == columnas)
        {
            linea_vertical.setFillColor(Color(150,152,154));
        }else{
            linea_vertical.setFillColor(Color(150,152,154));
        }
        
        linea_vertical.setPosition(x,60);
        ventana->draw(linea_vertical);
        x += dim;
    }

    

    for (int i = 0; i <= filas; i++)
    {
        if (i == 0 || i == filas)
        {
            linea_horizontal.setFillColor(Color(150,152,154));
        }else{
            linea_horizontal.setFillColor(Color(150,152,154));
        }
        
        linea_horizontal.setPosition(100,y);
        ventana->draw(linea_horizontal);
        y += dim;
    }
}

bool Mapa::verificarPosicion(int x,int y){
    if(tablero[y][x] != 0){
        return true; 
    }
    return false;


}

void Mapa::compararMapa(){
    for(int i= 0; i < filas; i++){
        for(int j=0;j < columnas; j++){
            if(tablero[i][j] != 0){
                dibujarMapa(j,i,tablero[i][j]);
            }
        }
    }
}

void Mapa::dibujarMapa(int x,int y,int color){

    bl->setX(x);
    bl->setY(y);

    bl->getBloque()->setPosition(100 + (x * dim),60 + (y * dim));

     float x_1 = 40.f / bl->getSprite_num(color)->getTexture()->getSize().x;
     float y_1 = 40.f / bl->getSprite_num(color)->getTexture()->getSize().y;

    bl->getSprite_num(color)->setPosition(100 + (x * dim),60 + (y * dim));
    bl->getSprite_num(color)->setScale(x_1,y_1);

    // bl->getSprite_num(color)->setColor(bl->getColor_RGB(color));
    // bl.getBloque()->setFillColor(bl->getColor_RGB(color));
    // ventana->draw(*bl.getBloque());
    ventana->draw(*bl->getSprite_num(color));
}

void Mapa::actualizar_tablero(int &puntaje){
     int fila = filas - 1;

    while (fila >= 0)
    {
        if (verificar_fila(fila))
        {
            puntaje++;
            mover_fila(fila);
        }else{
            fila--;
        }
        
        
    }
    
}

void Mapa::actualizar_tablero1(){
     int colum = columnas - 1;

    while (colum >= 0)
    {
        
        verificar_columna(colum);
        // if (verificar_fila(fila))
        // {
        //     puntaje++;
        //     // mover_fila(fila);
        // }else{
        //     fila--;
        // }

        colum--;
        
        
    }
    
}

bool Mapa::verificar_fila(int fila){
    for (int i = 0; i < columnas; i++)
    {
        if (tablero[fila][i] == 0)
        {
            return false;
        }    
    }
    return true;
}

void Mapa::verificar_columna(int columna){

    int cont = 0;
    int valor1,valor2;
    for (int i = 0; i < filas; i++)
    {
        if ((tablero[i][columna] == tablero[i+1][columna]) && (i+1) < filas && tablero[i][columna] != 0)
        {
            tablero[i][columna] = 0;
            tablero[i+1][columna] = 0;
            return;
        }
        
    }
}


void Mapa::mover_fila(int fila){
    for (int i = fila; i > 0; i--)
    {
        for (int j = 0; j < columnas; j++)
        {
            tablero[i][j] = tablero[i-1][j];
        }
        
    }

    for (int i = 0; i < columnas; i++)
    {
        tablero[0][i] = 0;
    }
    
    
}


void Mapa::verificar_PrimeraPieza(bool &compare){
    for(int i=0;i<columnas;i++){
        if(tablero[0][i]!=0){
            compare = false;
        }
    }
}
