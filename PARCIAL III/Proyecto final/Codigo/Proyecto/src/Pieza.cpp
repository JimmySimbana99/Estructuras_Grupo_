#include "Pieza.h"
#include <ctime>
 Pieza::Pieza(int seleccionado,RenderWindow *_ventana){
     ventana = _ventana;
     num_seleccionado = seleccionado;
 }

// Pieza::Pieza(int x1, int y1, int x2, int y2, int x3, int y3,RenderWindow *_ventana){

//     adyacentes = new Bloque[3];

//     (adyacentes + 0)->setX(x1);
//     (adyacentes + 0)->setY(y1);

//     (adyacentes + 1)->setX(x2);
//     (adyacentes + 1)->setY(y2);

//     (adyacentes + 2)->setX(x3);
//     (adyacentes + 2)->setY(y3);

//     ventana = _ventana;

// }

// void Pieza::colorear_pieza(int color){

//     /*
//         1 = cyan
//         2 = amarillo
//         3 = verde
//         4 = rojo
//         5 = morado
//         6 = naranja
//         7 = azul
//     */
//    this->color = color;

//    central.getSprite()->setColor(getColor_RGB(color));
// //    central.getBloque()->setFillColor(getColor_RGB(color));
//     for (int i = 0; i < 3; i++)
//     {
//         (adyacentes + i)->getSprite()->setColor(getColor_RGB(color));
//     //   (adyacentes + i)->getBloque()->setFillColor(getColor_RGB(color));
//     }
// }


void Pieza::ubicar_pieza(int x, int y){
    
    central.setX(x);
    central.setY(y);

    float x_1;
    float y_1;

    x_1 = 40.f / central.getSprite_num(num_seleccionado)->getTexture()->getSize().x;
    y_1 = 40.f / central.getSprite_num(num_seleccionado)->getTexture()->getSize().y;

    central.getSprite_num(num_seleccionado)->setPosition(100 + (x * dim),60 + (y * dim));
    central.getSprite_num(num_seleccionado)->setScale(x_1,y_1);

    // for (int i = 0; i < 3; i++)
    // {
    //     int posX = 100 + (x * dim);
    //     int posY = 60 + (y * dim);
    //     (adyacentes + i)->getSprite()->setPosition(posX + ((adyacentes + i)->getX() * dim),posY + ((adyacentes + i)->getY() * dim));
    //     x_1 = 40.f / (adyacentes + i)->getSprite()->getTexture()->getSize().x;
    //     y_1 = 40.f / (adyacentes + i)->getSprite()->getTexture()->getSize().y;
    //     (adyacentes + i)->getSprite()->setScale(x_1,y_1);
    // }
    //ubicar con bloques
    // central.setX(x);
    // central.setY(y);
    // central.getBloque()->setPosition(100 + (x * dim),60 + (y * dim));

    // for (int i = 0; i < 3; i++)
    // {
    //     int posX = 100 + (x * dim);
    //     int posY = 60 + (y * dim);
    //     (adyacentes + i)->getBloque()->setPosition(posX + ((adyacentes + i)->getX() * dim),posY + ((adyacentes + i)->getY() * dim));

    // }
    
}

void Pieza::ubicar_pieza_siguiente(int dx,int dy){

    float x_1;
    float y_1;

    x_1 = 55.f / central.getSprite_num(num_seleccionado)->getTexture()->getSize().x;
    y_1 = 55.f / central.getSprite_num(num_seleccionado)->getTexture()->getSize().y;

    central.getSprite_num(num_seleccionado)->setPosition(700 + dx,175 + dy);
    central.getSprite_num(num_seleccionado)->setScale(x_1,y_1);

    // for (int i = 0; i < 3; i++)
    // {
    //     int posX = 700+ dx ;
    //     int posY = 175 + dy;
    //     (adyacentes + i)->getSprite()->setPosition(posX + ((adyacentes + i)->getX() * 55),posY + ((adyacentes + i)->getY() * 55));
    //     x_1 = 55.f / (adyacentes + i)->getSprite()->getTexture()->getSize().x;
    //     y_1 = 55.f / (adyacentes + i)->getSprite()->getTexture()->getSize().y;
    //     (adyacentes + i)->getSprite()->setScale(x_1,y_1);
    // }
}
void Pieza::dibujar_pieza(){
    ventana->draw(*central.getSprite_num(num_seleccionado));

    // for (int i = 0; i < 3; i++)
    // {
    //     ventana->draw(*(adyacentes + i)->getSprite());
    // }

    //dibujar con bloques
    // ventana->draw(*central.getBloque());

    // for (int i = 0; i < 3; i++)
    // {
    //     ventana->draw(*(adyacentes + i)->getBloque());
    // }

    
}


Vector2f Pieza::obtener_posicion(){
    int x,y;

    x = central.getX();
    y = central.getY();

    return Vector2f(x,y);
}

// Bloque* Pieza::getAdyacentes(){
//     return adyacentes;
// }

// void Pieza::rotar_pieza_derecha(){
//     int x,y;
//     for (int i = 0; i < 3; i++)
//     {
//         x = (adyacentes+i)->getX();
//         y=(adyacentes+i)->getY();
//         (adyacentes+i)->setX(-y);
//         (adyacentes+i)->setY(x);
//     }
//     ubicar_pieza(central.getX(),central.getY());
// }

// void Pieza::rotar_pieza_izquierda(){
//     int x,y;
//     for (int i = 0; i < 3; i++)
//     {
//         x = (adyacentes+i)->getX();
//         y=(adyacentes+i)->getY();
//         (adyacentes+i)->setX(y);
//         (adyacentes+i)->setY(-x);
//     }
//     ubicar_pieza(central.getX(),central.getY());
// }
Vector2f Pieza::obtener_posicionBloque(int nBloque){
    Vector2f bloques;
    if(nBloque==0){
        bloques.x=central.getX();
        bloques.y=central.getY();
    }
    // else{
    //     bloques.x=central.getX()+(adyacentes+nBloque-1)->getX();
    //     bloques.y=central.getY()+(adyacentes+nBloque-1)->getY();
    // }
    return bloques;
}

int Pieza::getColor(){
    return num_seleccionado;
}

Color Pieza::getColor_RGB(int n){
    Color color;

    switch (n)
    {
    case 1:
        color.r = 51;
        color.g = 255;
        color.b = 255;
        break;
    case 2:
        color.r = 255;
        color.g = 255;
        color.b = 51;
        break;
    case 3:
        color.r = 153;
        color.g = 255;
        color.b = 51;
        break;
    case 4:
        color.r = 255;
        color.g = 102;
        color.b = 102;
        break;
    case 5:
        color.r = 153;
        color.g = 51;
        color.b = 255;
        break;
    case 6:
        color.r = 255;
        color.g = 153;
        color.b = 51;
        break;
    case 7:
        color.r = 51;
        color.g = 153;
        color.b = 255;
        break;
    }

    return color;

}