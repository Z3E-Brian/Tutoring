#include <iostream>
using namespace std;

// Clase Nodo
class Nodo {
public:
	int dato;           // Información o valor del nodo
	Nodo* siguiente;    // Puntero al siguiente nodo

	Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Clase Lista
class Lista {
private:
	Nodo* head;   // Puntero al primer nodo

public:
	Lista() : head(nullptr) {}

	void agregarAlFinal(int valor) {
		Nodo* nuevoNodo = new Nodo(valor);

		if (head == nullptr) {
			head = nuevoNodo;
		}
		else {
			Nodo* actual = head;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevoNodo;
		}
	}

	void agregarAlInicio(int valor) {
		Nodo* nuevoNodo = new Nodo(valor);
		if (head == nullptr) {
			head = nuevoNodo;
		}
		else {
			nuevoNodo->siguiente = head;
			head = nuevoNodo;
		}
	}

	//insertar ordenado
	void insertarOrdenado(int valor) {
		Nodo* nuevoNodo = new Nodo(valor);
		if (head == nullptr || head->dato >= valor) {
			nuevoNodo->siguiente = head;
			head = nuevoNodo;
		}
		else {
			Nodo* actual = head;
			while (actual->siguiente != nullptr && actual->siguiente->dato < valor) {
				actual = actual->siguiente;
			}
			nuevoNodo->siguiente = actual->siguiente;
			actual->siguiente = nuevoNodo;
		}

	}

	// Método para mostrar la lista
	void mostrar() {
		Nodo* actual = head;
		while (actual != nullptr) {
			cout << actual->dato << " -> ";
			actual = actual->siguiente;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	Lista lista;

	// Agregar algunos elementos a la lista
	lista.agregarAlFinal(10);
	lista.agregarAlFinal(20);
	lista.agregarAlFinal(30);

	// Mostrar la lista
	cout << "Lista enlazada: ";
	lista.mostrar();

	return 0;
}

/*
// Clase Nodo
class Nodo {
public:
	int dato;           // Información o valor del nodo
	Nodo* siguiente;    // Puntero al siguiente nodo

	// Constructor
	Nodo(int valor) : dato(valor), siguiente(nullptr) {}

	// Método para insertar un nodo al final
	void insertarAlFinal(int valor) {
		Nodo* nuevoNodo = new Nodo(valor);
		Nodo* actual = this;  // Empezamos desde el nodo actual (this)

		// Recorremos hasta el último nodo
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}

		// Al final de la lista, enlazamos el nuevo nodo
		actual->siguiente = nuevoNodo;
	}

	// Método para mostrar la lista a partir de este nodo
	void mostrar() {
		Nodo* actual = this;  // Empezamos desde el nodo actual
		while (actual != nullptr) {
			cout << actual->dato << " -> ";
			actual = actual->siguiente;
		}
		cout << "NULL" << endl;
	}

	// Método para eliminar el último nodo
	void eliminarUltimo() {
		Nodo* actual = this;
		Nodo* anterior = nullptr;

		// Si solo hay un nodo, no eliminamos nada
		if (actual->siguiente == nullptr) {
			cout << "Solo hay un nodo en la lista, no se puede eliminar" << endl;
			return;
		}

		// Recorremos la lista hasta el último nodo
		while (actual->siguiente != nullptr) {
			anterior = actual;
			actual = actual->siguiente;
		}

		// Eliminamos el último nodo
		anterior->siguiente = nullptr;
		delete actual;
	}
};

int main() {
	// Crear el primer nodo de la lista
	Nodo* lista = new Nodo(10);  // Primer nodo con valor 10

	// Insertar algunos elementos
	lista->insertarAlFinal(20);
	lista->insertarAlFinal(30);
	lista->insertarAlFinal(40);

	// Mostrar la lista
	cout << "Lista enlazada: ";
	lista->mostrar();

	// Eliminar el último nodo
	lista->eliminarUltimo();
	cout << "Después de eliminar el último nodo: ";
	lista->mostrar();

	return 0;
}
*/