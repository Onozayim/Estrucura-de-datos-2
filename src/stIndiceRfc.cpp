#include "stIndiceRfc.h"
#include "iostream"
#include "string.h"

stIndiceRfc::stIndiceRfc()
{
    this->rfc = (char*) malloc(sizeof(char) * 13);
}

stIndiceRfc::~stIndiceRfc()
{
    //dtor
}

ostream& operator << (ostream& os, stIndiceRfc& obj)
{
  os  << obj.getRfc() << "|"
    << obj.getIndice()
    <<endl;

    return os;
}

char* stIndiceRfc::getRfc()
{
    return this->rfc;
}

int stIndiceRfc::getIndice()
{
    return this->indice;
}

bool stIndiceRfc::operator < (const stIndiceRfc &other)
{
    return this->rfc < other.rfc;
}

bool stIndiceRfc::operator > (const stIndiceRfc &other)
{
    return this->rfc > other.rfc;
}

bool stIndiceRfc::operator == (const stIndiceRfc &other)
{
    return this->rfc == other.rfc;
}

bool stIndiceRfc::operator >= (const stIndiceRfc &other)
{
    return this->rfc >= other.rfc;
}

bool stIndiceRfc::operator <= (const stIndiceRfc &other)
{
    return this->rfc <= other.rfc;
}

void stIndiceRfc::setRfc(char *rfc)
{
    strcpy(this->rfc, rfc);
}

void stIndiceRfc::setIndice(int indice)
{
    this->indice = indice;
}
