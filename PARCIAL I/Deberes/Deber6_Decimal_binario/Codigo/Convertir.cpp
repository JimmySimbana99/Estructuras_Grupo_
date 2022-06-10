#include "Convertir.h"
#include <stdlib.h>
#include <stdio.h>
#define BIN 2
/**
 * @brief Convertir de decimal a binario
 * 
 * @param val 
 * @param cad 
 */
void Convertir::decimalBinario(int val, char cad[])
	{ 
	if(val>=1)
	{ 
	decimalBinario((val/BIN),cad); 
	strcpy(cad,itoa((val%BIN),cad,10));
    } 
	strcat(cad,"\0");
 	printf("%s",cad);
  } 
  
  