#include <iostream>
using namespace std;

int main()
{
    int entero = 10;
    string cadena = "";

    cadena = to_string(entero);

    std::cout << "Cadena: " << cadena << endl;

    return 0;
}