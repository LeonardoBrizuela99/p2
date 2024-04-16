/*1. Crear en un proyecto un programa que siga los siguientes pasos:a. Solicite el ingreso de dos textos al usuario.b.
Haga la escritura de la frase más larga en un archivo de texto llamado“long_text.txt”.c.
Haga la escritura de la frase más corta en un archivo de texto llamado“short_text.txt”*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    string texto1, texto2;

    
    cout << "Ingrese el primer texto: ";
    getline(cin, texto1);

    cout << "Ingrese el segundo texto: ";
    getline(cin, texto2);

   
    string long_text, short_text;

    if (texto1.length() >= texto2.length()) {
        long_text = texto1;
        short_text = texto2;
    }
    else {
        long_text = texto2;
        short_text = texto1;
    }

    
    ofstream long_file("long_text.txt");
    if (long_file.is_open()) {
        long_file << long_text;
        long_file.close();
        cout << "La frase mas larga se ha guardado en long_text.txt\n";
    }
    else {
        cerr << "No se pudo abrir el archivo long_text.txt\n";
    }

    
    ofstream short_file("short_text.txt");
    if (short_file.is_open()) {
        short_file << short_text;
        short_file.close();
        cout << "La frase mas corta se ha guardado en short_text.txt\n";
    }
    else {
        cerr << "No se pudo abrir el archivo short_text.txt\n";
    }

    return 0;
}
