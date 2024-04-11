#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <ListaEstatica.h>
#include "IndiceSecundario.h"
#include "stIndiceRfc.h"

#include "list"
#include "string.h"

class Algoritmos
{
    public:
        Algoritmos() {}
        virtual ~Algoritmos(){}


        int isBinarySearch(ListaEstatica<IndiceSecundario>& staticList, char* ciudad)
        {
            int bottom = 0;
            int supperior = staticList.size() - 1;
            int half = 0;

            while(bottom <= supperior)
            {
                half = bottom + ((supperior - bottom) / 2);

                if(strcmp(ciudad, staticList[half].getCiudad()) == 0)
                    return half;
                else if(strcmp(ciudad, staticList[half].getCiudad()) < 0)
                    supperior = half - 1;
                else
                    bottom = half + 1;
            }

            return -1;
        }

        void isBubbleSort(ListaEstatica<IndiceSecundario>& is)
        {
            for(size_t i(0); i < is.size(); i++)
            {
                for(size_t j(0); j < is.size() - 1; j++)
                    if(strcmp(is[j].getCiudad(), is[j + 1].getCiudad()) > 0) swap(is[j], is[j + 1]);
            }
        }

        void ipBubbleSort(ListaEstatica<stIndiceRfc> &is)
        {
            for(size_t i(0); i < is.size(); i++)
            {
                for(size_t j(0); j < is.size() - 1; j++)
                    if(strcmp(is[j].getRfc(), is[j + 1].getRfc()) > 0) swap(is[j], is[j + 1]);
            }
        }

        int ipBinarySearch(ListaEstatica<stIndiceRfc>& staticList, char* rfc)
        {
            int bottom = 0;
            int supperior = staticList.size() - 1;
            int half = 0;

            while(bottom <= supperior)
            {
                half = bottom + ((supperior - bottom) / 2);

                if(strcmp(rfc, staticList[half].getRfc()) == 0)
                    return half;
                else if(strcmp(rfc, staticList[half].getRfc()) < 0)
                    supperior = half - 1;
                else
                    bottom = half + 1;
            }

            return -1;
        }

    private:
};



#endif // ALGORITMOS_H_H
