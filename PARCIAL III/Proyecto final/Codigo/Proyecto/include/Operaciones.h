#include <iostream>
#include <cstdlib>
#include "Mapa.h"
#define velocidad 1
using namespace std;

class Operaciones
{
    private:
        RenderWindow *ventana;

        //mapa
        Mapa mapa;
        //piezas
        Pieza seleccionada;
        Pieza siguiente;

         RectangleShape *cuadro;
         Texture *tex;
         Sprite *spr;


    public:
        Operaciones() = default;
        void iniciar(RenderWindow *_ventana);



        //logica
        void seleccionar_pieza(int n);
        void seleccionar_pieza_siguiente(int n);
        Pieza llamar_pieza(int seleccionada);
        void posicionar_pieza();
        

        //proceso de caida

        bool caer_pieza();
        void desplazar_derecha();
        void desplazar_izquierda();
        void rotar_pieza(int n);
        void encajar_pieza();

        void poner();


        void verificar_mapa(int &filasEliminadas,bool &compare);
        //dibujado
        void dibujar_mapa();
        void dibujar_pieza();

        //calcularAdyacentes
        bool verificarColision();

        // //siguiente
        // void dibujar_cuadro_siguiente();
        // void posionar_pieza_siguiente();
        // void dibujar_pieza_siguiente();
    
        
};