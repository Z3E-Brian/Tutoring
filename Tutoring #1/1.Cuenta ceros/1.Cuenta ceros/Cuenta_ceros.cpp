#include "Cuenta_ceros.h"

void Generar(int M[n][m])
//Generacion de numeros enteros aleatorios menores a n*10.
{
	
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			M[i][j] = rand() % (n * 10);
	return;
}

void Mostrar_Matriz(int M[n][m])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{

			cout.width(4);
			
cout << M[i][j];
		}
		cout << '\n';
	}
	return;
	}

int Cuenta(int M[n][m])
//Complejidad del algoritmo: n-> \Theta(n).
{
	int i, s = 0; //A[0][0] es el mayor al momento inicial
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == 0)
				s++;
		}
	}
	return s;
}

