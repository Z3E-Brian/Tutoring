#include <iostream>
using namespace std;

// Definicion de la clase Nodo
class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int valor) : valor(valor), siguiente(nullptr) {}
};

// Definicion de la clase Lista
class Lista {
private:
    Nodo* primero;

public:
    // Constructor
    Lista() : primero(nullptr) {}

    // Destructor
    ~Lista() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    // Agregar un nodo al final
    void agregarNodo(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (primero == nullptr) {
            primero = nuevo;
            return;
        }
        Nodo* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

	//agregar nodo en orden
	void agregarNodoEnOrden(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (primero == nullptr || primero->valor >= valor) {
			nuevo->siguiente = primero;
			primero = nuevo;
			return;
		}
		Nodo* actual = primero;
		while (actual->siguiente != nullptr && actual->siguiente->valor < valor) {
			actual = actual->siguiente;
		}
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
	}

    // Mostrar los elementos de la lista
    void mostrar() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        cout << "nullptr\n";
    }

    // Eliminar el ultimo nodo
    void eliminarUltimo() {
        if (primero == nullptr) return;
        if (primero->siguiente == nullptr) {
            delete primero;
            primero = nullptr;
        }
        else {
            Nodo* actual = primero;
            while (actual->siguiente->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            delete actual->siguiente;
            actual->siguiente = nullptr;
        }
    }

    // Insertar al inicio
    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = primero;
        primero = nuevo;
    }

    // Insertar un nodo en una posicion deseada
    void insertarEnPosicion(int valor, int posicion) {
        Nodo* nuevo = new Nodo(valor);
        if (posicion == 0) {
            insertarAlInicio(valor);
        }
        else {
            Nodo* actual = primero;
            for (int i = 0; i < posicion - 1 && actual != nullptr; i++) {
                actual = actual->siguiente;
            }
            if (actual != nullptr) {
                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
            }
        }
    }

    // Buscar un nodo por indice
    Nodo* buscarPorIndice(int indice) {
        Nodo* actual = primero;
        int i = 0;
        while (actual != nullptr && i < indice) {
            actual = actual->siguiente;
            i++;
        }
        return actual; // Devuelve nullptr si no existe
    }

    // Buscar un nodo por valor
    Nodo* buscarPorDato(int valor) {
        Nodo* actual = primero;
        while (actual != nullptr) {
            if (actual->valor == valor) return actual;
            actual = actual->siguiente;
        }
        return nullptr;
    }

    // Eliminar por indice
    void eliminarPorIndice(int indice) {
        if (indice == 0 && primero != nullptr) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
        else {
            Nodo* actual = primero;
            for (int i = 0; i < indice - 1 && actual != nullptr; i++) {
                actual = actual->siguiente;
            }
            if (actual != nullptr && actual->siguiente != nullptr) {
                Nodo* temp = actual->siguiente;
                actual->siguiente = temp->siguiente;
                delete temp;
            }
        }
    }

    // Eliminar por valor
    void eliminarPorDato(int valor) {
        if (primero == nullptr) return;
        if (primero->valor == valor) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
        else {
            Nodo* actual = primero;
            while (actual->siguiente != nullptr && actual->siguiente->valor != valor) {
                actual = actual->siguiente;
            }
            if (actual->siguiente != nullptr) {
                Nodo* temp = actual->siguiente;
                actual->siguiente = temp->siguiente;
                delete temp;
            }
        }
    }

    // Invertir la lista
    void invertir() {
        Nodo* anterior = nullptr;
        Nodo* actual = primero;
        Nodo* siguiente = nullptr;
        while (actual != nullptr) {
            siguiente = actual->siguiente;
            actual->siguiente = anterior;
            anterior = actual;
            actual = siguiente;
        }
        primero = anterior;
    }

