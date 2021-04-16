#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;

int main()
{

    string cadena;

    cout << "Ingrese la cadena de texto que contenga numeros: ";
    cin >> cadena;

    int entero = atoi(cadena.c_str());

    cout << "Tu numero en entero es: " << entero << endl;

    return 0;
}