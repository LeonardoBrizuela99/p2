/*2. Crear en otro proyecto un programa que siga los siguientes pasos :
a.Haga la lectura de los dos archivos guardados en el ejercicio anterior.
b.Imprima por pantalla los contenidos de las frases, especificando cuál es cuál(“la frase más larga es : ...”, por ejemplo).
c.Guarde en un archivo nuevo todas las palabras que tengan una cantidad decaracteres par(separadas por una coma)*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


bool esPar(int num)
{
    return num % 2 == 0;
}

int main()
{
    ifstream archivoLargo("../Actividad_3/long_text.txt");
    ifstream archivoCorto("../Actividad_3/short_text.txt");

    string fraseLarga, fraseCorta;

   
    getline(archivoLargo, fraseLarga);

    
    getline(archivoCorto, fraseCorta);

    
    cout << "La frase más larga es: " << fraseLarga << endl;
    cout << "La frase más corta es: " << fraseCorta << endl;

    
    vector<string> palabrasPar;

    
    auto separarPalabras = [](const string& frase) 
        {
        vector<string> palabras;
        string palabra;
        for (char c : frase) 
        {
            if (c == ' ') 
            {
                palabras.push_back(palabra);
                palabra.clear();
            }
            else {
                palabra += c;
            }
        }
        if (!palabra.empty()) 
        {
            palabras.push_back(palabra);
        }
        return palabras;
        };

   
    vector<string> palabrasLarga = separarPalabras(fraseLarga);
    for (const auto& palabra : palabrasLarga) {
        if (esPar(palabra.length())) {
            palabrasPar.push_back(palabra);
        }
    }

    
    vector<string> palabrasCorta = separarPalabras(fraseCorta);
    for (const auto& palabra : palabrasCorta)
    {
        if (esPar(palabra.length()))
        {
            palabrasPar.push_back(palabra);
        }
    }

    
    ofstream archivoPar("palabrasPar.txt");
    if (archivoPar.is_open()) 
    {
        for (const auto& palabra : palabrasPar) 
        {
            archivoPar << palabra << ",";
        }
        archivoPar.close();
        cout << "Se han guardado las palabras con cantidad de caracteres par en palabrasPar.txt" << endl;
    }
    else 
    {
        cout << "Error al abrir el archivo palabrasPar.txt" << endl;
        return 1;
    }

   
    archivoLargo.close();
    archivoCorto.close();

    return 0;
}