    // Eliminar nodos duplicados
    void eliminarDuplicados() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            Nodo* iterador = actual;
            while (iterador->siguiente != nullptr) {
                if (iterador->siguiente->valor == actual->valor) {
                    Nodo* temp = iterador->siguiente;
                    iterador->siguiente = temp->siguiente;
                    delete temp;
                }
                else {
                    iterador = iterador->siguiente;
                }
            }
            actual = actual->siguiente;
        }
    }

    // Insertar otra lista al final
    void insertarOtraLista(Lista& otra) {
        if (primero == nullptr) {
            primero = otra.primero;
        }
        else {
            Nodo* actual = primero;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = otra.primero;
        }
    }

    // Intercalar dos listas
    void intercalarLista(Lista& otra) {
        Nodo* actual1 = primero;
        Nodo* actual2 = otra.primero;
        while (actual1 != nullptr && actual2 != nullptr) {
            Nodo* temp1 = actual1->siguiente;
            Nodo* temp2 = actual2->siguiente;
            actual1->siguiente = actual2;
            if (temp1 == nullptr) break;
            actual2->siguiente = temp1;
            actual1 = temp1;
            actual2 = temp2;
        }
    }

    // Dividir la lista en dos
    Lista dividirEnDos() {
        if (primero == nullptr) return Lista();

        Nodo* lento = primero;
        Nodo* rapido = primero->siguiente;

        while (rapido != nullptr && rapido->siguiente != nullptr) {
            lento = lento->siguiente;
            rapido = rapido->siguiente->siguiente;
        }

        Lista segundaLista;
        segundaLista.primero = lento->siguiente;
        lento->siguiente = nullptr;

        return segundaLista;
    }

	//****************************************** RECURSIVOS ******************************************//

    // Agregar nodo de forma recursiva
    void agregarNodoRecursivo(int valor) {
        primero = agregarRecursivo(primero, valor);
    }

    Nodo* agregarRecursivo(Nodo* actual, int valor) {
        if (actual == nullptr) {
            return new Nodo(valor);
        }
        actual->siguiente = agregarRecursivo(actual->siguiente, valor);
        return actual;
    }

    // Mostrar elementos de forma recursiva
    void mostrarRecursivo() {
        mostrarRecursivo(primero);
        std::cout << "nullptr\n";
    }

    void mostrarRecursivo(Nodo* actual) {
        if (actual != nullptr) {
            std::cout << actual->valor << " -> ";
            mostrarRecursivo(actual->siguiente);
        }
    }

    // Eliminar el último nodo de forma recursiva
    void eliminarUltimoRecursivo() {
        primero = eliminarUltimoRecursivo(primero);
    }

    Nodo* eliminarUltimoRecursivo(Nodo* actual) {
        if (actual == nullptr) {
            return nullptr;
        }
        if (actual->siguiente == nullptr) {
            delete actual;
            return nullptr;
        }
        actual->siguiente = eliminarUltimoRecursivo(actual->siguiente);
        return actual;
    }

    // Invertir la lista de forma recursiva
    void invertirRecursivo() {
        primero = invertirRecursivo(primero, nullptr);
    }

    Nodo* invertirRecursivo(Nodo* actual, Nodo* anterior) {
        if (actual == nullptr) {
            return anterior;
        }
        Nodo* siguiente = actual->siguiente;
        actual->siguiente = anterior;
        return invertirRecursivo(siguiente, actual);
    }




};

// Ejemplo de uso
int main() {
    Lista lista, lista2;

    lista.agregarNodo(1);
    lista.agregarNodo(2);
    lista.agregarNodo(3);
    lista.mostrar();  // Salida: 1 -> 2 -> 3 -> nullptr

    lista.insertarAlInicio(0);
    lista.mostrar();  // Salida: 0 -> 1 -> 2 -> 3 -> nullptr

    lista.invertir();
    lista.mostrar();  // Salida: 3 -> 2 -> 1 -> 0 -> nullptr

    lista.eliminarUltimo();
    lista.mostrar();  // Salida: 3 -> 2 -> 1 -> nullptr

	cout << "\n\nMetodos Recursivos\n\n";

    // Agregar nodos de manera recursiva
    lista2.agregarNodoRecursivo(1);
    lista2.agregarNodoRecursivo(2);
    lista2.agregarNodoRecursivo(3);
    lista2.mostrarRecursivo();  // Salida: 1 -> 2 -> 3 -> nullptr

    // Invertir la lista de forma recursiva
    lista2.invertirRecursivo();
    lista2.mostrarRecursivo();  // Salida: 3 -> 2 -> 1 -> nullptr

    // Eliminar el último nodo de forma recursiva
    lista2.eliminarUltimoRecursivo();
    lista2.mostrarRecursivo();  // Salida: 3 -> 2 -> nullptr


    return 0;
}
