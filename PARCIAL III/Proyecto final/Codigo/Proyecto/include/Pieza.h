#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bloque.h"
using namespace sf;
using namespace std;
/*

*/

#define x_dim 100;
#define y_dim 60;
class Pieza
{
    private:
        Bloque central;
        // Bloque *adyacentes;
        bool estado;
        int dim = 40;
        RenderWindow *ventana;

        int num_seleccionado;

        int color;
    public:
        Pieza() = default;
        Pieza(int seleccionado,RenderWindow *_ventana);
        // Pieza (int x1, int y1, int x2, int y2, int x3, int y3,RenderWindow *_ventana);
        
        void ubicar_pieza(int x, int y);
        void ubicar_pieza_siguiente(int dx,int dy);
        void dibujar_pieza();

        Vector2f obtener_posicion();

        // Bloque* getAdyacentes();
        
        void rotar_pieza_derecha();
        void rotar_pieza_izquierda();

        Vector2f obtener_posicionBloque(int nBloque);

        int getColor();

        Color getColor_RGB(int n);

        

};