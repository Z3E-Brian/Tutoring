#include "RandomMatrixManager.h"

// Genera una matriz de números aleatorios y la guarda en un archivo
void RandomMatrixManager::generateAndSaveRandomMatrix(int rows, int cols, const string& fileName) {
    vector<string> matrixLines;
    srand(time(0));  // Inicializa la semilla para la generación de números aleatorios

    for (int i = 0; i < rows; ++i) {
        string row;
        for (int j = 0; j < cols; ++j) {
            int randomValue = rand() % 100;  // Números aleatorios entre 0 y 99
            row += to_string(randomValue);
            if (j < cols - 1) {
                row += " ";
            }
        }
        matrixLines.push_back(row);
    }

    fileManager.save(matrixLines, fileName);
}

// Carga y muestra la matriz desde un archivo
void RandomMatrixManager::loadAndPrintMatrix(const string& fileName) {
    vector<string> loadedLines = fileManager.load(fileName);

    for (const string& line : loadedLines) {
        cout << line << endl;
    }
}