#include <iostream>
using namespace std;

int main()
{

    string cadena;
    int bloque;

    // Seccion a)
    /*
    cout << "Ingrese la cadena: " << endl;
    cin >> cadena;
    */
    cadena = "intente_analizar_mas_profundamente_los_mensajes_recibidos";

    // Seccion b)
    cout << "Ingrese el numero de caracteres que tendra el bloque: " << endl;
    cin >> bloque;

    // Seccion d)
    while ( cadena.length() % bloque != 0 )
    {
        cadena.append("X");
    }

    // Seccion c)
    cout << " ------- Cadenas divididas------------- " << endl;
    for(int i = 0; i < cadena.length(); i=i+bloque)
    {
        cout << cadena.substr(i,bloque) << endl ;
    }
    cout << " ------- Cadenas divididas------------- " << endl;

    // Seccion e)
    string cadena_con_signo;
    for(int i = 0; i < cadena.length(); i=i+bloque)
    {
        cadena_con_signo.append( cadena.substr(i,bloque) );
        cadena_con_signo.append( "*" );
    }
    cout << cadena_con_signo << endl;

    // Seccion f) 
    /*
    char vector[cadena.length()];
    string divicion;

    for(int i = 0; i  < cadena.length() / bloque; i++)
    {
        for(int j = 0; j < cadena.length(); i=i+bloque)
        {
            divicion = cadena.substr(i,bloque);
        }
    }    
    */
    return 0;
}