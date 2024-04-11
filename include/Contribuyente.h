#ifndef CONTRIBUYENTE_H
#define CONTRIBUYENTE_H

#include "iostream"
#include "fstream"

using namespace std;

class Contribuyente
{
    public:
        Contribuyente();
        virtual ~Contribuyente();

        void setRfc(char *rfc);
        void setNombre(char *nombre);
        void setApellidos(char **apellido);
        void setApellidoMaterno(char *apellido);
        void setApellidoPaterno(char *apellido);
        void setTelefono(char *telefono);
        void setDireccion(char *direccion);
        void setCiudad(char *ciudad);
        void setFechaNacimiento(char *fechaNacimiento);
        void setEstadoCivil(char estadoCivil);
        void setDependiente(int dependientes);

        char* getRfc();
        char* getNombre();
        char* getApellidoPaterno();
        char* getApellidoMaterno();
        char* getTelefono();
        char* getDireccion();
        char* getCiudad();
        char* getFechaNacimiento();
        char getEstadoCivil();
        int getDependientes();

        void fillWithSpaces(char* word, int wordSize, int maxSize);

        friend ostream& operator << (ostream& os, Contribuyente& obj);
        friend istream& operator >> (istream& is, Contribuyente& obj);

    protected:

    private:
        char *rfc;
        char *nombre;
        char **apellido;
        char *telefono;
        char *direccion;
        char *ciudad;
        char *fechaNacimiento;
        char estadoCivil;
        int dependientes;
};

#endif // CONTRIBUYENTE_H
