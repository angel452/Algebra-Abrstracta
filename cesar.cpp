#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int modulo(int a, int n)
{
    //a = q*n+r
    int q = a/n;
    int r = a%n;

    if (r < 0)
    {
        q = q - 1;
        r = a - (q*n);
    }

    return r;
}


class Cesar
{
    private:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        string mensaje;
        int clave;

    public:
        Cesar(string _mensaje, int _clave)
        {
            mensaje = _mensaje;
            clave = _clave;
        }

        string codificar()
        {
            for (int i = 0; i < mensaje.length(); i++)
            {
                for (int j = 0; j < alfabeto.length(); j++)
                {
                    if ( mensaje[i] == alfabeto[j])
                    {
                        int formula = j + clave;
                        if ( formula >= alfabeto.length() )
                        {
                            formula = modulo( formula, alfabeto.length() );
                        }

                        mensaje[i] = alfabeto[formula];
                        break;
                    }       
                }   
            }

            return mensaje;
        }

        string decodificar()
        {
            for (int i = 0; i < mensaje.length(); i++)
            {
                for (int j = 0; j < alfabeto.length(); j++)
                {
                    if ( mensaje[i] == alfabeto[j])
                    {
                        int formula = j - clave;
                        if ( formula < 0 )
                        {
                            formula = modulo(formula,alfabeto.length());
                        }

                        mensaje[i] = alfabeto[formula];
                        break;
                    }       
                }   
            }

            return mensaje;
        }
};

int main()
{
    string mensaje;
    int respuesta;
    int clave;

    cout << "----------- Progrmama de criptografia -----------------" << endl;
    cout << "Que deseas hacer: " << endl;
    cout << "Encriptar un mensaje ................ 1" << endl;
    cout << "Descodificar un mensaje ............. 2" << endl;
    cout << "Respuesta:  ";
    cin >> respuesta;

    if (respuesta == 1)
    {

        cout << "Ingrese el mensaje que desea encriptar: ";
        cin.ignore();
        getline(cin,mensaje);
        cout << "Ingrese la clave: ";
        cin >> clave;

        Cesar emisor(mensaje,clave);

        cout << "Mensaje codificado: " << endl;
        cout << emisor.codificar() << endl;
    }

    else if(respuesta == 2)
    {

        cout << "Ingrese el mensaje que desea descodificar: ";
        cin.ignore();
        getline(cin,mensaje);

        cout << "Ingrese la clave: ";
        cin >> clave;

        Cesar receptor(mensaje,clave);

        cout << "Mensaje descodificado: " << endl;
        cout << receptor.decodificar() << endl;
    }

    return 0;
}