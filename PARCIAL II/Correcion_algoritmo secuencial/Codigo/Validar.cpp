#include "Validar.h"
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

int Validar::validarNumeros(string msj, int dim)
{
    char dato[dim];
    int i;
    char tecla;
    cout << msj;
    i = 0;
    dato[0] = '\0';
    do
    {

        tecla = getch();
        if (i > 0 && tecla == 8)
        {
            cout << "\b \b";
            dato[--i] = '\0';
        }
        else
        {
            if (i < dim)
            {
                if ((tecla >= 48 && tecla <= 57))
                {
                    cout << tecla;
                    dato[i++] = tecla;
                }
            }
        }

    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';
    string retorno(dato);
    return stoi(retorno);
}
