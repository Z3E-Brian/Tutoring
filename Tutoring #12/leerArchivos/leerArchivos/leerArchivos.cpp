#include <iostream>
#include "FileManager.h"
#include "RandomMatrixManager.h"
#include "PersonManager.h"

using namespace std;

int main() {
    FileManager fileManager;
    vector<string> linesToSave = { "Hola, mundo."
                                , "Este es un ejemplo.", 
                                  "Guardando texto en un archivo." };

    
    // Guardar las líneas en un archivo llamado "ejemplo.txt"
    fileManager.save(linesToSave, "ejemplo.txt");

    // Cargar las líneas desde el archivo "ejemplo.txt"
    vector<string> loadedLines = fileManager.load("ejplo.txt");

    // Mostrar las líneas cargadas
    for (const string& line : loadedLines) {
        cout << line << endl;
    }


    /*clase q administra la matriz de numeros aleatorios*/cout << endl << endl;

    RandomMatrixManager matrixManager;
    int numRows = 3;
    int numCols = 4;
    string fileName = "random_matrix.txt";

    // Generar y guardar la matriz
    matrixManager.generateAndSaveRandomMatrix(numRows, numCols, fileName);

    // Cargar y mostrar la matriz
    matrixManager.loadAndPrintMatrix(fileName);

    /*clase q agrega personas*/cout << endl << endl;

    PersonManager personManager;
    vector<Person> people = {
        Person("Juan", "Perez", 30, "Masculino"),
        Person("Maria", "Gonzalez", 25, "Femenino"),
        Person("Carlos", "Lopez", 35, "Masculino")
    };

    // Guardar la información de las personas en un archivo
    personManager.savePeopleToFile(people, "people.txt");

    // Cargar la información de las personas desde el archivo
    vector<Person> loadedPeople = personManager.loadPeopleFromFile("people.txt");

    // Mostrar la información de las personas en la consola
    personManager.displayPeople(loadedPeople);

    return 0;
}