#include <iostream>
using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Cliente.h"

class Cliente
{
private:
    string nombre;
    string rut;
    int edad;
    int monto;

public:
    Cliente(string nombre, string rut, int edad)
    {
        this->nombre = nombre;
        this->rut = rut;
        this->edad = edad;
        monto = 0;
    }
    void setRut(string rut)
    {
        this->rut = rut;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    void setEdad(int edad)
    {
        this->edad = edad;
    }
    void setMonto(int monto)
    {
        this->monto = monto;
    }
    string getNombre()
    {
        return nombre;
    }
    string getRut()
    {
        return rut;
    }
    int getEdad()
    {
        return edad;
    }
    double getMonto()
    {
        return monto;
    }
    void imprimir()
    {
        cout << "La persona: " << nombre << " de rut: " << rut << " y edad: " << edad
             << " tiene un monto de: " << monto << endl;
    }
};

#endif
