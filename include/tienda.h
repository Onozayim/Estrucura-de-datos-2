#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include "ListaEstatica.h"
#include <fstream>

class tienda
{
    public:
        tienda();
        virtual ~tienda();

        void setNombre(string n);

        void addProductos();
        void showProducts();
        void sortProducts();
        void importProducts();
        void exportProducts();
        void searchProduct();

    protected:

    private:
        string nombre;
        ListaEstatica<Producto> productos;
};

#endif // TIENDA_H
