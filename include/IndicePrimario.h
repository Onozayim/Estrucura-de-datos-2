#ifndef INDICEPRIMARIO_H
#define INDICEPRIMARIO_H

#include <ListaEstatica.h>
#include <stIndiceRfc.h>

class IndicePrimario
{
    public:
        IndicePrimario();
        virtual ~IndicePrimario();

    protected:

    private:
        ListaEstatica<stIndiceRfc> indicePrimario;
};

#endif // INDICEPRIMARIO_H
