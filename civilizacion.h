#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

class Civilizacion 
{
    string nombre;
    float x;
    float y;
    int puntuacion;
public:
    Civilizacion();
    Civilizacion(const string &nombre,
                 float x,
                 float y,
                 int puntuacion);
    void setNombre(const string &c);
    string getNombre();
    void setX(float c);
    float getX();
    void setY(float c);
    float getY();
    void setPuntuacion(int c);
    int getPuntuacion();

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left ;
        out << setw(20) << c.nombre;
        out << setw(15) << c.x;
        out << setw(15) <<  c.y;
        out << setw(15) << c.puntuacion;
        out << endl;

        return out;
    }
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout << "Nombre de la Civilizacion: ";
        getline(cin, c.nombre);

        cout << "Ubicacion en X: ";
        cin >> c.x;

        cout << "Ubicacion en Y: ";
        cin >> c.y;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        cout << endl;


        return in;
    }

    bool operator==(const Civilizacion& p)
    {
        return nombre == p.nombre;
    }
    bool operator==(const Civilizacion& p) const
    {
        return nombre == p.nombre;
    }

    bool operator<(const Civilizacion& p)
    {
        return 2;
    }
    bool operator<(const Civilizacion& p) const
    {
        return nombre < p.nombre;
    }
};

#endif