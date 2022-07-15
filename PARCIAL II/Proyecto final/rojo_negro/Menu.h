#include <iostream>

using namespace std;


class Menu{
	
	public:
		Menu() = default;
		void gotoxy(int,int);
		int crearMenu(string, string *, int);
		int menuPrincipal();
		//submenus();
};
