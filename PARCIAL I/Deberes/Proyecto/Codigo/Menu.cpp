
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "Menu.h"

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define AYUDA 60
using namespace std;

void Menu::gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int Menu::crearMenu(string titulo, string *opciones, int nOpciones)
{

	int seleccion = 1, tecla;
	bool repite = true;

	do
	{
		system("cls");
		gotoxy(15, 2);
		cout << titulo;
		gotoxy(15, 3);
		cout << "Presione la tecla F1 para ayuda";
		gotoxy(5, 5 + seleccion);
		cout << ">>";

		for (int i = 0; i < nOpciones; i++)
		{
			gotoxy(10, 6 + i);
			cout << (i + 1) << "." << *(opciones + i);
		}

		do
		{
			tecla = getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER && tecla != AYUDA);

		switch (tecla)
		{
		case ARRIBA:
			seleccion--;
			if (seleccion < 1)
			{
				seleccion = nOpciones;
			}
			break;
		case ABAJO:
			seleccion++;
			if (seleccion > nOpciones)
			{
				seleccion = 1;
			}
			break;
		case AYUDA:
			seleccion = 10;
			repite = false;
			break;

		case ENTER:
			repite = false;
			break;
		}

	} while (repite);
	return seleccion;
}

int Menu::menuPrincipal()
{
	string *opciones = new string[6];

	*(opciones + 0) = "Registrar Vehiculo";
	*(opciones + 1) = "Mostrar Vehiculos";
	*(opciones + 2) = "Buscar Vehiculo";
	*(opciones + 3) = "Agregar datos de mantenimiento de mi vehiculo";
	*(opciones + 4) = "Generar Reporte de mantenimiento";
	*(opciones + 5) = "Salir";
	return crearMenu("Menu principal", opciones, 6);

}