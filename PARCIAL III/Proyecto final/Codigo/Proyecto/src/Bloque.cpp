#include "Bloque.h"

Bloque::Bloque() {
    t1 = new Texture();
    sp1 = new Sprite();

    t2 = new Texture();
    sp2 = new Sprite();

    t3 = new Texture();
    sp3 = new Sprite();

    t4 = new Texture();
    sp4 = new Sprite();

    t5 = new Texture();
    sp5 = new Sprite();

    t6 = new Texture();
    sp6 = new Sprite();

    t7 = new Texture();
    sp7 = new Sprite();

    t8 = new Texture();
    sp8 = new Sprite();

    t9 = new Texture();
    sp9 = new Sprite();

    t1->loadFromFile("../resources/images/1.png");
    t2->loadFromFile("../resources/images/2.png");
    t3->loadFromFile("../resources/images/3.png");
    t4->loadFromFile("../resources/images/4.png");
    t5->loadFromFile("../resources/images/5.png");
    t6->loadFromFile("../resources/images/6.png");
    t7->loadFromFile("../resources/images/7.png");
    t8->loadFromFile("../resources/images/8.png");
    t9->loadFromFile("../resources/images/9.png");

    t1->setSmooth(true);
    t2->setSmooth(true);
    t3->setSmooth(true);
    t4->setSmooth(true);
    t5->setSmooth(true);
    t6->setSmooth(true);
    t7->setSmooth(true);
    t8->setSmooth(true);
    t9->setSmooth(true);
    sp1->setTexture(*t1);
    sp2->setTexture(*t2);
    sp3->setTexture(*t3);
    sp4->setTexture(*t4);
    sp5->setTexture(*t5);
    sp6->setTexture(*t6);
    sp7->setTexture(*t7);
    sp8->setTexture(*t8);
    sp9->setTexture(*t9);


    // if (!t1->loadFromFile("../resources/images/1.png") && !t2->loadFromFile("../resources/images/2.png") &&
    // !t3->loadFromFile("../resources/images/3.png"))
    // {
    //     cout<<"\n No se pudo cargar la imagen";
    // }else{
    //     t1->setSmooth(true);
    //     t2->setSmooth(true);
    //     t3->setSmooth(true);
    //     sp1->setTexture(*t1);
    //     sp2->setTexture(*t2);
    //     sp3->setTexture(*t3);
    // }


    bloque = new RectangleShape(Vector2f(dim, dim));

    text_bloque = new Texture;
    spr_bloque = new Sprite;

    if (!text_bloque->loadFromFile("../resources/images/bloque.png")) {
        cout << "\n No se pudo cargar la imagen";
    } else {
        text_bloque->setSmooth(true);
        spr_bloque->setTexture(*text_bloque);
    }
    /*
        0 = cyan
        1 = amarillo
        2 = verde
        3 = rojo
        4 = morado
        5 = naranja
        6 = azul

    */
}

int Bloque::getX() {
    return x;
}

void Bloque::setX(int newX) {
    x = newX;
}

int Bloque::getY() {
    return y;
}

void Bloque::setY(int newY) {
    y = newY;
}

int Bloque::getDim() {
    return dim;
}

void Bloque::setDim(int newDim) {
    dim = newDim;
}

RectangleShape *Bloque::getBloque() {
    return bloque;
}
void Bloque::setBloque(RectangleShape *newBloque) {
    bloque = newBloque;
}


Sprite *Bloque::getSprite_num(int n) {
    switch (n) {
        case 1:
            return sp1;
            break;

        case 2:
            return sp2;
            break;

        case 3:
            return sp3;
            break;
        case 4:
            return sp4;
            break;

        case 5:
            return sp5;
            break;

        case 6:
            return sp6;
            break;

        case 7:
            return sp7;
            break;

        case 8:
            return sp8;
            break;

        case 9:
            return sp9;
            break;
    }
}

Sprite *Bloque::getSprite() {
    return spr_bloque;
}

void Bloque::setSprite(Sprite *newSprite) {
    spr_bloque = newSprite;
}

Color Bloque::getColor_RGB(int n) {
    Color color;

    switch (n) {
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