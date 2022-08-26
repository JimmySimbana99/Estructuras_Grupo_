#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <fstream>
#include "Operaciones.h"

using namespace std;
using namespace sf;

class Juego
{
    private:
        //Atributos propio
        RenderWindow *ventana;
        int fps;
        float temporizador;
        float demora;
	    Clock reloj;
        bool game_over;
        bool cambio;

        Operaciones op;
       
    public:
        Juego() = default;
        void iniciar(int ancho, int alto);
        void iniciar();
        void renderizar();
        void procesar_logica();
        void procesar_eventos();


        //funciones extras

        void cargar_fondo();
};

