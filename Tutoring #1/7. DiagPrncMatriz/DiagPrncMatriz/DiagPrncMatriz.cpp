#include <iostream>
using namespace std;

int main() {
    int matriz[5][5];
    
    // Introducir valores en la matriz Random
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = rand() % 10 + 1;
        }
    }

    // Introducir valores en la matriz
    /*
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Introduce el valor de la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    */
    // Imprimir la diagonal principal

	// Imprimir la matriz
	cout << "Matriz:" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}

    cout << "Diagonal Principal:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;

    return 0;
}
