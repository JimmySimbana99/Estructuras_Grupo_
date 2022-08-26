#include <iostream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>


#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;

class Menu{
	public:
		Menu() = default;
		void gotoxy(int,int);
		int crearMenu(string, string *, int);
		int menuPrincipal();
        void abrirFichero();
};
