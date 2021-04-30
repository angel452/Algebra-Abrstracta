#include <iostream>
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

int euclides(int num1, int num2)
{
    int q, r=1;

    if (num1 < num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (r != 0)
    {
        //num1 = (q*num2) + r
        q = num1/num2; 
        r = num1 - (q*num2);

        if (r != 0) // para que en la ultima operacion no haga el cambio y obtenga el num2
        {        
            num1 = num2;
            num2 = r;
        }
    }

    int mcd = num2;
    return mcd;
}

int euclides_extendido(int num_1, int num_2)
{
    int num1 = num_1, num2 = num_2, q, r;
    int r1, r2, s1, s2, t1, t2, s, t;

    // Para algorimto de euclides extendido
    r1 = num1; r2 = num2;
    s1 = 1; s2 = 0;
    t1 = 0; t2 = 1;
    // ---------------------------------------

    while (r != 0) // r != 0
    {
        //num1 = (q*num2) + r
        q = r1/r2; 
        r = r1 - (q*r2);

        if (r != 0) // para que en la ultima operacion no haga el cambio y obtenga el num2
        {        
            r1 = r2;
            r2 = r;
        }

        s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    int mcd = r2;

    /*
    cout << " -------- Algoritmo de Euclides ----------" << endl;
    cout << "El MCD es: " << mcd << endl;

    cout << " -------- Algoritmo de Euclides Extendido ----------"  << endl;
    cout << "x = " << s1 << endl;
    cout << "y = " << t1 << endl;
    cout << num1 << "(" << s1 << ") + " << num2 << "(" << t1 << ") = " << mcd << endl; 
    */
   
    return s1;
}

int inversa (int clave_a, int longitud)
{
    clave_a = euclides_extendido(clave_a,longitud);
    if (clave_a < 0)
    {
        clave_a = modulo(clave_a,longitud);
    }
    return clave_a;
} 