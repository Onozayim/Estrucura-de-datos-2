#ifndef STINDICERFC_H
#define STINDICERFC_H

#include <iostream>
#include <fstream>

using namespace std;

class stIndiceRfc
{
    public:
        stIndiceRfc();
        virtual ~stIndiceRfc();

        void setRfc(char *rfc);
        void setIndice(int indice);

        friend ostream& operator << (ostream& os, stIndiceRfc& obj);

        bool operator < (const stIndiceRfc& other);
        bool operator > (const stIndiceRfc& other);
        bool operator <= (const stIndiceRfc& other);
        bool operator >= (const stIndiceRfc& other);
        bool operator == (const stIndiceRfc& other);

        char* getRfc();
        int getIndice();

    protected:

    private:
        char *rfc = new char[13];
        int indice;
};

#endif // STINDICERFC_H
