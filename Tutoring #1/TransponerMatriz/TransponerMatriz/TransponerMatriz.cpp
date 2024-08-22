#include <iostream>
using namespace std;

int main() {

    int matriz[4][4];
    int transpuesta[4][4];
    
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
    /*
    // Introducir valores en la matriz
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Introduce el valor de la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    */

    // Calcular la transpuesta
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Imprimir la matriz original
    cout << "Matriz Original:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Imprimir la matriz transpuesta
    cout << "Matriz Transpuesta:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
