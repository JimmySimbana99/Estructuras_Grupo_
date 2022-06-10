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