#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int vector[10];
    for (int i = 0; i < 10; i++) {
        vector[i] = rand() % 100 + 1;
    }
    int limite;
    cout << "Introduce un numero limite: ";
    cin >> limite;
    int contador = 0;
    for (int i = 0; i < 10; i++) {
        if (vector[i] > limite) {
            contador++;
        }
    }
    cout << "Hay " << contador << " elementos mayores que " << limite << endl;

    cout << "Vector obtenido" << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << ". " << vector[i] << endl;
    }

    return 0;
}
