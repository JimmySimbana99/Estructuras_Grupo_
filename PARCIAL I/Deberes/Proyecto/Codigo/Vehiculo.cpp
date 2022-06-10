#include "Vehiculo.h"
/**
 * @brief Construct a new Vehiculo:: Vehiculo object
 * 
 * @param _marca 
 * @param _modelo 
 * @param _anio 
 * @param _placa 
 */
Vehiculo::Vehiculo(string _marca, string _modelo, int _anio, string _placa)
{
    this->marca = _marca;
    this->modelo = _modelo;
    this->anio = _anio;
    this->placa = _placa;
}

string Vehiculo::getMarca()
{
    return marca;
}
void Vehiculo::setMarca(string _marca)
{
    this->marca = _marca;
}

string Vehiculo::getModelo()
{
    return modelo;
}
void Vehiculo::setModelo(string _modelo)
{
    this->modelo = _modelo;
}

string Vehiculo::getPlaca()
{
    return placa;
}
void Vehiculo::setPlaca(string _placa)
{
    this->placa = _placa;
}

int Vehiculo::getAnio()
{
    return anio;
}
void Vehiculo::setAnio(int _anio)
{
    this->anio = _anio;
}

string Vehiculo::to_string()
{
    stringstream s;
    s << marca << "\n" << modelo << "\n" << anio << "\n" << placa << "\n";

    return s.str();
}