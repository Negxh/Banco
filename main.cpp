#include <iostream>
using namespace std;

#include "Banco.h"
#include "Cliente.h"
#include "menus.h"

int main()
{

    Banco *b = new Banco();
    int opcion1;

    while (true)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "MENU BANCO UNIVERSITARIO PORTALEANO" << endl;
        cout << " " << endl;

        menuPrincipal();

        cout << "----------------------------------------------------" << endl;
        cout << "Marque su opcion: ";
        cin >> opcion1;
        cout << "----------------------------------------------------" << endl;
        if (opcion1 == 1)
        {
            string rut, nombre;
            int edad;

            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el rut: ";
            cin >> rut;
            cout << "Igrese la edad: ";
            cin >> edad;
            cout << "----------------------------------------------------" << endl;
            Cliente *c = new Cliente(nombre, rut, edad);
            b->agregarCliente(c);
        }
        if (opcion1 == 2)
        {
            string rutbusq;
            int opcion2;
            cout << "Ingrese rut del cliente: ";
            cin >> rutbusq;
            cout << "----------------------------------------------------" << endl;
            if (b->buscarCliente(rutbusq) == true)
            {
                while (true)
                {
                    cout << "MENU DE ATENCION AL CLIENTE" << endl;
                    cout << " " << endl;
                    cout << "----------------------------------------------------" << endl;

                    menuCliente();

                    cout << "----------------------------------------------------" << endl;
                    cout << "Marque su opcion: ";
                    cin >> opcion2;
                    cout << "----------------------------------------------------" << endl;

                    if (opcion2 < 1 || opcion2 > 4)
                    {
                        break;
                    }
                    if (opcion2 == 1)
                    {
                        int depositar = 0;
                        cout << "Ingrese monto a depositar: $";
                        cin >> depositar;
                        b->DepositoCliente(rutbusq, depositar);
                        cout << "----------------------------------------------------" << endl;
                    }
                    if (opcion2 == 2)
                    {
                        int girar = 0;
                        cout << "Ingrese monto a girar: $";
                        cin >> girar;
                        b->GirarCliente(rutbusq, girar);
                        cout << "----------------------------------------------------" << endl;
                    }
                    if (opcion2 == 3)
                    {
                        string ruttransf;
                        int transfer = 0;
                        cout << "Ingrese rut del cliente al que desea transferir: ";
                        cin >> ruttransf;
                        if (b->buscarCliente(ruttransf) == true)
                        {
                            cout << "Cliente encontrado con exito: " << endl;
                            cout << " " << endl;
                            cout << "Ingrese monto a transferir: $";
                            cin >> transfer;
                            b->transferirCliente(rutbusq, ruttransf, transfer);
                            cout << "----------------------------------------------------" << endl;
                        }
                        else
                        {
                            cout << "No existe un cliente con ese rut" << endl;
                            cout << "----------------------------------------------------" << endl;
                        }
                    }
                    if (opcion2 == 4)
                    {
                        int lineacred;
                        cout << "Ingrese monto de prestamo: $";
                        cin >> lineacred;
                        b->lineadeCredito(rutbusq, lineacred);
                        cout << "----------------------------------------------------" << endl;
                    }
                }
            }
            else if (b->buscarCliente(rutbusq) == false)
            {
                cout << "No se ha encontrado el cliente" << endl;
            }
        }
        if (opcion1 == 3)
        {
            b->dineroTotal();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion1 == 4)
        {
            b->totalClientes();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion1 == 5)
        {
            b->clientemasViejo();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion1 == 6)
        {
            b->clientesDeudores();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion1 == 7)
        {
            cout << "Gracias por preferir nuestro banco, Vuelva pronto!" << endl;
            cout << "----------------------------------------------------" << endl;
            break;
        }
        if (opcion1 == 8)
        {
            int posimprimir;
            cout << "Ingrese la posicion del cliente para obtener su informacion: ";
            cin >> posimprimir;
            b->imprimirCliente(posimprimir);
        }
    }

    return 0;
}
