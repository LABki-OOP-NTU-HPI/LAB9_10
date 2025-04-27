#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <string>
using namespace std;
#include "exception"

class Error : public exception
{
protected:
    string message;

public:
    Error(string message) : message(message) {}
    virtual const char* what() const throw()
    {
        return message.c_str();
    }
};

class VectorOutOfRange : public Error
{
public:
    VectorOutOfRange() : Error("Index beyond vector boundaries") {}
};

class VectorEmptyAccess : public Error
{
public:
    VectorEmptyAccess() : Error("Accessing an empty vector") {}
};
#endif //ERROR_H
