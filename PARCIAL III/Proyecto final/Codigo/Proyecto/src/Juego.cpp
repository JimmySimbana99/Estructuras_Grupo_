#include "Juego.h"

void Juego::iniciar(int ancho,int alto){
    ventana = new RenderWindow(VideoMode(ancho,alto),"TETRIS");
    ventana->setVerticalSyncEnabled(true);
    ventana->setKeyRepeatEnabled(false);
    op.iniciar(ventana);
}

void Juego::renderizar(){
       ventana->clear(Color(153,80,81));
        cargar_fondo();
        op.dibujar_mapa();
        op.dibujar_pieza();
        // op.dibujar_pieza_siguiente();
        ventana->display();
}
void Juego::procesar_logica(){

    game_over = true;
    int i = 0;
    temporizador = 0;
    demora = 0.5;
    cambio = true;
    fstream entrada1;
    int filasEliminadas=0;
    bool comp = true;
    

    int n2;
    n2 = 1 + rand() % 9;
    while (ventana->isOpen() && comp==true)
    {
        float tiempo = reloj.getElapsedTime().asSeconds();
        reloj.restart();
        temporizador += tiempo;

        if (cambio)
        {
            
            op.seleccionar_pieza(n2);
            op.posicionar_pieza();
            n2 = 1 + rand() % 9;
            // op.seleccionar_pieza_siguiente(n2);
            // op.posionar_pieza_siguiente();
            cambio = false;
        }
        
        Event e;
        while (ventana->pollEvent(e))
        {
            if (e.type == sf::Event::Closed){
                ventana->close();
            }
            if (e.type == Event::KeyPressed){
                // if (e.key.code==Keyboard::Up) op.rotar_pieza(1);
                if (e.key.code==Keyboard::Left) op.desplazar_izquierda();
                else if (e.key.code==Keyboard::Right) op.desplazar_derecha();
                else if (e.key.code==Keyboard::Escape) ventana->close();
            }                      
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)){
            demora = 0.03;
        }
        if (temporizador > demora)
        {
            if (op.caer_pieza())
            {
                cambio = true;
                op.encajar_pieza();
                op.verificar_mapa(filasEliminadas,comp);
            }
            
            temporizador = 0;
        }
        demora = 0.5;

        //dibujado
        renderizar();
        if(comp==false){
            ventana->close();
        }
    }
    entrada1.open("Puntajes.txt", fstream::app);
    entrada1<<"Puntaje: "<<filasEliminadas<<" filas removidas";
    entrada1<<"\n";
    entrada1.close();

}

void Juego::cargar_fondo(){

    Texture tx;
    Sprite spr;

    //fondo.png

    if (!tx.loadFromFile("../resources/images/fondo.png"))
    {
        cout<<"no se puedo";
        return;
    }
    spr.setTexture(tx);
    float x_1 = 1000.f / spr.getTexture()->getSize().x;
    float y_1 = 920.f / spr.getTexture()->getSize().y;
    spr.setScale(x_1,y_1);
    ventana->draw(spr);
    
}

