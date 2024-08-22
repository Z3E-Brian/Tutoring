#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int size = 3;
    int* arr = new int[size];

    // Inicializar el arreglo original
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // Imprimir el arreglo original
    /*cout << "Arreglo original: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    // Aumentar el tamanno del arreglo
    int newSize = 5;
    int* newArr = new int[newSize]; // Crear un nuevo arreglo con tamanno mayor

    // Copiar elementos del arreglo original al nuevo arreglo
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    // Inicializar los nuevos elementos
    for (int i = size; i < newSize; i++) {
        newArr[i] = i + 1;
    }

    // Liberar la memoria del arreglo original
    delete[] arr;

    // Actualizar el puntero para que apunte al nuevo arreglo
    arr = newArr;
    size = newSize;

    // Imprimir el nuevo arreglo
    /*cout << "Nuevo arreglo: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    // Liberar la memoria del nuevo arreglo
    delete[] arr;

    /*********************************PRACTICA***********************************/
    /*#1*/
    printf("Ejercicio #1\n\n");

    int sizeEjercicio1;
    printf("Introduce el tamanno del arreglo: ");
    scanf_s("%d", &sizeEjercicio1);

    int* arregloEjercicio1 = new int[sizeEjercicio1];

    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < sizeEjercicio1; i++) {
        scanf_s("%d", &arregloEjercicio1[i]);
    }

    int sum = 0;
    for (int i = 0; i < sizeEjercicio1; i++) {
        sum += arregloEjercicio1[i];
    }

    printf("La suma de los elementos es: %d\n", sum);

    delete[] arregloEjercicio1;

    /********#2************/
    printf("Ejercicio #2\n\n");


    int sizeEjercicio2;
    printf("Introduce el tamanno del arreglo: ");
    scanf_s("%d", &sizeEjercicio2);

    // Asignacion dinamica de memoria para el arreglo
    int* arrEjercicio2 = new int[sizeEjercicio2];

    // Inicializar el generador de numeros aleatorios
    srand(time(0));

    // Llenar el arreglo con valores aleatorios
    printf("Elementos del arreglo:\n");
    for (int i = 0; i < sizeEjercicio2; i++) {
        arrEjercicio2[i] = rand() % 100 + 1; // Valores entre 1 y 100
        printf("%d ", arrEjercicio2[i]);
    }
    printf("\n");

    // Encontrar el elemento mayor
    int max = arrEjercicio2[0];
    for (int i = 1; i < sizeEjercicio2; i++) {
        if (arrEjercicio2[i] > max) {
            max = arrEjercicio2[i];
        }
    }

    // Mostrar el elemento mayor
    printf("El elemento mayor es: %d\n", max);

    // Liberar la memoria asignada
    delete[] arrEjercicio2;

    
    /*************#3************/
    printf("Ejercicio #3\n\n");


    int sizeEjercicio3;
    printf("Introduce el tamanno del arreglo: ");
    scanf_s("%d", &sizeEjercicio3);

    int* arrEjercicio3 = new int[sizeEjercicio3];

    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < sizeEjercicio3; i++) {
        scanf_s("%d", &arrEjercicio3[i]);
    }

    int newSizeEjercicio3;
    printf("Introduce el nuevo tamanno del arreglo: ");
    scanf_s("%d", &newSizeEjercicio3);

    int* newArrEjercicio3 = new int[newSizeEjercicio3];
    int minValue = (sizeEjercicio3 < newSizeEjercicio3 ? sizeEjercicio3 : newSizeEjercicio3);

    for (int i = 0; i < minValue; i++) {
        newArrEjercicio3[i] = arrEjercicio3[i];
    }

    for (int i = sizeEjercicio3; i < newSizeEjercicio3; i++) {
        newArrEjercicio3[i] = 0;
    }

    delete[] arrEjercicio3;

    arrEjercicio3 = newArrEjercicio3;
    sizeEjercicio3 = newSizeEjercicio3;

    printf("Nuevo arreglo:\n");
    for (int i = 0; i < sizeEjercicio3; i++) {
        printf("%d ", arrEjercicio3[i]);
    }
    printf("\n");

    delete[] arrEjercicio3;
    delete[] newArrEjercicio3;

    /*************#4************/
    printf("Ejercicio #4\n\n");

    int sizeEjercicio4;
    printf("Introduce el tamanno del arreglo: ");
    scanf_s("%d", &sizeEjercicio4);

    int* arrEjercicio4 = new int[sizeEjercicio4];

    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < sizeEjercicio4; i++) {
        scanf_s("%d", &arrEjercicio4[i]);
    }

    int pos;
    printf("Introduce la posicion del elemento que deseas eliminar (0-%d): ", sizeEjercicio4 - 1);
    scanf_s("%d", &pos);

    int* newArrEjercicio4 = new int[sizeEjercicio4 - 1];

    for (int i = 0, j = 0; i < sizeEjercicio4; i++) {
        if (i != pos) {
            newArrEjercicio4[j++] = arrEjercicio4[i];
        }
    }

    delete[] arrEjercicio4;

    arrEjercicio4 = newArrEjercicio4;
    sizeEjercicio4--;

    printf("arreglo despues de eliminar el elemento:\n");
    for (int i = 0; i < sizeEjercicio4; i++) {
        printf("%d ", arrEjercicio4[i]);
    }
    printf("\n");

    delete[] arrEjercicio4;


    return 0;
}

