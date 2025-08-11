#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int matriz[7][7];
    int vector[7];
    int fila;

    // Inicializar la matriz con valores aleatorios
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    // Imprimir la matriz
    cout << "Matriz:" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Pedir al usuario que introduzca el número de la fila
    cout << "Introduce el número de la fila que deseas extraer (0-6): ";
    cin >> fila;

    // Verificar que la fila sea válida
    while (fila < 0 || fila > 6) {
        cout << "Número de fila inválido. Introduce un número entre 0 y 6: ";
        cin >> fila;
    }

    // Copiar la fila seleccionada al vector
    for (int i = 0; i < 7; i++) {
        vector[i] = matriz[fila][i];
    }

    // Imprimir el vector resultante
    cout << "Vector de la fila " << fila << ":" << endl;
    for (int i = 0; i < 7; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    return 0;
}
