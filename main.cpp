#include <iostream>
#include <fstream>
#include "tienda.h"
#include "AllContribuyentes.h"

using namespace std;

enum opciones {
    AGREGAR = 'A',
    CONSULTAR_CONTRIBUYENTES = 'B',
    SALIR
};

int main()
{
    AllContribuyentes contribuyentes;

    contribuyentes.importData();

    char op;
    do
    {

        cout << "A] AGREGAR CONTRIBUYENTE" << endl
             << "B] BUSCAR REGISTRO" << endl
             << "C] SALIR" << endl;

        cin >> op;
        cin.ignore();

        switch(op) {
        case AGREGAR:
            contribuyentes.saveContribuyente();
            break;

        case CONSULTAR_CONTRIBUYENTES:
             system("CLS");

            cout << "1] Por llave primaria" << endl
             << "2] Por llave secundaria" << endl;

            int op2;
            cin >> op2;
            cin.ignore();

                switch (op2)
                {
                case 1:
                    contribuyentes.queryIp();
                    break;
                case 2:
                    contribuyentes.queryIs();
                    break;
                default:
                    cout << "opcion no valida" << endl;
                }

            break;

        case SALIR:
            break;
        default:
            cout << "Accion no valida" << endl;
            break;
        }

        cout << endl;

        system("pause");
        system("CLS");
    }while(op != SALIR);

    return 0;
}
