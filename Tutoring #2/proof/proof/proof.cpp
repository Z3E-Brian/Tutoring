#include <iostream>
using namespace std;

// for(i;;i++){ cout << *&ptr[i] }
// for(i;;i++){ cout << ptr + i  }

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 }; // Declaración e inicialización del array
    int* ptr = arr; // ptr ahora apunta al primer elemento de arr

    int num = 456;
    int* ptr2 = &num;

    // Imprimir elementos del array usando el puntero
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << " del array: " << *&ptr[i] << endl;
        *&ptr[i] += 50;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << " del array: " << (ptr + i) << endl;
    }
    return 0;

}
/*
######################################################################################

#include <iostream>
using namespace std;

int main() {
    int var = 42;      // Variable original
    int* ptr = &var;   // Puntero a var
    int** ptr2 = &ptr; // Puntero a puntero a var

    // Acceso y manipulación usando punteros
    cout << "Valor de var: " << var << endl;         // 42
    cout << "Valor usando *ptr: " << *ptr << endl;   // 42
    cout << "Valor usando **ptr2: " << **ptr2 << endl; // 42

    // Direcciones de memoria
    cout << "Direccion de var (&var): " << &var << endl;
    cout << "Direccion almacenada en ptr: " << ptr << endl;
    cout << "Direccion almacenada en ptr2: " << ptr2 << endl;
    cout << "Direccion de ptr (&ptr): " << &ptr << endl;
    return 0;
}
/*
######################################################################################

#include <iostream>
using namespace std;

void modificarValor(int *ptr) {
    *ptr = 100; // Modificar el valor de la variable apuntada
}

int main() {
    int var = 42;
    cout << "Valor inicial de var: " << var << endl; // 42

    modificarValor(&var); // Pasar la direccion de var a la funcion

    cout << "Valor de var despues de llamar a modificarValor: " << var << endl; // 100

    return 0;
}

####################################################################################

#include <iostream>
using namespace std;

void modificarPuntero(int*& ptr) {
    static int nuevoValor = 200;
    ptr = &nuevoValor; // Cambiar el puntero para que apunte a nuevoValor
}

int main() {
    int var = 42;
    int* ptr = &var;

    cout << "Direccion de ptr antes de modificarPuntero: " << ptr << endl; // Dirección de var
    cout << "Valor apuntado por ptr antes de modificarPuntero: " << *ptr << endl; // 42

    modificarPuntero(ptr); // Pasar el puntero por referencia

    cout << "Direccion de ptr despues de modificarPuntero: " << ptr << endl; // Dirección de nuevoValor
    cout << "Valor apuntado por ptr despues de modificarPuntero: " << *ptr << endl; // 200
    return 0;
}
*/