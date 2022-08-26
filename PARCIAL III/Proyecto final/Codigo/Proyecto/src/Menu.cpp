#include "Menu.h"

void Menu::gotoxy(int x,int y){
		HANDLE hcon;
		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X=x;
		dwPos.Y=y;
		SetConsoleCursorPosition(hcon,dwPos);
}


int Menu::crearMenu(string titulo, string *opciones, int nOpciones){
	
	int seleccion = 1,tecla;
	bool repite = true;
	
	do{
		system("cls");
		gotoxy(15,2); cout<<titulo;
		gotoxy(5,3 + seleccion); cout<<">>";
		
		for(int i = 0;i < nOpciones;i++){
			gotoxy(10,4 + i); cout<< (i+1) << "." <<*(opciones+i);
		}
		
		do{
			tecla = getch();
		}while(tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
		
		switch(tecla){
			case ARRIBA:
				seleccion--;
				if(seleccion < 1){
					seleccion = nOpciones;
				}
				break;
			case ABAJO:
				seleccion++;
				if(seleccion > nOpciones){
					seleccion = 1;
				}
				break;
			case ENTER:
				repite = false;
				break;
		}
	
	}while(repite);
	return seleccion;
}

int Menu::menuPrincipal(){
	string *opciones = new string[2];
	*(opciones + 0) = "Jugar ";
    *(opciones + 1) = "Salir";
	return crearMenu("Menu principal", opciones,2);
}

void Menu::abrirFichero(){
	system("cls");
	cout<<"''PUNTAJES''"<<endl;
    ifstream archivo;
    string texto;
    archivo.open("Puntajes.txt",ios::in);
    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}