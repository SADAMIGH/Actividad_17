#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre,
                                 float x,
                                 float y,
                                 int puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &c)
{
    nombre = c;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setX(float c)
{
    x = c;
}

float Civilizacion::getX()
{
    return x;
}

void Civilizacion::setY(float c)
{
    y = c;
}

float Civilizacion::getY()
{
    return y;
}

void Civilizacion::setPuntuacion(int c)
{
    puntuacion = c;
}

int Civilizacion::getPuntuacion()
{
    return puntuacion;
}