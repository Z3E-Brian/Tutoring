#include <iostream>
using namespace std;

/*Ejercicio #1 */
void sumarYModificar(int* ptr, int& ref) {
    ref += *ptr;
}

/*Ejercicio #3 */
void cambiarPuntero(int** ptr2ptr) {
    static int nuevoValor = 50;
    *ptr2ptr = &nuevoValor;
}


int main() {
    //#1
   int* num1 = new int(10);
   int num2 = 5;
   
    cout << "Valor antes de modificar: " << num2 << endl;

    sumarYModificar(num1, num2); 

    cout << "Valor despues de modificar: " << num2 << endl; 

    /**************************************************************************************/
    //#2
    int a = 10, b = 20, c = 30;
    int* arr[3];

    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    for (int i = 0; i < 3; ++i) {
        cout << "Valor de arr[" << i << "]: " << *arr[i] << ", Direccion: " << arr[i] << endl;
    }

    /**************************************************************************************/
    //#3

    int num = 20;
    int* ptr = &num;

    cout << "Antes de cambiar: " << *ptr << endl;

    cambiarPuntero(&ptr);

    cout << "Despues de cambiar: " << *ptr << endl;

    /**************************************************************************************/
    //#4

    const char* cadenas[3] = { "Hola", "Mundo", "C++" };

    for (int i = 0; i < 3; ++i) {
        cout << "Cadena " << i << ": " << cadenas[i] << endl;
    }

    return 0;
}
