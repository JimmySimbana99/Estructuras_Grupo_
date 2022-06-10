#include "Data.h"
/**
 * @brief This function return Data variable
 * 
 * @tparam T 
 * @return T 
 */
template<typename T>
T Data<T>::getData(void){
   return data;
}
/**
 * @brief This function set Data variable
 * 
 * @tparam T 
 * @param newData 
 */
template<typename T>
void Data<T>::setData(T newData){
   this->data = newData;
}
/**
 * @brief This function return Value variable
 * 
 * @tparam T 
 * @return T 
 */
template<typename T>
T Data<T>::getValue(void){
   return value;
}
/**
 * @brief This function set value variable
 * 
 * @tparam T 
 * @param newValue 
 */
template<typename T>
void Data<T>::setValue(T newValue){
   this->value = newValue;
}
/**
 * @brief Construct a new Data< T>:: Data object
 * 
 * @tparam T 
 */
template<typename T>
Data<T>::Data(){
}
/**
 * @brief Construct a new Data< T>:: Data object
 * 
 * @tparam T 
 * @param datax 
 * @param valuex 
 */
template<typename T>
Data<T>::Data(T datax, T valuex){
	this.data=datax;
	this.value=valuex;
}
