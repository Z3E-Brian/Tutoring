#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int vector[10];
    for (int i = 0; i < 10; i++) {
        vector[i] = rand() % 100 + 1;
    }

    cout << "Vector inicial:\n";

    for (int i = 0; i < 10; i++) {
        cout << vector[i] << endl;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    cout << "Vector final:\n";

    for (int i = 0; i < 10; i++) {
        cout << vector[i] << endl;
    }
    return 0;
}
