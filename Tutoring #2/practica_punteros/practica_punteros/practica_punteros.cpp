#include <iostream>
using namespace std;

void modificarPorReferencia(int& num) {//recibe int por referencia para modificarlo correctamente
    num = 10;
}

void modificarValor(int* ptr) {
    *ptr = 100; // Cambiar el valor apuntado por ptr
}

void imprimirArreglo(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main() {
    //#0
    int numero = 5;
    modificarPorReferencia(numero);
    std::cout << "Numero despues de modificarPorReferencia: " << numero << std::endl; // Salida: 10

/*######################################################################*/
    //#1
    // Asignar memoria para dos enteros
    int n = 10;
    int *num1 = new int(n);
    int* num2 = new int(20);

    // Imprimir los valores
    cout << "Valor de num1: " << *num1 << endl; // Imprime 10
    cout << "Valor de num2: " << *num2 << endl; // Imprime 20

    // Liberar memoria
    delete num1;
    delete num2;

/*######################################################################*/
    //#2
    int* arr = new int[5]; // Asignar memoria para un arreglo de 5 enteros

    // Inicializar el arreglo
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }

    // Imprimir el arreglo
    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Liberar memoria
    delete[] arr;

/*######################################################################*/
    //#3
    int** ptrArray = new int* [3]; // Arreglo de punteros a enteros

    // Asignar memoria para cada entero en el arreglo
    for (int i = 0; i < 3; ++i) {
        ptrArray[i] = new int(i * 10);
    }

    // Imprimir los valores
    for (int i = 0; i < 3; ++i) {
        cout << "ptrArray[" << i << "] = " << *ptrArray[i] << endl;
    }

    // Liberar memoria
    for (int i = 0; i < 3; ++i) {
        delete ptrArray[i];
    }
    delete[] ptrArray;

/*######################################################################*/
    //#4
    int* num = new int(50); // Asignar memoria e inicializar

    cout << "Valor antes de modificar: " << *num << endl; // Imprime 50

    modificarValor(num); // Llamar a la función para modificar el valor

    cout << "Valor después de modificar: " << *num << endl; // Imprime 100

    delete num; // Liberar memoria

/*######################################################################*/
    //#5
    const char* strArray[3] = { "Hola", "Mundo", "Punteros" };

    // Imprimir cada cadena
    for (int i = 0; i < 3; ++i) {
        cout << "strArray[" << i << "] = " << strArray[i] << endl;
    }

/*######################################################################*/
    //#5
    int* arr5 = new int[5] {1, 2, 3, 4, 5}; // Inicializar un arreglo

    imprimirArreglo(arr5, 5); // Llamar a la función con el arreglo

    delete[] arr5; // Liberar memoria










    return 0;
}
