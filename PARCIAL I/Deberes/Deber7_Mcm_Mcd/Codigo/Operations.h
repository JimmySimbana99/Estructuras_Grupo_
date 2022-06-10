#if !defined(__Class_Diagram_1_Operaciones_h)
#define __Class_Diagram_1_Operaciones_h
#include "Data.h"
template<typename H>
class Operations
{
public:
   Operations(); 
   	H operator /=(Data <H>);	
private:
   Data <H> data;
};
#endif