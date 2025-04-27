#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Error.h"
using namespace std;

template <class T>
class Vector
{
    T *array;
    int size;
    public:

    Vector()
    {
        array = nullptr;
        size = 0;
    }

    Vector(const Vector& other)
    {
        size = other.size;
        if (size > 0)
        {
            array = new T[size];
            for (int i = 0; i < size; ++i)
                array[i] = other.array[i];
        }
        else
        {
            array = nullptr;
        }
    }
    ~Vector()
    {
        delete[] array;
    };

    T& operator[](int index)
    {
        if(index < 0 || index >= size)
            throw VectorOutOfRange();

        return array[index];
    }

    Vector operator++(int)
    {
        Vector temp = *this;
        T* newArray = new T[size + 1];

        for (int i = 0; i < size; ++i)
            newArray[i] = array[i];

        delete[] array;
        array = newArray;
        size++;

        return temp;
    }

    Vector& operator++()
    {
        T* newArray = new T[size + 1];

        for (int i = 0; i < size; ++i)
            newArray[i + 1] = array[i];

        delete[] array;
        array = newArray;
        size++;

        return *this;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
    }
};
template<>
class Vector<bool>{};

template<>
void Vector<string>::print() const
{
    for (int i = 0; i < size; ++i)
        cout << "#" << array[i] << "#" << " ";
    cout << endl;
}

#endif //VECTOR_H
