#include "Operaciones.h"

void Operaciones::iniciar(RenderWindow *_ventana){
    
    ventana = _ventana;
    tex = new Texture;
    spr = new Sprite;

    if (!tex->loadFromFile("../resources/images/cuadro1.png"))
    {
        cout<<"\n No se pudo cargar la imagen";
    }else{
        tex->setSmooth(true);
        spr->setTexture(*tex);
    }

    mapa.iniciar(ventana);
    mapa.iniciar_tablero();
    cuadro = new RectangleShape(Vector2f(350,260));
}



void Operaciones::seleccionar_pieza(int n){


    seleccionada = llamar_pieza(n);
}

void Operaciones::seleccionar_pieza_siguiente(int n){
    siguiente = llamar_pieza(n);
}

void Operaciones::posicionar_pieza(){
    
    
    int posX;

    posX = 1 + rand() % 7;

    seleccionada.ubicar_pieza(posX,1);
}


bool Operaciones::caer_pieza(){
    
    Vector2f posicion;
    int y;
    posicion = seleccionada.obtener_posicionBloque(0);
    y = posicion.y;
    y += velocidad;
    seleccionada.ubicar_pieza(posicion.x,y);
    if(verificarColision()){
        y -= velocidad;
        seleccionada.ubicar_pieza(posicion.x,y);
        return true;
    }

    return false;
}

void Operaciones::desplazar_derecha(){
    Vector2f posicion;
    int x;
    posicion = seleccionada.obtener_posicion();
    x = posicion.x;
    x += velocidad;
    seleccionada.ubicar_pieza(x,posicion.y);
    if(verificarColision()){
        x-=velocidad;
        seleccionada.ubicar_pieza(x,posicion.y);
    }
}

void Operaciones::desplazar_izquierda(){
    Vector2f posicion;
    int x;
    posicion = seleccionada.obtener_posicion();
    x = posicion.x;
    
    x -= velocidad;
    seleccionada.ubicar_pieza(x,posicion.y);
    if(verificarColision()){
        x+=velocidad;
        seleccionada.ubicar_pieza(x,posicion.y);
    }
}

bool Operaciones::verificarColision(){
    Vector2f posicion;
    // for(int i=0;i<4;i++){
         posicion = seleccionada.obtener_posicionBloque(0);
         if(posicion.x < 0 || posicion.x >= 10){
             return true;
         }
         if(posicion.y < 0 ||  posicion.y >= 20){
             return true;
         }if(mapa.verificarPosicion(posicion.x,posicion.y)){
             return true; 
         }
    // }
    return false;
}


// void Operaciones::rotar_pieza(int n){
//     if(n==1){
//         seleccionada.rotar_pieza_derecha();
//         if (verificarColision() || seleccionada.getColor() == 2)
//         {
//             seleccionada.rotar_pieza_izquierda();
//         }
        
//     }else{
//         seleccionada.rotar_pieza_izquierda();
//         if (verificarColision() || seleccionada.getColor() == 2)
//         {
//             seleccionada.rotar_pieza_derecha();
//         }
//     }
// }

void Operaciones::encajar_pieza(){
    mapa.encajar_pieza(seleccionada);
}


Pieza Operaciones::llamar_pieza(int seleccionada){

    Pieza pieza(seleccionada,ventana);

    return pieza;
    
    // Pieza I(0,-1,0,1,0,2,ventana);
    // Pieza O(0,-1,1,-1,1,0,ventana);
    // Pieza S(-1,0,0,-1,1,-1,ventana);
    // Pieza Z(-1,-1,0,-1,1,0,ventana);
    // Pieza T(-1,0,0,-1,1,0,ventana);
    // Pieza L(-1,1,0,1,0,-1,ventana);
    // Pieza J(1,1,0,1,0,-1,ventana);


    // switch (seleccionada)
    // {
    //     case 1:
            
    //         I.colorear_pieza(seleccionada);
    //         return I;
    //         break;

    //     case 2:
    //         O.colorear_pieza(seleccionada);
    //         return O;
    //         break;

    //     case 3:
    //         S.colorear_pieza(seleccionada);
    //         return S;
    //         break;
        
    //     case 4:
    //         Z.colorear_pieza(seleccionada);
    //         return Z;
    //         break;

    //     case 5:
    //         T.colorear_pieza(seleccionada);   
    //         return T;
    //         break;

    //     case 6:
    //         L.colorear_pieza(seleccionada);
    //         return L;
    //         break;

    //     case 7:
    //         J.colorear_pieza(seleccionada);
    //         return J;
    //         break;

    // }
}


void Operaciones::dibujar_mapa(){
    mapa.dibujar();
    // dibujar_cuadro_siguiente();
    mapa.compararMapa();
}

void Operaciones::dibujar_pieza(){
    seleccionada.dibujar_pieza();
}

void Operaciones::verificar_mapa(int &filasEliminadas,bool &compare){

    mapa.actualizar_tablero1();
    mapa.verificar_PrimeraPieza(compare);
}
// void Operaciones::dibujar_cuadro_siguiente(){

//     spr->setPosition(550,80);
//     float x_1;
//     float y_1;

//     x_1 = 350.f / spr->getTexture()->getSize().x;
//     y_1 = 290.f / spr->getTexture()->getSize().y;

//     spr->setScale(x_1,y_1);

//     // cuadro->setPosition(550,90);
//     // cuadro->setFillColor(Color::Transparent);
//     // cuadro->setOutlineThickness(10);
//     // cuadro->setOutlineColor(sf::Color(255, 155, 155));


//     ventana->draw(*spr);



// }

// void Operaciones::posionar_pieza_siguiente(){
//     int color = siguiente.getColor();

//     int dx, dy;

//     if(color == 3 || color == 4 || color == 5){
//         dx = 0;dy = 50;
//     }
//     else if (color == 6)
//     {
//         dx = 20; dy = 40;

//     }else if(color == 7){
//         dx = -5; dy = 40;
//     }
//     else if (color == 2)
//     {
//         dx = -30; dy = 40;
//     }
    
    
//     siguiente.ubicar_pieza_siguiente(dx,dy);
// }

// void Operaciones::dibujar_pieza_siguiente(){
    
//     siguiente.dibujar_pieza();
// }
