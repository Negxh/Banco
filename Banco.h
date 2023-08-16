#include <iostream>
using namespace std;
#include "Cliente.h"

#ifndef BANCO_H
#define BANCO_H


class Banco
{
private:
    Cliente *lista[400];

public:
    Banco()
    {
        for (int i = 0; i < 400; i++)
        {
            lista[i] = NULL;
        }
    }
    void agregarCliente(Cliente *c)
    {
        int posicion = -1;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] == NULL)
            {

                posicion = i;
                lista[i] = c;
                cout << "Cliente ha sido agregado con exito en la posicion  " << i << endl;
                break;
            }
        }
        if (posicion == -1)
        {
            cout << "No hay capacidad para otro Cliente" << endl;
        }
    }
    bool buscarCliente(string rutbusq)
    {
        bool encontro = true;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getRut() == rutbusq)
                {
                    return encontro;
                    break;
                }
            }
            else if (i == 399)
            {
                encontro = false;
                return encontro;
                break;
            }
        }
        return true;
    }
    void DepositoCliente(string rutbusq, int deposito)
    {
        int saldodeposito = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getRut() == rutbusq)
                {
                    saldodeposito = lista[i]->getMonto() + deposito;
                    lista[i]->setMonto(saldodeposito);
                    cout << "Se le ha sumado $" << deposito << " a la cuenta del cliente "
                         << lista[i]->getNombre()
                         << ", Ahora su saldo es: $" << lista[i]->getMonto() << endl;
                }
            }
        }
    }
    void GirarCliente(string rutbusq, int giro)
    {
        int saldoactual = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getRut() == rutbusq)
                {
                    if (lista[i]->getMonto() >= giro)
                    {
                        saldoactual = lista[i]->getMonto() - giro;
                        lista[i]->setMonto(saldoactual);
                        cout << "Se le ha quitado $" << giro << " a la cuenta del cliente "
                             << lista[i]->getNombre()
                             << ", Ahora su saldo es: $" << lista[i]->getMonto() << endl;
                    }
                    else
                    {
                        cout << "Saldo insuficiente, el giro excede el saldo en la cuenta" << endl;
                    }
                }
            }
        }
    }
    void dineroTotal()
    {
        int dinerototal = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                dinerototal = dinerototal + lista[i]->getMonto();
            }
        }
        cout << "En el Banco hay un total de: $" << dinerototal << endl;
    }
    void totalClientes()
    {
        int clientetotal = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                clientetotal++;
            }
        }
        cout << "En el banco hay un total de " << clientetotal << " clientes." << endl;
    }
    void clientemasViejo()
    {
        int edadviejo = 0;
        string nombreviejo;
        int saldoviejo = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getEdad() > edadviejo)
                {
                    edadviejo = lista[i]->getEdad();
                    nombreviejo = lista[i]->getNombre();
                    saldoviejo = lista[i]->getMonto();
                }
            }
        }
        cout << "El cliente con mas edad en nuestro banco es: " << nombreviejo
             << ", con una edad de " << edadviejo << " y un saldo de $" << saldoviejo << endl;
    }
    void clientesDeudores()
    {
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getMonto() < 0)
                {
                    cout << "El cliente " << lista[i]->getNombre() << " es deudor y tiene un saldo de $"
                         << lista[i]->getMonto() << endl;
                    break;
                }
            }
            if (i == 399)
            {
                cout << "No hay clientes con deudas en nuestro banco" << endl;
                break;
            }
        }
    }
    void transferirCliente(string rutbusq, string ruttransf, int transfer)
    {
        int saldotransf = 0;
        int saldotransf2 = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getRut() == ruttransf)
                {
                    for (int i = 0; i < 400; i++)
                    {
                        if (lista[i] != NULL)
                        {
                            if (lista[i]->getRut() == rutbusq)
                            {
                                if (lista[i]->getMonto() >= transfer)
                                {
                                    saldotransf = lista[i]->getMonto() - transfer;
                                    lista[i]->setMonto(saldotransf);
                                    cout << "Se han descontado $" << transfer << " a la cuenta de "
                                         << lista[i]->getNombre() << " ahora su saldo es de $"
                                         << lista[i]->getMonto() << endl;
                                    for (int i = 0; i < 400; i++)
                                    {
                                        if (lista[i] != NULL)
                                        {
                                            if (lista[i]->getRut() == ruttransf)
                                            {
                                                saldotransf2 = lista[i]->getMonto() + transfer;
                                                lista[i]->setMonto(saldotransf2);
                                                cout << "Se ha agregado $" << transfer << " a la cuenta de "
                                                     << lista[i]->getNombre() << " hora su saldo es de $"
                                                     << lista[i]->getMonto() << endl;
                                            }
                                        }
                                    }
                                    break;
                                }
                                else
                                {
                                    cout << "No tiene saldo suficiente para transferir al cliente" << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (i == 399)
                {
                    cout << "No existe un cliente con ese rut, no se puede transferir" << endl;
                    break;
                }
            }
        }
    }
    void lineadeCredito(string rutbusq, int lineacred)
    {
        int lineacredf = 0;
        for (int i = 0; i < 400; i++)
        {
            if (lista[i] != NULL)
            {
                if (lista[i]->getRut() == rutbusq)
                {
                    lineacredf = lista[i]->getMonto() - lineacred;
                    lista[i]->setMonto(lineacredf);
                    cout << "Se ha dado un prestamo de $" << lineacred << " a la cuenta del cliente "
                         << lista[i]->getNombre()
                         << ", Ahora su saldo es: $" << lineacredf << endl;
                }
            }
        }
    }
    void imprimirCliente(int posimprimir)
    {
        lista[posimprimir]->imprimir();
    }
};

#endif