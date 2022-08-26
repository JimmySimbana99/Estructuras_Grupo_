
#include "Juego.h"
#include "Menu.h"

using namespace sf;
int main() {
    int opc = 0;
    Menu menu;
    Juego juego;
    srand(time(0));


    do {
        system("cls");
        opc = menu.menuPrincipal();

        switch (opc) {
            case 1:
                juego.iniciar(650, 920);
                juego.procesar_logica();
                break;
        }
    } while (opc != 2);
    return 0;
}