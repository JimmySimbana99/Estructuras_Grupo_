/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE
AUTORES : ALEXANDER MAILA
		  JIMMY SIMBAÑA
		  
ENUNCIADO: REALIZAR UN PROGRAMA CON METODOS BINARIOS
FECHA DE CREACION: 16/5/2022
FECHA MODIFICACION: 16/5/2022
*/
#if !defined(__Class_Diagram_1_Datos_h)
#define __Class_Diagram_1_Datos_h
template<typename T>
class Data
{
public:
	T getData(void);
	void setData(T);
	T getValue(void);
	void setValue(T);
    Data(T,T);
	Data();
protected:
private:
   T data;
   T value; 
};
#endif
