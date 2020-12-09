#include "videojuego.h"
#include <fstream>
#include <algorithm>


Videojuego::Videojuego()
{

}

Videojuego::Videojuego(const string &usuario)               
{
    this->usuario = usuario;
}

void Videojuego::setUsuario(const string &u)
{
    usuario = u;
}

string Videojuego::getUsuario()
{
    return usuario;
}

void Videojuego::agregarCivilizacion(const Civilizacion &p)
{
    civilizaciones.push_back(p);
}

void Videojuego::mostrar()
{
    cout << left;
    cout << setw(20) << "Nombre";
    cout << setw(15) << "Ubicacion X";
    cout << setw(15) << "Ubicacion Y";
    cout << setw(15) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &p = civilizaciones[i];
        cout << p;
    }
}

void Videojuego::respaldar_tabla()
{
    ofstream archivo("civilizaciones_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(20) << "Nombre";
        archivo << setw(15) << "Ubicacion X";
        archivo << setw(15) << "Ubicacion Y";
        archivo << setw(15) << "Puntuacion";
        archivo << endl;
        for (size_t i = 0; i < civilizaciones.size(); i++) {
            Civilizacion &p = civilizaciones[i];
            archivo << p;
        }
    }
    archivo.close();
}
void Videojuego::respaldar()
{
    ofstream archivo("civilizaciones.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < civilizaciones.size(); i++) {
            Civilizacion &p = civilizaciones[i];
            archivo << p.getNombre() << endl;
            archivo << p.getX() << endl;
            archivo << p.getY() << endl;
            archivo << p.getPuntuacion() << endl;
        }
    }
    archivo.close();
}

void Videojuego::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open()) {
        string temp;
        float u;
        int pt;
        Civilizacion p;

        while (true)
        {
            getline(archivo, temp); 
            if (archivo.eof()) {
                break;
            }
            p.setNombre(temp);

            getline(archivo, temp); 
            u = stof(temp);  
            p.setX(u);

            getline(archivo, temp); 
            u = stof(temp); 
            p.setY(u);

            getline(archivo, temp);
            pt = stoi(temp); 
            p.setPuntuacion(pt);

            agregarCivilizacion(p);            
        }
        
    }
    archivo.close();
}

void Videojuego::insertar(const Civilizacion &p, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, p);
}

size_t Videojuego::size()
{
    return civilizaciones.size();
}

void Videojuego::inicializar(const Civilizacion &p, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, p);
}

void Videojuego::primeraCivilizacion()
{
    cout<<civilizaciones.front();
}

void Videojuego::ultimaCivilizacion()
{
    cout<<civilizaciones.back();
}

void Videojuego::eliminar(size_t pos)
{
    civilizaciones.erase(civilizaciones.begin()+pos);
}

void Videojuego::ordenar()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}
void Videojuego::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion p1, Civilizacion p2){return p1.getX() < p2.getX();});
}
void Videojuego::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion p1, Civilizacion p2){return p1.getY() > p2.getY();});
}
void Videojuego::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion p1, Civilizacion p2){return p1.getPuntuacion() < p2.getPuntuacion();});
}

Civilizacion* Videojuego::buscar(const Civilizacion &p)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), p);

    if (it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}
