#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int matriz1[3][3];
    int matriz2[3][3];
    int suma[3][3];

    // Inicializar matrices con valores aleatorios
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz1[i][j] = rand() % 10 + 1;
            matriz2[i][j] = rand() % 10 + 1;
        }
    }

    // Calcular la suma de las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Imprimir las matrices
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz 2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Suma de Matrices:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << suma[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
