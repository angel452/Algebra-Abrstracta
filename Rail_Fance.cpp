/*
Correccion...
La tercera funcion (string completar) se encuentra dentro del main. Linea 104 - 111
*/

#include <iostream>
#include <string>
using  namespace  std;

class Programa
{
    private:
        string mensaje;
        int clave_fila;

    public:
        Programa(string _mensaje, int _clave_fila)
        {
            mensaje = _mensaje;
            clave_fila = _clave_fila;
        }

        void codificar()
        {
            int nElementos;
            char vacio[100];
            int rondas;
            int nronda = 0;
            int contador = 0;
            
            nElementos = (clave_fila*2)-2; //6
            rondas = mensaje.length() / nElementos; // 3

            for (int a = 0; a < mensaje.length(); a = a + ((clave_fila*2) - 2)) // < 24
            {
                //cout << a << endl;
                vacio[contador] = mensaje[a];
                contador = contador + 1;
            }

            for(int i = 1; i < clave_fila - 1; i++) // < 4
            {
                for (int  j = 0; j < rondas; j++) // < 3
                {
                    int ini, fin;
                    
                    ini = ((nElementos*(j+1)) - (nElementos - 1)) + (i-1); // 8 - 7 + 0 = 1
                    fin = ((nElementos * (j+1)) - 1) - (i-1); // 8 - 1 - 0 = 7

                    //cout << "[" << ini << "][" << fin << "]" << endl;

                    vacio[contador] = mensaje[ini];
                    contador = contador + 1;
                    vacio[contador] = mensaje[fin];
                    contador = contador + 1;
                }
            }

            for(int b = clave_fila - 1; b < mensaje.length(); b = b + ((clave_fila*2) - 2) )
            {
                //cout << b << endl;
                vacio[contador] = mensaje[b];
                contador = contador + 1; 
            }

            cout << "El mensaje Codificado es: " << vacio << endl;
        }

        void descodificar()
        {

        }

};

int main()
{
    string mensaje;
    int clave_filas;
    int respuesta;

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

        do
        {
            cout << "---------------------------------------------------- " << endl;
            cout << "RECUERDA QUE LA CLAVE DEBE SER MAYOR O IGUAL A 2" << endl;
            cout << "Ingrese la clave: ";
            cin >> clave_filas;

        } while ( clave_filas < 2 );

        // -------------- Para rellenar espacios del mensaje ---------------------
        int nElementos = (clave_filas*2)-2; //6;
            
        while (mensaje.length() % (nElementos) != 0)
        {
            mensaje.push_back('_');
        }
        // --------------------------------------------------------------

        Programa emisor(mensaje, clave_filas);

        emisor.codificar();
    }

    else if(respuesta == 2)
    {

        cout << "Ingrese el mensaje que desea descodificar: ";
        cin.ignore();
        getline(cin,mensaje);

        cout << "---------------------------------------------------- " << endl;
        cout << "Ingrese la clave: ";
        cin >> clave_filas;

        Programa receptor(mensaje, clave_filas);

        receptor.descodificar();
    }
    return 0;
}
