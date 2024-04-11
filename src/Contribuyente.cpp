#include "Contribuyente.h"
#include "string.h"

using namespace std;

Contribuyente::Contribuyente()
{
    this->rfc = new char[13];
    this->nombre = new char[32];
    this->telefono = new char[12];
    this->direccion = new char[45];
    this->ciudad =  new char[32];
    this->fechaNacimiento = new char[10];

    this->apellido = new char*[2];
    for(size_t i = 0; i < 2; i++)
        apellido[i] = new char[32];
}

Contribuyente::~Contribuyente()
{

}

ostream& operator << (ostream& os, Contribuyente& obj)
{
  os  << obj.getRfc() << "|"
    << obj.getNombre() << "|"
    << obj.getApellidoPaterno() << "|"
    << obj.getApellidoMaterno() << "|"
    << obj.getTelefono() << "|"
    << obj.getDireccion() << "|"
    << obj.getCiudad() << "|"
    << obj.getFechaNacimiento() << "|"
    << obj.getEstadoCivil() << "|"
    << obj.getDependientes()
    <<endl;

    return os;
}

istream& operator >> (istream& is, Contribuyente& obj)
{
    string aux;
    getline(is, aux, ' ');
    if (aux.size() > 0)
    {
        //
        //cout << "new line" << endl;
        getline(is, aux, '|');
        char *rfc = new char[13];


        for(int i = 0; i < 13; i++)
            rfc[i] = aux[i];


        rfc[12] = '\0';
        //cout << rfc <<  '|' << endl;
        obj.setRfc(rfc);

        //

        getline(is, aux, '|');
        char *nombre = new char[32];

        for(int i = 0; i < 32; i++)
            nombre[i] = aux[i];

        nombre[31] = '\0';
        //cout << nombre << '|' << endl,
        obj.setNombre(nombre);

        //
        getline(is, aux, '|');
        char *apellidoP = new char[32];

        for(int i = 0; i < 32; i++)
            apellidoP[i] = aux[i];

        apellidoP[31] = '\0';
        //cout << apellidoP << '|' << endl;
        obj.setApellidoPaterno(apellidoP);

        //
        getline(is, aux, '|');
        char *apellidoM = new char[32];

        for(int i = 0; i < 32; i++)
            apellidoM[i] = aux[i];

        apellidoM[31] = '\0';
        obj.setApellidoMaterno(apellidoM);
        //cout << apellidoM << '|' << endl;

        //cout << "set appm " << endl;

        //
        getline(is, aux, '|');
        char *telefono = new char[12];

        for(int i = 0; i < 12; i++)
            telefono[i] = aux[i];

        telefono[11] = '\0';
        //cout << telefono << '|' << endl;
        obj.setTelefono(telefono);


        getline(is, aux, '|');
        char *direccion = new char[32];

        for(int i = 0; i < 32; i++)
            direccion[i] = aux[i];

        direccion[31] = '\0';
        //cout << direccion << '|' << endl;
        obj.setDireccion(direccion);

        getline(is, aux, '|');
        char *ciudad = new char[32];

        for(int i = 0; i < 32; i++)
            ciudad[i] = aux[i];

        ciudad[31] = '\0';
        //cout << ciudad << '|' << endl;
        obj.setCiudad(ciudad);


        getline(is, aux, '|');
        char *fn = new char[10];

        for(int i = 0; i < 10; i++)
            fn[i] = aux[i];

        fn[9] = '\0';
        obj.setFechaNacimiento(fn);


        getline(is, aux, '|');
        obj.setEstadoCivil(aux[0]);

        //cout << aux[0] << endl;


        getline(is, aux, '\n');
        //cout << aux << endl;
        obj.setDependiente(stoi(aux));
    }
    return is;
}

void Contribuyente::fillWithSpaces(char* word, int wordSize, int maxSize)
{
    while(wordSize < maxSize)
    {
        word[wordSize] = ' ';
        wordSize++;
    }

    word[maxSize] = '\0';
}



void Contribuyente::setRfc(char *rfc)
{
    strcpy(this->rfc, rfc);
    fillWithSpaces(this->rfc, strlen(this->rfc), 13);
}

void Contribuyente::setNombre(char *nombre)
{
    strcpy(this->nombre, nombre);
    fillWithSpaces(this->nombre, strlen(this->nombre), 32);
}

void Contribuyente::setApellidos(char **apellido)
{
    strcpy(this->apellido[0], apellido[0]);
    fillWithSpaces(this->apellido[0], strlen(this->apellido[0]), 32);

    strcpy(this->apellido[1], apellido[1]);
    fillWithSpaces(this->apellido[1], strlen(this->apellido[1]), 32);
}

void Contribuyente::setApellidoPaterno(char *apellido)
{
    strcpy(this->apellido[0], apellido);
    fillWithSpaces(this->apellido[0], strlen(this->apellido[0]), 32);
}

void Contribuyente::setApellidoMaterno(char *apellido)
{
    strcpy(this->apellido[1], apellido);
    fillWithSpaces(this->apellido[1], strlen(this->apellido[1]), 32);
}

void Contribuyente::setTelefono(char *telefono)
{
    strcpy(this->telefono, telefono);
    fillWithSpaces(this->telefono, strlen(this->telefono), 12);
}

void Contribuyente::setDireccion(char *direccion)
{
    strcpy(this->direccion, direccion);
    fillWithSpaces(this->direccion, strlen(this->direccion), 45);
}

void Contribuyente::setCiudad(char *ciudad)
{
    strcpy(this->ciudad, ciudad);
    fillWithSpaces(this->ciudad, strlen(this->ciudad), 32);
}

void Contribuyente::setFechaNacimiento(char *fechaNacimiento)
{
    strcpy(this->fechaNacimiento, fechaNacimiento);
    fillWithSpaces(this->fechaNacimiento, strlen(this->fechaNacimiento), 10);
}

void Contribuyente::setEstadoCivil(char estadoCivil)
{
    this->estadoCivil = estadoCivil;
}

void Contribuyente::setDependiente(int dependientes)
{
    this->dependientes = dependientes;
}

char* Contribuyente::getRfc()
{
    return this->rfc;
}

char* Contribuyente::getNombre()
{

    return this->nombre;
}

char* Contribuyente::getApellidoPaterno()
{

    return this->apellido[0];
}

char* Contribuyente::getApellidoMaterno()
{
    return this->apellido[1];
}

char* Contribuyente::getTelefono()
{
    return this->telefono;
}

char* Contribuyente::getDireccion()
{
    return this->direccion;
}

char* Contribuyente::getCiudad()
{

    return this->ciudad;
}

char* Contribuyente::getFechaNacimiento()
{

    return this->fechaNacimiento;
}

char Contribuyente::getEstadoCivil()
{
    return this->estadoCivil;
}

int Contribuyente::getDependientes()
{

    return this->dependientes;
}
