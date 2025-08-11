#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;

int main() {
    srand(time(NULL));
    int vector[15];
    for (int i = 0; i < 15; i++) {
        vector[i] = rand() % 100 + 1;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < 15; i++) {
        if (vector[i] < min) {
            min = vector[i];
        }
        if (vector[i] > max) {
            max = vector[i];
        }
    }

    cout << "Vector obtenido:\n";

    for (int i = 0; i < 15; i++) {
        cout << i << ". " << vector[i] << endl;
    }

    cout << "El valor minimo es: " << min << endl;
    cout << "El valor maximo es: " << max << endl;
    return 0;
}
