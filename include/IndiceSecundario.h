#ifndef INDICESECUNDARIO_H
#define INDICESECUNDARIO_H

#include "ListaEstatica.h"
#include "iostream"
#include "fstream"

#include "list"
#include "stIndiceRfc.h"

class IndiceSecundario
{
    public:
        IndiceSecundario();
        virtual ~IndiceSecundario();

        void fillWithSpaces(char* word, int wordSize, int maxSize);

        char* getCiudad();
        void pushIndice(stIndiceRfc indice);

        void setCiudad(char* ciudad);


        bool operator < (const IndiceSecundario& other);
        bool operator > (const IndiceSecundario& other);
        bool operator <= (const IndiceSecundario& other);
        bool operator >= (const IndiceSecundario& other);
        //bool operator == (const IndiceSecundario& other);
        friend ostream& operator << (ostream& os, IndiceSecundario& obj);

        list<stIndiceRfc> rfcsList;
        //int  *rfcsList = new int[100];
        int index = 0;

    protected:

    private:
        char *ciudad = new char[32];

};

#endif // INDICESECUNDARIO_H
