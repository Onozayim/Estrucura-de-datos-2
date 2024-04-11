#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto
{
public:
    Producto();

    string getNombre() const;
    void setNombre(const string& valor);
    int getExistencia() const;
    void setExistencia(int valor);
    float getPrecio() const;
    void setPrecio(float valor);

    bool operator < (const Producto& other);
    bool operator > (const Producto& other);
    bool operator <= (const Producto& other);
    bool operator >= (const Producto& other);
    bool operator == (const Producto& other);


    // friend permite a un ente externo a la clase acceder a los atributos y m�todos de la clase
    // OuputSTREAM: Flujo de salida
    friend ostream& operator << (ostream& os, const Producto& obj);
    // InputSTREAM: Flujo de entrada
    friend istream& operator >> (istream& is, Producto& obj);

private:
    string nombre;
    int existencia;
    float precio;
};

#endif // PRODUCTO_H
