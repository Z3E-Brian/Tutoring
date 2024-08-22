//Sede Brunca, UNA.
//Programacion I. 
//Ejemplo: 3.1.1
//Calcular el maximo valor en un vector de enteros

#include "Cuenta_ceros.h"

int main(){

	srand(time(NULL));
	
	int M[n][m], donde, i, j;
	
	Generar(M);
	Mostrar_Matriz(M);
	cout << "Numero de ceros: " << Cuenta(M);
	return 0;
}