#include "IndiceSecundario.h"
#include "string.h"

#include "iostream"
#include "stIndiceRfc.h"

using namespace std;

IndiceSecundario::IndiceSecundario()
{
}

IndiceSecundario::~IndiceSecundario()
{
    //dtor
}

void IndiceSecundario::setCiudad(char* ciudad)
{
    strcpy(this->ciudad, ciudad);
    fillWithSpaces(this->ciudad, strlen(this->ciudad), 32);
}

char* IndiceSecundario::getCiudad()
{
    return this->ciudad;
}

void IndiceSecundario::fillWithSpaces(char* word, int wordSize, int maxSize)
{
    while(wordSize < maxSize)
    {
        word[wordSize] = ' ';
        wordSize++;
    }

    word[maxSize] = '\0';
}

void IndiceSecundario::pushIndice(stIndiceRfc indice)
{
    this->rfcsList.push_back(indice);
    this->index++;
    rfcsList.sort([](stIndiceRfc indice1, stIndiceRfc indice2)
                        {
                            return strcmp(indice1.getRfc(), indice2.getRfc()) < 0;
                        });
    //cout << this->rfcsList[this->index - 1] << endl;
}


bool IndiceSecundario::operator < (const IndiceSecundario &other)
{
    return this->ciudad < other.ciudad;
}

bool IndiceSecundario::operator > (const IndiceSecundario &other)
{
    return this->ciudad > other.ciudad;
}

/*

bool IndiceSecundario::operator == (const IndiceSecundario &other)
{
    return this->ciudad == other.ciudad;
}

�*/
bool IndiceSecundario::operator >= (const IndiceSecundario &other)
{
    return this->ciudad >= other.ciudad;
}

bool IndiceSecundario::operator <= (const IndiceSecundario &other)
{
    return this->ciudad <= other.ciudad;
}

ostream& operator << (ostream& os, IndiceSecundario& obj)
{
  os  << obj.getCiudad() << "|";


    int i = 1;

    for(list<stIndiceRfc>::iterator it = obj.rfcsList.begin(); it != obj.rfcsList.end(); ++it)
    {
        os << it->getIndice();

        if(i != obj.index) os << " -> ";

        i++;
    }

    os <<endl;

    return os;
}
