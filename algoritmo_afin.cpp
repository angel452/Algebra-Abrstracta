#include <iostream>
#include <string>
#include <string.h>
#include "algoritmo_afin_funciones.h"
using namespace std;

class Afin
{
    private:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26
        string mensaje;
        int clave_a;
        int clave_b;

    public:
        Afin(string _mensaje, int _clave_a, int _clave_b)
        {
            mensaje = _mensaje;
            clave_a = _clave_a;
            clave_b = _clave_b;
        }
        
        void cifrado_generar_clave_a()
        {
            int a, longitud_alfabeto;

            longitud_alfabeto = alfabeto.length();
            a = rand()%alfabeto.length();

            while (euclides(a,longitud_alfabeto) != 1)
            {
                a = rand()%alfabeto.length();
            }
            
            clave_a = a;
        }

        void cifrado_generar_clave_b()
        {
            int b;
            b = rand()%alfabeto.length();
            clave_b = b;
        }
        
        string cifrado()
        {
            for (int i = 0; i < mensaje.length(); i++)
            {
                for (int j = 0; j < alfabeto.length(); j++)
                {
                    if ( mensaje[i] == alfabeto[j])
                    {
                        //int formula = 5*j + 8;
                        int formula = clave_a*j + clave_b;
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

        string decifrado() // hpccxaq
        {
            int num = inversa(clave_a,alfabeto.length()); 
            for (int i = 0; i < mensaje.length(); i++)
            {
                for (int j = 0; j < alfabeto.length(); j++)
                {
                    if ( mensaje[i] == alfabeto[j])
                    {
                        int formula = num*(j - clave_b);
                        if ( formula < 0 || formula > alfabeto.length() - 1)
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

        void return_clave_a()
        {
            cout << "La clave a es: " << clave_a << endl;
        }

        void return_clave_b()
        {
            cout <<  "La clave b es: " << clave_b << endl;
        }
};


int main()
{
    string mensaje;
    int respuesta;
    int clave_a, clave_b;

    cout << "----------- Progrmama de criptografia - Afin - -----------------" << endl;
    cout << "Que deseas hacer: " << endl;
    cout << "Encriptar un mensaje ................ 1" << endl;
    cout << "Descodificar un mensaje ............. 2" << endl;
    cout << "Respuesta:  ";
    cin >> respuesta;

    if (respuesta == 1)
    {
        cout << "Ingrese el mensaje que desea encriptar: "; //itscool
        cin.ignore();
        getline(cin, mensaje);
        //cin >> mensaje;

        cout << "-------------------------------------------------------------" << endl;
        cout << "Tu mensaje es: " << mensaje << endl;

        Afin emisor(mensaje,0,0);
        emisor.cifrado_generar_clave_a();
        emisor.cifrado_generar_clave_b();
        cout << "-------------------------------------------------------------" << endl;
        cout << "Estas son tus claves. Ten cuidado en no mostrar a nadie mas :)" << endl;
        emisor.return_clave_a();
        emisor.return_clave_b();
        cout << "-------------------------------------------------------------" << endl;
        cout << "El mensaje cifrado es: " << emisor.cifrado() << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    
    else if(respuesta == 2)
    {
        cout << "Ingrese el mensaje que desea descodificar: ";
        cin.ignore();
        getline(cin,mensaje);
        //cin >> mensaje;
        
        cout << "-------------------------------------------------------------" << endl;
        cout << "Tu mensaje es: " << mensaje << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Ingrese la clave a: ";
        cin >> clave_a;
        cout << "Ingrese la clave b: ";
        cin >> clave_b;
        cout << "-------------------------------------------------------------" << endl;
        Afin receptor(mensaje,clave_a, clave_b);
        cout << "-------------------------------------------------------------" << endl;
        cout  << "El mensaje decifrado es: " << receptor.decifrado() << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}