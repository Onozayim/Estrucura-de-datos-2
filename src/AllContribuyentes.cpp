#include "AllContribuyentes.h"
#include "Contribuyente.h"
#include "stIndiceRfc.h"
#include "string"
#include <iostream>
#include "Algoritmos.h"
#include "string.h"

using namespace std;

AllContribuyentes::AllContribuyentes()
{

}

AllContribuyentes::~AllContribuyentes()
{
    //dtor
}

void AllContribuyentes::showContribuyentes()
{
    system("CLS");

    if(this->contribuyentes.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    cout << "PRODUCTOS ACTUALES" << endl << endl;

    for(size_t i = 0; i < this->contribuyentes.size(); i++) {
        cout << i << ": ";
        cout << this->contribuyentes[i];
    }
}

void AllContribuyentes::showIndicePrimario()
{
    system("CLS");

    if(this->indicePrimario.empty() == true) {
        cout << "No se puede realizar la accion, agrege productos primero";
        return;
    }

    cout << "PRODUCTOS ACTUALES" << endl << endl;

    for(size_t i = 0; i < this->indicePrimario.size(); i++) {
        cout << i << ": ";
        cout << this->indicePrimario[i];
    }
}

void AllContribuyentes::saveContribuyente()
{
    system("CLS");

    char *rfc = new char[13];
    char *nombre = new char[32];
    char **apellido = new char*[2];
    for(int i = 0; i < 2; i++)
        apellido[i] = new char[32];

    char *telefono = new char[12];
    char *direccion = new char[45];
    char *ciudad = new char[32];
    char *fechaNacimiento = new char[10];
    char estadoCivil;
    int dependientes;

    cout <<"Ingrese el Rfc del contribuyente : ";
    cin.getline(rfc, 13);

    cout << "Ingrese el nombre del contribuyente: ";
    cin.getline(nombre, 32);

    cout << "Ingrese el apellido paterno del contribuyente: ";
    cin.getline(apellido[0], 32);

    cout << "Ingrese el apellido materno del contribuyente: ";
    cin.getline(apellido[1], 32);

    cout << "Ingrese el telefono del contribuyente: ";
    cin.getline(telefono, 12);

    cout << "Ingrese la direccion del contribuyente: ";
    cin.getline(direccion, 45);

    cout << "Ingrese la ciudad del contribuyente: ";
    cin.getline(ciudad, 32);

    cout << "Ingrese la fecha de nacimiento del contribuyente: ";
    cin.getline(fechaNacimiento, 10);

    cout << "Ingrese el estado civil del contribuyente: ";
    cin >> estadoCivil;

    cout << "Ingrese el numero de dependientes del contribuyente: ";
    cin >> dependientes;

    Contribuyente contribuyente;

    contribuyente.setRfc(rfc);
    contribuyente.setNombre(nombre);
    contribuyente.setApellidos(apellido);
    contribuyente.setTelefono(telefono);
    contribuyente.setDireccion(direccion);
    contribuyente.setCiudad(ciudad);
    contribuyente.setFechaNacimiento(fechaNacimiento);
    contribuyente.setEstadoCivil(estadoCivil);
    contribuyente.setDependiente(dependientes);

    this->contribuyentes.push_back(contribuyente);
    exportContribuyentes();

    stIndiceRfc indice;

    fillWithSpaces(rfc, strlen(rfc), 13);

    indice.setRfc(rfc);
    indice.setIndice(this->contribuyentes.size() - 1);

    this->indicePrimario.push_back(indice);
    exportIndicePrimatio();

    al.ipBubbleSort(this->indicePrimario);

    saveInSecondaryIndex(ciudad, indice);
    exportIndiceSecundario();
}

void AllContribuyentes::saveInSecondaryIndex(char* ciudad, stIndiceRfc indice)
{
    fillWithSpaces(ciudad, strlen(ciudad), 32);
    int index = al.isBinarySearch(this->IndiceSecundarioList, ciudad);

    if(index != -1)
    {
        this->IndiceSecundarioList[index].pushIndice(indice);
        //al.isBubbleSort(this->IndiceSecundarioList[index].rfcsList, this->IndiceSecundarioList[index].index);
    }
    else
    {
        IndiceSecundario element;
        element.setCiudad(ciudad);
        element.pushIndice(indice);

        this->IndiceSecundarioList.push_back(element);
        al.isBubbleSort(this->IndiceSecundarioList);
    }
}

void AllContribuyentes::fillWithSpaces(char* word, int wordSize, int maxSize)
{
    while(wordSize < maxSize)
    {
        word[wordSize] = ' ';
        wordSize++;
    }

    word[maxSize] = '\0';
}


void AllContribuyentes::exportIndiceSecundario()
{
    if(IndiceSecundarioList.empty() == true) return;

    fstream archivo;
    archivo.open("indiceSecundario.txt", ios::out | ios::trunc);

    archivo << "Llave Secundaria                |" << "NRR" << endl;

    if(!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    for(int i = 0; i < IndiceSecundarioList.size(); i++)
    {
        archivo << IndiceSecundarioList[i];
    }
}

void AllContribuyentes::exportContribuyentes()
{
    if(this->contribuyentes.empty() == true) return;

    fstream archivo;
    archivo.open("hacienda.txt", ios::out | ios::trunc);

    if(!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    for(int i = 0; i < this->contribuyentes.size(); i++)
    {
        archivo << i << " " << this->contribuyentes[i];
    }
}

void AllContribuyentes::queryIs()
{
    system("CLS");

    if(IndiceSecundarioList.empty() == true) return;

    char* ciudad = new char[32];

    cout <<"Ingrese la ciudad del contribuyente : ";
    cin.getline(ciudad, 32);

    fillWithSpaces(ciudad, strlen(ciudad), 32);

    int index = al.isBinarySearch(this->IndiceSecundarioList, ciudad);

    if(index == -1)
    {
        cout << "No se encontro registros" << endl;
        return;
    }

    for(list<stIndiceRfc>::iterator it = IndiceSecundarioList[index].rfcsList.begin(); it != IndiceSecundarioList[index].rfcsList.end(); ++it)
        cout << endl << it->getIndice()  << " " << this->contribuyentes[it->getIndice()];
}

void AllContribuyentes::queryIp()
{
    system("CLS");

    if(this->indicePrimario.empty() == true) return;

    char* rfc = new char[13];

    cout <<"Ingrese el rfc del contribuyente : ";
    cin.getline(rfc, 13);

    fillWithSpaces(rfc, strlen(rfc), 13);

    int index = al.ipBinarySearch(this->indicePrimario, rfc);

    if(index == -1)
    {
        cout << "No se encontro registros" << endl;
        return;
    }

    cout << this->indicePrimario[index].getIndice() << " " <<  this->contribuyentes[this->indicePrimario[index].getIndice()] << endl;
}

void AllContribuyentes::exportIndicePrimatio()
{
    if(this->indicePrimario.empty() == true) return;

    fstream archivo;
    archivo.open("indicePrimario.txt", ios::out | ios::trunc);

    if(!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    for(int i = 0; i < this->indicePrimario.size(); i++)
    {
        archivo << this->indicePrimario[i];
    }
}

void AllContribuyentes::importData()
{
    fstream archivo;

    archivo.open("hacienda.txt", ios::in);

    if(!archivo.is_open())
    {
        cout << "Error con el archivo" << endl;
        return;
    }


    while(archivo)
    {
        Contribuyente contr;
        archivo >> contr;
        this->contribuyentes.push_back(contr);
    }

    this->contribuyentes.pop_back();

    archivo.close();


    for(int i = 0; i < this->contribuyentes.size(); i++)
    {
        stIndiceRfc newIndice;

        newIndice.setIndice(i);
        newIndice.setRfc(this->contribuyentes[i].getRfc());

        this->indicePrimario.push_back(newIndice);

        saveInSecondaryIndex(this->contribuyentes[i].getCiudad(), newIndice);
    }

    al.ipBubbleSort(this->indicePrimario);

    cout << "Datos importados" << endl;
}
