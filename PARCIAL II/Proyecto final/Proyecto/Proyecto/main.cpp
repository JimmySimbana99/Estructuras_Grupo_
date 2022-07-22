//#include <iostream>

#include "Menu.h"
#include "Operacion.h"
#include <Windows.h>

#include <iostream>
#include <string>
using namespace std;


string nombre;
Operacion op;
Menu menu;
int opc = 0;

void marquesina(std::string text) {
    HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });
    while (true) {
        std::string temp = text;// temp -> JUAN
        text.erase(0, 1); //UAN
        text += temp[0]; //UANJ
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 0, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
 
   }

}

void submenu() {
    do
    {
        opc = menu.subMenu();
        switch (opc) {
        case 1:
            op.insertarEnArbol(nombre);
            break;

        case 2:
            op.buscarEnArbol();
            break;

        case 3:
            op.eliminarDeArbol(nombre);
            break;

        case 4:
            op.MostrarRecorridos();
            break;

        case 5:
            op.mostrarImagen(nombre);
            break;
        case 6:
            op.generarBackup(nombre);
            break;
        }
        cout << "\n";
        system("pause");
    } while (opc != 7);
    
}


int main(int, char**) {



    op.iniciarSesion();
    
    string texto = "UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE ";
    thread t2(marquesina, texto);
    t2.detach();
    
    do
    {
        opc = menu.menuPrincipal();

        switch (opc) {
            case 1:
                nombre = op.crearArbol();

                if (nombre == "Nombre de arbol ya creado") {
                    cout << "\n " << nombre;
                }
                else {
                    submenu();
                }

                break;

            case 2:
                cout << "\n Nombre del arbol: ";
                cin >> nombre;
                if (op.buscarArbol(nombre))
                {
                    submenu();
                }
                else {
                    cout << "\n Archivo no encontrado \n";
                }

                break;

            case 3:
                op.eliminarArbol();
                break;

            case 4:
                op.generarPuntoRestauracion();
                break;
        }
        cout << "\n";
        system("pause");
    } while (opc != 5);
}
