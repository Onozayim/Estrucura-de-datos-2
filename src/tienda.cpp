#include "tienda.h"
#include <algoritmos.h>
#include <fstream>
#include <string>

tienda::tienda()
{
    //ctor
}

tienda::~tienda()
{
    //dtor
}

void tienda::setNombre(string n) {
    nombre = n;
}

void tienda::addProductos() {
    Producto newProduct;

    string nombre;
    int ex;
    float pre;

    cout <<"Ingresa la informaci�n de un producto (Nombre, Existencia, Precio)." <<endl
         <<"Por cada atributo presiona <ENTER>" <<endl;

    getline(cin, nombre);
    cin >> ex;
    cin >> pre;

    newProduct.setNombre(nombre);
    newProduct.setExistencia(ex);
    newProduct.setPrecio(pre);

    productos.push_back(newProduct);
}

void tienda::sortProducts() {
    if(productos.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    Algoritmos al;
    al.bubbleSort(productos);

    cout << "Articulos ordenados" << endl;
}

void tienda::showProducts() {
    if(productos.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    cout << "PRODUCTOS ACTUALES" << endl << endl;

    for(size_t i = 0; i < productos.size(); i++) {
        cout << i << ": ";
        cout << productos[i];
    }
}

void tienda::exportProducts() {
    if(productos.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    fstream archivo;
    archivo.open("productos.txt", ios::out | ios::trunc);

    if(!archivo.is_open())
    {
        cout << "Error al abrir el archivo " << endl;
        return;
    }

    for(size_t i = 0; i < productos.size(); i++) {
        archivo << productos[i];
    }

    archivo.close();

    cout << "Articulos guardados en el archivo de texto" << endl;
}

void tienda::importProducts() {
    productos.clear();
    fstream archivo;

    archivo.open("productos.txt", ios::in);
    if (!archivo.is_open())
    {
        cout <<"Error con el archivo de entrada" <<endl;
        return;
    }

    Producto prod;
    while (archivo >> prod)
    {
        productos.push_back(prod);
    }
    archivo.close();

    cout << "Articulos importados del archivo de texto" << endl;
}

void tienda::searchProduct() {
    if(productos.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    string ar;
    Producto p;

    cout << "Ingrese el art�culo a buscar: " << endl;
    getline(cin, ar);

    p.setNombre(ar);

    Algoritmos al;

    //int pos = al.sequentialSearch(productos, p);
    int pos = 0;

    if(pos != productos.size()) {
            cout << "Art�culo encontrado!!" << endl;
            cout << pos << ": ";
            cout << productos[pos];
    }else {
        cout << "Articulo no encontrado" << endl;
    }

}
