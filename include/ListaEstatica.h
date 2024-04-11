#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept>

using namespace std;


template<typename T>
class ListaEstatica
{
public:
    ListaEstatica(size_t n = 1000)
    {
        index = 0;
        containerSize = n;
    }

    bool empty() const;
    bool full() const;
    size_t size() const;
    void push_back(const T& element);
    void pop_back();
    T& operator [] (size_t position);
    void clear();

private:
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    //Indica la cantidad de elementos en la lista y la posici�n del siguiente elemento
    size_t index;
    size_t containerSize;//Capacidad con la que se crea la lista
};

template<typename T>
bool ListaEstatica<T>::empty() const
{
    return index == 0;
}

template<typename T>
bool ListaEstatica<T>::full() const
{
    return index == containerSize;
}

template<typename T>
size_t ListaEstatica<T>::size() const
{
    return index;
}

template<typename T>
void ListaEstatica<T>::push_back(const T& element)
{
    if (full())
    {
        throw runtime_error("Trying push_back(const T& element) on full list");
    }

    elements[index++] = element;
}

template<typename T>
void ListaEstatica<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() on empty list");
    }
    --index;
}

template<typename T>
T& ListaEstatica<T>::operator [] (size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying [] on empty list");
    }
    if (position >= size())
    {
        throw range_error("Trying [] in non valid position");
    }

    return elements[position];
}

template<typename T>
void ListaEstatica<T>::clear()
{
    index = 0;
}
#endif // LISTA_ESTATICA_H
