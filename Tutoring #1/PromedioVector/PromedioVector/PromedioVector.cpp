#include <iostream>
using namespace std;

int main() {
    int vector[10];
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Introduce el elemento " << i + 1 << ": ";
        cin >> vector[i];
        suma += vector[i];
    }
    double promedio = suma / 10.0;
    cout << "El promedio de los elementos es: " << promedio << endl;
    return 0;
}
