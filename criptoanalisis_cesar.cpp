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

        int longitud_alfabeto()
        {
            return alfabeto.length() + 1;
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
    int clave;

    cout << "----------- Progrmama de criptoanalisis -----------------" << endl;

    cout << "Ingrese el mensaje que desea descodificar: ";
    getline(cin,mensaje);

    Cesar longitud(mensaje,0);

    cout << "Posibles Mensajes: " << endl;
    for(int i = 1; i < longitud.longitud_alfabeto() ; i++)
    {
        Cesar receptor(mensaje,i);
        cout << "Clave " << i << ": " << receptor.decodificar() << endl;        
    }

    return 0;
}