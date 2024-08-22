#include <cstdio>
#include <cstdlib>

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int** crearMatriz(int filas, int columnas) {
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}

void leerMatriz(int** matriz, int filas, int columnas) {
    printf("Introduce los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf_s("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int** agregarColumna(int** matriz, int filas, int columnas, int* nuevaColumna) {
    int** nuevaMatriz = crearMatriz(filas, columnas + 1);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            nuevaMatriz[i][j] = matriz[i][j];
        }
        nuevaMatriz[i][columnas] = nuevaColumna[i];
    }

    liberarMatriz(matriz, filas);

    return nuevaMatriz;
}

int main() {
    int filas, columnas;

    printf("Introduce el numero de filas y columnas de la matriz:\n");
    scanf_s("%d %d", &filas, &columnas);

    int** matriz = crearMatriz(filas, columnas);
    leerMatriz(matriz, filas, columnas);

    int* nuevaColumna = new int[filas];
    printf("Introduce los elementos para la nueva columna:\n");
    for (int i = 0; i < filas; i++) {
        scanf_s("%d", &nuevaColumna[i]);
    }

    matriz = agregarColumna(matriz, filas, columnas, nuevaColumna);

    printf("Matriz con la nueva columna:\n");
    imprimirMatriz(matriz, filas, columnas + 1);

    delete[] nuevaColumna;
    liberarMatriz(matriz, filas);

    return 0;
}
