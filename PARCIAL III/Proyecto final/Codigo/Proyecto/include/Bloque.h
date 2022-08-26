#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

class Bloque {
private:
    int x;
    int y;
    int dim = 40;
    RectangleShape *bloque;

    Texture *t1;
    Sprite *sp1;

    Texture *t2;
    Sprite *sp2;

    Texture *t3;
    Sprite *sp3;

    Texture *t4;
    Sprite *sp4;

    Texture *t5;
    Sprite *sp5;

    Texture *t6;
    Sprite *sp6;

    Texture *t7;
    Sprite *sp7;

    Texture *t8;
    Sprite *sp8;


    Texture *t9;
    Sprite *sp9;

    Texture *text_bloque;
    Sprite *spr_bloque;
    int color;

public:
    Bloque();

    int getX();
    void setX(int newX);

    int getY();
    void setY(int newY);

    int getDim();
    void setDim(int newDim);

    RectangleShape *getBloque();
    void setBloque(RectangleShape *newBloque);

    Sprite *getSprite_num(int n);
    void setSprite(Sprite *newSprite);

    Sprite *getSprite();

    Color getColor_RGB(int n);
};