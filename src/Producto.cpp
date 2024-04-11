#include "producto.h"
#include "fstream"
#include "iostream"

Producto::Producto()
{
    nombre = "-";
    existencia = 0;
    precio = 0.0;
}

string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(const string &valor)
{
    nombre = valor;
}

int Producto::getExistencia() const
{
    return existencia;
}

void Producto::setExistencia(int valor)
{
    existencia = valor;
}

float Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(float valor)
{
    precio = valor;
}

ostream& operator << (ostream& os, const Producto& obj)
{
    os <<obj.getNombre() <<"|" <<obj.getExistencia() <<"|" <<obj.getPrecio()
      <<endl;

    return os;
}

istream& operator >> (istream& is, Producto& obj)
{
    string aux;
    getline(is, aux, '|');
    if (aux.size() > 0)
    {
        obj.setNombre(aux);
        getline(is, aux, '|');
        obj.setExistencia(stoi(aux)); // STOI StringTOInteger requiere C++ 11
        getline(is, aux);
        obj.setPrecio(stof(aux)); // STOF StringTOFloat
    }
    return is;
}

bool Producto::operator < (const Producto &other)
{
    return nombre < other.nombre;
}

bool Producto::operator > (const Producto &other)
{
    return nombre > other.nombre;
}

bool Producto::operator <= (const Producto &other)
{
    return nombre <= other.nombre;
}

bool Producto::operator == (const Producto &other)
{
    return nombre == other.nombre;
}
