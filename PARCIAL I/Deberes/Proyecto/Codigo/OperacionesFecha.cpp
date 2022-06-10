// #include "Fecha.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
/**
 * @brief Ingreso de campo fecha
 * 
 * @param dim 
 * @return int 
 */
static int ingresarCampoFecha(int dim){

    char dato[dim];
	int i,valor;
    char tecla;
    i = 0;
    dato[0] = '\0';
    do
    {

        tecla = getch();
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

    valor = atoi(dato);
    return valor;
}
/**
 * @brief Verificacion de anio bisiesto
 * 
 * @param anio 
 * @return true 
 * @return false 
 */
static bool verificarAnioBisiesto(int anio){

    if(anio % 4 == 0 && anio   % 100 != 0 || anio % 400 == 0){
        return true;
    }else{
        return false;
    }
   
}
/**
 * @brief Validacion de fecha 
 * 
 * @param dia 
 * @param mes 
 * @param anio 
 * @return true 
 * @return false 
 */

static bool validarFecha(int dia, int mes, int anio ){
    
    bool bandera;
    if(anio>=1900 && anio <=2100){
        if(verificarAnioBisiesto(anio )){
            if(mes>=1 && mes<=12){
                if(mes==4 || mes==6 || mes==9 || mes==11){
                    if(dia>=1 && dia<=30){
                        bandera = true;
                    }else{
                        bandera = false;
                    }
                }else if(mes == 2){
                    if(dia>=1 && dia<=29){
                        bandera = true;
                    }else{
                        bandera = false;
                    }
                }else{
                    if(dia>=1 && dia<=31){
                        bandera = true;
                    }else{
                        bandera = false;
                    }
                }
            }else{
                bandera = false;
            }
        }
        else{
            if(mes>=1 && mes<=12){
                if(mes==4 || mes==6 || mes==9 || mes==11){
                    if(dia>=1 && dia<=30){
                        bandera = true;
                    }else{
                        bandera = false;
                    }

                }else if(mes == 2){
                    if(dia>=1 && dia<=28){
                        bandera = true;
                    }else{
                        bandera = false;
                    }
                }else{
                    if(dia>=1 && dia<=31){
                        bandera = true;
                    }else{
                        bandera = false;
                    }
                }
            }else{
                bandera = false;
            }
        }
    }else{
        bandera = false;
    }

    return bandera;
}
/**
 * @brief Ingreso de Fecha

 * 
 * @return string 
 */
static string ingresarFecha(){
    
    stringstream s;
    bool verificador;
    
    // vector<int> fecha;
    int dia,mes,anio;
    do
    {
        dia=0;mes=0;anio=0;
        cout<<"\nIngrese la fecha en formato dd/mm/aa: ";
        dia = ingresarCampoFecha(2);
        cout<<"/";
        mes = ingresarCampoFecha(2);
        cout<<"/";
        anio = ingresarCampoFecha(4);
        verificador = validarFecha(dia,mes,anio);
        if(verificador == false){
            cout<<endl;
            cout << "\e[A\r\e[0K";
        }
    } while (verificador == false);

    s<<dia<<"/"<<mes<<"/"<<anio;

    return s.str();
}