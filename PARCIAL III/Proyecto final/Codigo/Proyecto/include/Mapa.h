#include <SFML/Graphics.hpp>
#include "Pieza.h"
using namespace sf;

class Mapa
{
    private:
        int filas;
        int columnas;
        int dim;
        RenderWindow *ventana;
        int tablero[20][10];
        Bloque *bl;

        Texture *tex;
        Sprite *spr;

        //operaciones
        
        
    public:
        Mapa() = default;
        void iniciar(RenderWindow *_ventana);
        void iniciar_tablero();
        void encajar_pieza(Pieza pieza);
        void dibujar();
        //pruebas
        void poner_pieza();

        //
        bool verificarPosicion(int x,int y);
        //
        void compararMapa();
        void dibujarMapa(int,int,int);


        //Por hacer
        void actualizar_tablero(int &puntaje);
        void actualizar_tablero1();
        bool verificar_fila(int fila);
        void verificar_columna(int columna);
        void mover_fila(int fila);

        void verificar_PrimeraPieza(bool &compare);
};

