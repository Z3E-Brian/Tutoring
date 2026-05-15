#pragma once
#include <iostream>
using namespace std;
#include<time.h>

const int n = 20, m = 20;

void Generar(int M[n][m]);
//Generacion de numeros enteros aleatorios menores a n*10.

void Mostrar_Matriz(int M[n][m]);

int Cuenta(int M[n][m]);
//Complejidad del algoritmo: n-> \Theta(n*m