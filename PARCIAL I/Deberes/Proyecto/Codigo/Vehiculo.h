#include <iostream>
#include <sstream>

using namespace std;
class Vehiculo
{
private:
    string marca;
    string modelo;
    int anio;
    string placa;

public:
    Vehiculo() = default;
    Vehiculo(string _marca, string _modelo, int _anio, string _placa);

    string getMarca();
    void setMarca(string _marca);

    string getModelo();
    void setModelo(string _modelo);

    string getPlaca();
    void setPlaca(string _placa);

    int getAnio();
    void setAnio(int _anio);

    string to_string();
};
