#if !defined(__TrigoDiagramClass_operaciones_h)
#define __TrigoDiagramClass_operaciones_h
class Operaciones
{
public:
    Operaciones(void);
   double calc_cos(int,int);
   double calc_sen(int,int);
	double calc_csc(int,int);
	double calc_sec(int,int);
	double calc_tan(int,int);
   double factorial(int);
   double *segmentar(double dim);
protected:
private:
};
#endif
