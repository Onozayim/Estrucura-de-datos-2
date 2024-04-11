#ifndef ALLCONTRIBUYENTES_H
#define ALLCONTRIBUYENTES_H

#include "ListaEstatica.h"
#include "Contribuyente.h"
#include "stIndiceRfc.h"
#include "Algoritmos.h"
#include "IndiceSecundario.h"

class AllContribuyentes
{
    public:
        AllContribuyentes();
        virtual ~AllContribuyentes();

        void saveContribuyente();
        void saveInSecondaryIndex(char* ciudad, stIndiceRfc indice);
        void fillWithSpaces(char* word, int wordSize, int maxSize);
        void showContribuyentes();
        void showIndicePrimario();
        void exportIndiceSecundario();
        void exportContribuyentes();
        void exportIndicePrimatio();
        void queryIs();
        void queryIp();
        void importData();

    protected:

    private:
        ListaEstatica<Contribuyente> contribuyentes;
        ListaEstatica<stIndiceRfc> indicePrimario;
        ListaEstatica<IndiceSecundario> IndiceSecundarioList;
        Algoritmos al;
};

#endif // ALLCONTRIBUYENTES_H
