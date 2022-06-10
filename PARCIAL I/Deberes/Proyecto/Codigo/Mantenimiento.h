#include <iostream>
#include <sstream>
using namespace std;

class Mantenimiento
{
private:
    string fecha;
    string servicio;
    float costo;
    string placaAuto;

public:
    Mantenimiento() = default;
    Mantenimiento(string _fecha, string _servicio, float _costo, string _placaAuto);

    string getFecha();
    void setFecha(string _fecha);

    string getServicio();
    void setServicio(string _servicio);

    float getCosto();
    void setCosto(float _costo);

    string getplacaAuto();
    void setplacaAuto(string _placaAuto);
    
    string to_string();
};


