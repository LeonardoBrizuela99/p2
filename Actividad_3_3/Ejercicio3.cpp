#include <iostream>
#include <fstream>
#include <string>

/*Crear en otro proyecto un programa que,
sin recurrir a archivos de textoadicionales,
imprima su propio código fuente en la consola*/

using namespace std;

int main() {
    ifstream src(__FILE__); // (__FILE__) es una macro que contiene el nombre del archivo fuente)
    
    if (src)
    {
        
        string line;
        while (getline(src, line))
        {
            cout << line << endl;
        }

        src.close(); 
    }
    else 
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    return 0;
}
