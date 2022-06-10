#include "Mantenimiento.h"
/**
 * @brief Construct a new Mantenimiento:: Mantenimiento object
 * 
 * @param _fecha 
 * @param _servicio 
 * @param _costo 
 * @param _placaAuto 
 */
Mantenimiento::Mantenimiento(string _fecha, string _servicio, float _costo, string _placaAuto)
{
    this->fecha = _fecha;
    this->servicio = _servicio;
    this->costo = _costo;
    this->placaAuto = _placaAuto;
}

string Mantenimiento::getFecha()
{
    return fecha;
}
void Mantenimiento::setFecha(string _fecha)
{
    this->fecha = _fecha;
}

string Mantenimiento::getServicio()
{
    return servicio;
}
void Mantenimiento::setServicio(string _servicio)
{
    this->servicio = _servicio;
}

float Mantenimiento::getCosto()
{
    return costo;
}
void Mantenimiento::setCosto(float _costo)
{
    this->costo = _costo;
}

string Mantenimiento::getplacaAuto()
{
    return placaAuto;
}
void Mantenimiento::setplacaAuto(string _placaAuto)
{
    this->placaAuto = _placaAuto;
}

string Mantenimiento::to_string()
{
    stringstream s;
    s << fecha <<endl<< servicio <<endl<< costo <<endl<< placaAuto<<endl;
    return s.str();
}
