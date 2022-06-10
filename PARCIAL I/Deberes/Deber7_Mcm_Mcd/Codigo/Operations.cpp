#include "Operations.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/**
 * @brief Construct a new Operations< H>:: Operations object
 * 
 * @tparam H 
 */
template<typename H>
Operations<H>::Operations(){	
}

 /**
  * @brief This function returns the mcm of two numbers
  * 
  * @tparam H 
  * @param info 
  * @return H 
  */
 template<typename H>
 H Operations<H>::operator /=(Data <H> info){
 	long int num1=info.getData();
 	long int num2=info.getValue();
 	long int a,b,res,mcm;
 	if(num1>num2){
		a=num1;
		b=num2;
	}else{
		a=num2;
		b=num1;
	}
	do{
		res=b;
		b=a%b;
		a=res;
	}while(b!=0);
 	mcm=num1*num2/res;
 	return (mcm);
 }
