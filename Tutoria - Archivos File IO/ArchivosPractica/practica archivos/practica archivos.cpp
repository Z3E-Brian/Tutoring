#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//concatenar archivos
/*

int main() {
    ifstream archivo1("archivo1.txt");
    ifstream archivo2("archivo2.txt");
    ofstream archivoSalida("resultado.txt");

    if (archivo1.is_open() && archivo2.is_open() && archivoSalida.is_open()) {
        
        string linea;

        



        while (getline(archivo1, linea)) {
            archivoSalida << linea << endl;
        }

        while (getline(archivo2, linea)) {
            archivoSalida << linea << " ";
        }

        archivo1.close();
        archivo2.close();
        archivoSalida.close();


        cout << "Archivos combinados con éxito." << endl;
    }
    else {
        cout << "No se pudieron abrir los archivos." << endl;
    }

    return 0;
}

//contar palabras

int contarPalabras(const string& texto) {
    int contador = 0;
    bool enPalabra = false;

    for (char caracter : texto) {
        if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
            enPalabra = false;
        }
        else if (!enPalabra) {
            contador++;
            enPalabra = true;
        }
    }

    return contador;
}

int main() {
    ifstream archivo("archivo.txt");

    if (archivo.is_open()) {
        string texto;
        string linea;

        while (getline(archivo, linea)) {
            texto += linea + "\n";
        }

        int palabras = contarPalabras(texto);

        cout << "Numero de palabras en el archivo: " << palabras << endl;

        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
*/
//buscar repeticion de palabra
/*
int contarRepeticiones(const string& palabraABuscar, const string& texto) {
    int contador = 0;
    int pos = 0;

    while ((pos = texto.find(palabraABuscar, pos)) != string::npos) {
        contador++;
        pos += palabraABuscar.length();
    }

    return contador;
}

int main() {
    ifstream archivo("archivo.txt");
    if (archivo.is_open()) {
        string palabraABuscar;
        cout << "Ingrese la palabra a buscar: ";
        cin >> palabraABuscar;

        string linea;
        string texto;

        while (getline(archivo, linea)) {
            texto += linea + " ";  // Agregar un espacio para asegurarse de contar palabras completas
        }

        int repeticiones = contarRepeticiones(palabraABuscar, texto);

        cout << "La palabra '" << palabraABuscar << "' aparece " << repeticiones << " veces en el archivo." << endl;
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return 0;
}
*/

//eliminar linea

int main() {
    ifstream archivoEntrada("archivo.txt");
    ofstream archivoSalida("nuevo_archivo.txt");

    if (archivoEntrada.is_open() && archivoSalida.is_open()) {
        int numeroLineaAEliminar;
        cout << "Ingrese el número de línea a eliminar: ";
        cin >> numeroLineaAEliminar;

        string linea;
        vector<string> lineas;


        while (getline(archivoEntrada, linea)) {
            lineas.push_back(linea);
        }

        archivoEntrada.close();
    
        
        if (numeroLineaAEliminar > 0 && numeroLineaAEliminar <= lineas.size()) {
            lineas.erase(lineas.begin() + (numeroLineaAEliminar - 1));
        }
        else {
            cout << "Número de línea no válido." << endl;
            return 1;
        }

        for (const string& l : lineas) {
            archivoSalida << l << endl;
        }

        archivoSalida.close();

        cout << "Línea eliminada con éxito." << endl;
    }
    else {
        cout << "No se pudieron abrir los archivos." << endl;
    }

    return 0;
}