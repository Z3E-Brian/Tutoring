#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int matriz[6][6];
    int suma = 0;

    // Inicializar la matriz con valores aleatorios
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            matriz[i][j] = rand() % 50 + 1;
        }
    }

    // Calcular la suma de los elementos por debajo de la diagonal principal
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < i; j++) {
            suma += matriz[i][j];
        }
    }

    // Imprimir la matriz
    cout << "Matriz:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Imprimir la suma
    cout << "Suma de los elementos por debajo de la diagonal principal: " << suma << endl;

    /*####################################################################################*/

    int matriz1[3][3];
    int matriz2[3][3];
    int producto[3][3] = { 0 };

    // Inicializar las matrices con valores aleatorios
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz1[i][j] = rand() % 10 + 1;
            matriz2[i][j] = rand() % 10 + 1;
        }
    }

    // Calcular el producto de las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    cout<< endl<<"#########################################"<<endl << endl;
    

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

    cout << "Producto de Matrices:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << producto[i][j] << " ";
        }
        cout << endl;
    }

    cout<< endl<<"#########################################"<<endl << endl;

        const int tamano = 5;
        int matriz0[tamano][tamano];
        int filas[tamano * tamano];
        int columnas[tamano * tamano];
        int contador = 0;
        int numero;

        // Inicializar la matriz con valores aleatorios
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                matriz0[i][j] = rand() % 20 + 1;
            }
        }

        // Imprimir la matriz
        cout << "Matriz:" << endl;
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                cout << matriz0[i][j] << " ";
            }
            cout << endl;
        }

        // Pedir al usuario que introduzca un número a buscar
        cout << "Introduce el numero a buscar: ";
        cin >> numero;

        // Buscar el número en la matriz y guardar las posiciones
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                if (matriz0[i][j] == numero) {
                    filas[contador] = i;
                    columnas[contador] = j;
                    contador++;
                }
            }
        }

        // Imprimir las posiciones del número encontrado
        if (contador > 0) {
            cout << "El numero " << numero << " se encuentra en las posiciones:" << endl;
            for (int i = 0; i < contador; i++) {
                cout << "[" << filas[i] << "][" << columnas[i] << "]" << endl;
            }
        }
        else {
            cout << "El número " << numero << " no se encuentra en la matriz." << endl;
        }




    return 0;
}
