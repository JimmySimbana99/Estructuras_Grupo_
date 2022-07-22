#pragma once
#include <conio.h>
#include <iostream>

using namespace std;



string static validarNumeros(string msj)
{
    char dato[10];
    int i;
    char tecla;
    cout << msj;
    i = 0;
    dato[0] = '\0';
    do
    {

        tecla = _getch();
        if (i > 0 && tecla == 8)
        {
            cout << "\b \b";
            dato[--i] = '\0';
        }
        else
        {
            if (i < 10)
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
    return retorno;
}