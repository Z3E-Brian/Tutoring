#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "FileManager.h"

using namespace std;

class RandomMatrixManager {
public:

    // Genera una matriz de números aleatorios y la guarda en un archivo
    void generateAndSaveRandomMatrix(int,int,const string&);

    // Carga y muestra la matriz desde un archivo
    void loadAndPrintMatrix(const string&);

private:
    FileManager fileManager;
};


