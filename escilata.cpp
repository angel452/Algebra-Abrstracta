/*
Descripción:
El programa, en general, hace uso de clases, punteros y sobre todo matrices (pues son la base de la encriptación practicada). Para el caso de las CLAVES, estas deberán ser ingresadas una por una en el momento que se le pregunta al usuario "Ingrese la clave 1" y de la misma manera cuando pregunte "Ingrese la clave 2". 
Algunos puntos adicionales:
Las dos primeras funciones de la clase (rellenar_matriz y  codificador ) son las que se encargan de codificar el mensaje; las siguientes 2 (rellenar_matriz2 y  descodificar ) son las que descodificarán el mensaje; la ultima es una funcion simple de mostrar la matriz que se usa. 
El programa volvera a preguntar las claves en caso la frase sea mas larga que la cantidad de espacios de la matriz; caso contrario que la frase si entre, rellenara los espacios sobrantes con el siguiente caracter "_" .
Ejemplo:

Respuesta:  1
    Ingrese el mensaje que desea encriptar: Hola como estas?
    Ingrese la clave 1: 3
    Ingrese la clave 2: 6
    Mensaje codificado: 
    Hotomalosa ? e_cs_
Respuesta:  2
    Ingrese el mensaje que desea descodificar: Hotomalosa ? e_cs_
    Ingrese la clave 1: 3
    Ingrese la clave 2: 6
    Mensaje descodificado: 
    Hola como estas?__
*/
#include <iostream>
#include <string>
using namespace std;

class Programa
{
private:
    string mensaje;
    int clave_columna;
    int clave_fila;
    char **puntero_matriz;

public:
    Programa(string _mensaje, int _clave_columna, int _clave_fila)
    {
        mensaje = _mensaje;
        clave_columna = _clave_columna;
        clave_fila = _clave_fila;

        puntero_matriz = new char *[clave_fila];
        for(int i = 0; i < clave_fila; i++)
        {
            puntero_matriz[i] = new char[clave_columna];
        }
    }

    void rellenar_matriz()
    {
        int conatador2 = 0;

        for(int i = 0; i < clave_fila; i++)
        {
            for(int j = 0; j < clave_columna; j++)
            {
                if (conatador2 < mensaje.length())
                {
                    puntero_matriz[i][j] = mensaje[conatador2];
                    conatador2 = conatador2 + 1;
                }
                else
                {
                    puntero_matriz[i][j] = '_';
                    conatador2 = conatador2 + 1;
                }
            }
        }
    }

    void codificador()
    {
        for(int i = 0; i < clave_columna; i++)
        {
            for(int j = 0; j < clave_fila; j++)
            {
                cout << puntero_matriz[j][i];
            }
        }
        cout << endl;
    }

    void rellenar_matriz2()
    {
        int conatador = 0;

        for(int i = 0; i < clave_columna; i++)
        {
            for(int j = 0; j < clave_fila; j++)
            {
                puntero_matriz[j][i] = mensaje[conatador];
                conatador = conatador + 1;
            }
        }
    }

    void descodificar()
    {
        for(int i = 0; i < clave_fila; i++)
        {
            for(int j=0; j < clave_columna; j++)
            {
                cout << puntero_matriz[i][j];
            }
        }
        cout << endl;
    }

    void mostrar_matriz()
    {
        cout << "------------------- Matriz ------------------------ " << endl;
        for(int i = 0; i < clave_fila; i++)
        {
            for(int j = 0; j < clave_columna; j++)
            {
                cout << puntero_matriz[i][j];
            }
            cout << endl;
        }
        cout << "---------------------------------------------------- " << endl;
    }
};

int main()
{
    string mensaje;
    int clave_filas;
    int clave_columnas;
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
            cout << "RECUERDA QUE LA FRACE DEBE ENTRAR EN LA MATRIZ" << endl;
            cout << "Ingrese la clave 1: ";
            cin >> clave_filas;

            cout << "Ingrese la clave 2: ";
            cin >> clave_columnas;
            cout << "---------------------------------------------------- " << endl;

        } while ( mensaje.length() > (clave_filas * clave_columnas));

        Programa emisor(mensaje, clave_columnas, clave_filas);

        emisor.rellenar_matriz();
        emisor.mostrar_matriz();

        cout << "Mensaje codificado: " << endl;
        emisor.codificador();
    }

    else if(respuesta == 2)
    {

        cout << "Ingrese el mensaje que desea descodificar: ";
        cin.ignore();
        getline(cin,mensaje);

        do
        {
            cout << "---------------------------------------------------- " << endl;
            cout << "RECUERDA QUE LA FRACE DEBE ENTRAR EN LA MATRIZ" << endl;
            cout << "Ingrese la clave 1: ";
            cin >> clave_filas;

            cout << "Ingrese la clave 2: ";
            cin >> clave_columnas;
            cout << "---------------------------------------------------- " << endl;

        } while ( mensaje.length() > (clave_filas * clave_columnas));

        Programa receptor(mensaje, clave_columnas, clave_filas);
        receptor.rellenar_matriz2();
        receptor.mostrar_matriz();

        cout << "Mensaje descodificado: " << endl;
        receptor.descodificar();
    }

    return 0;
}