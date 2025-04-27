#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector
{
    int *array;
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
            array = new int[size];
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

    int& operator[](int index)
    {
        if(index < 0 || index >= size)
            throw out_of_range("Index out of range");
        return array[index];
    }

    Vector operator++(int)
    {
        Vector temp = *this;
        int* newArray = new int[size + 1];

        for (int i = 0; i < size; ++i)
            newArray[i] = array[i];

        newArray[size] = 0;

        delete[] array;
        array = newArray;
        size++;

        return temp;
    }

    Vector& operator++()
    {
        int* newArray = new int[size + 1];
        newArray[0] = 0;

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

#endif //VECTOR_H
