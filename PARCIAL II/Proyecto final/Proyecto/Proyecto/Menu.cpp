#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "Menu.h"


#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;

void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

/**
 * @brief Crear menu
 * 
 * @param titulo 
 * @param opciones 
 * @param nOpciones 
 * @return int 
 */
int Menu::crearMenu(string titulo, string* opciones, int nOpciones) {

	int seleccion = 1, tecla;
	bool repite = true;

	do {
		system("cls");
		gotoxy(15, 2); cout << titulo;
		gotoxy(5, 3 + seleccion); cout << ">>";

		for (int i = 0; i < nOpciones; i++) {
			gotoxy(10, 4 + i); cout << (i + 1) << "." << *(opciones + i);
		}

		do {
			tecla = _getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

		switch (tecla) {
		case ARRIBA:
			seleccion--;
			if (seleccion < 1) {
				seleccion = nOpciones;
			}
			break;
		case ABAJO:
			seleccion++;
			if (seleccion > nOpciones) {
				seleccion = 1;
			}
			break;
		case ENTER:
			repite = false;
			break;
		}

	} while (repite);
	return seleccion;
}
/**
 * @brief Menu principal
 * 
 * @return int 
 */
int Menu::menuPrincipal() {
	string* opciones = new string[5];

	*(opciones + 0) = "Crear Arbol";
	*(opciones + 1) = "Buscar Arbol";
	*(opciones + 2) = "Eliminar Arbol";
	*(opciones + 3) = "Generar punto de restauracion";
	*(opciones + 4) = "Salir";

	return crearMenu("Menu principal", opciones, 5);
}
/**
 * @brief SubMenu
 * 
 * @return int 
 */
int Menu::subMenu() {
	string* opciones = new string[7];

	*(opciones + 0) = "Insertar Nodo";
	*(opciones + 1) = "Buscar Nodo";
	*(opciones + 2) = "Eliminar Nodo";
	*(opciones + 3) = "Mostrar Recorridos";
	*(opciones + 4) = "Pixelar imagen";
	*(opciones + 5) = "Generar Backup";
	*(opciones + 6) = "Salir";

	return crearMenu("Menu principal", opciones, 7);
}