#include "Validar.h"
#include <conio.h>
#include <iostream>

using namespace std;
/**
 * @brief Valida el ingreso de espacios y dimensiones 
 * 
 * @param msj 
 * @param dim 
 * @param espacio 
 * @return string 
 */
string Validar::ingreso(string msj, int dim, bool espacio)
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
        if (i < dim)
        {
            if (i > 0 && tecla == 8)
            {
                cout << "\b \b";
                dato[--i] = '\0';
            }
            else
            {
                if (espacio == false)
                {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) &&
                            tecla != 32 ||
                        (tecla >= 48 && tecla <= 57))
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
                else
                {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) ||
                        tecla == 32 || (tecla >= 48 && tecla <= 57))
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
            }
        }
    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';
    string retorno(dato);
    return retorno;
}
/**
 * @brief Validacion de ingreso de campo fecha
 * 
 * @param dim 
 * @return int 
 */
int Validar::ingresarCampoFecha(int dim){

    char dato[dim];
	int i,valor;
    char tecla;
    i = 0;
    dato[0] = '\0';
    do
    {

        tecla = getch ();
        if ( i > 0 && tecla == 8 ){
            cout<<"\b \b";
            dato[--i] = '\0';
        }else{
	        if(i<dim){
				if ( (tecla >= 48 && tecla <= 57)){
	                cout<<tecla;
	                dato[i++] = tecla;
	            }
	        }
		}
        
		
    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';

    valor=atoi(dato);
    return valor;
}
/**
 * @brief Valida las letras
 * 
 * @param msj 
 * @param dim 
 * @param espacio 
 * @return string 
 */
string Validar::validarLetras(string msj, int dim, bool espacio)
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
        if (i < dim)
        {
            if (i > 0 && tecla == 8)
            {
                cout << "\b \b";
                dato[--i] = '\0';
            }
            else
            {
                if (espacio == false)
                {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) &&
                            tecla != 32)
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
                else
                {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) ||
                        tecla == 32)
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
            }
        }
    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';
    string retorno(dato);
    return retorno;
}
/**
 * @brief Valida los numeros
 * 
 * @param msj 
 * @param dim 
 * @return string 
 */
string Validar::validarNumeros(string msj, int dim)
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
    return retorno;
}

// double Validar::validarNumerosDecimales(string msj,int dim){
//     char dato[dim];
// 	int i;
//     char tecla;
//     cout<<msj;
//     i = 0;
//     dato[0] = '\0';
//     do
//     {

//         tecla = getch ();
//         if ( i > 0 && tecla == 8 ){
//             cout<<"\b \b";
//             dato[--i] = '\0';
//         }else{
// 	        if(i<dim){
// 				if ( (tecla >= 48 && tecla <= 57)){
// 	                cout<<tecla;
// 	                dato[i++] = tecla;
// 	            }
// 	        }
// 		}

//     } while ((tecla != 13 || dato[0] == '\0'));
//     dato[i] = '\0';
//     string retorno(dato);
//     return retorno;
// }
string Validar::validarCedula()
{
    bool verificador;
    string cedula;
    do
    {
        cedula = validarNumeros("cedula: ", 10);
        char *cedulaAux = (char *)cedula.c_str();
        int *numeros = new int[10];
        for (int i = 0; i < 10; i++)
        {
            *(numeros + i) = *(cedulaAux + i) - 48;
        }

        int impares = 0, pares = 0, res;
        int suma = 0, resul;
        for (int i = 0; i < 9; i += 2)
        {
            if ((*(numeros + i) * 2) > 9)
            {
                (*(numeros + i)) *= 2;
                do
                {
                    res = (*(numeros + i)) / 10;
                    (*(numeros + i)) = (*(numeros + i)) % 10;
                    impares += (*(numeros + i));
                    (*(numeros + i)) = res;
                } while ((*(numeros + i)) != 0);
            }
            else
            {
                impares += ((*(numeros + i)) * 2);
            }
        }
        for (int i = 1; i < 9; i += 2)
        {
            pares += (*(numeros + i));
        }
        suma = impares + pares;
        resul = (suma / 10 + 1) * 10;
        resul -= suma;
        if ((*(numeros + 9)) == 0)
        {
            (*(numeros + 9)) = 10;
            if ((*(numeros + 9)) == resul)
            {
                verificador = true;
            }
        }
        else
        {
            if (resul == (*(numeros + 9)))
            {
                verificador = true;
            }
            else
            {
                verificador = false;
                cout << endl;
                cout << "\e[A\r\e[0K";
            }
        }
    } while (!verificador);
    return cedula;
}

string Validar::validarTelfeno()
{
    bool verificador;
    string telefono;
    do
    {
        verificador = true;
        telefono = validarNumeros("Telefono: ", 10);
        if (telefono.length() != 10)
        {
            verificador = false;
            cout << endl;
            cout << "\e[A\r\e[0K";
        }
    } while (verificador == false);

    return telefono;
}
