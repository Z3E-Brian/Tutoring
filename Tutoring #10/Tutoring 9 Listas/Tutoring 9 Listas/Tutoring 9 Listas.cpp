#include <iostream>

using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;

    // Constructor
    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor
    Lista() : cabeza(nullptr) {}

    // Método para agregar un nodo al final
    void agregarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    // Método para mostrar los elementos de la lista
    void mostrar() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->valor << " -> ";
            temp = temp->siguiente;
        }
        cout << "nullptr" << endl;
    }

    // Método para eliminar el primer nodo con un valor específico
    void eliminar(int valor) {
        if (cabeza == nullptr) return;

        // Si el nodo a eliminar es la cabeza
        if (cabeza->valor == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        // Buscar el nodo a eliminar
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr && temp->siguiente->valor != valor) {
            temp = temp->siguiente;
        }

        // Si se encuentra el nodo, eliminarlo
        if (temp->siguiente != nullptr) {
            Nodo* nodoAEliminar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete nodoAEliminar;
        }
    }

    // Destructor para liberar memoria
    ~Lista() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            Nodo* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
    }

	//-------------------------------------PRACTICA-------------------------------------//

    /*   Ejercicio #1   */
    void agregarEnOrden(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr || cabeza->valor >= valor) {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            return;
        }

        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr && temp->siguiente->valor < valor) {
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }

	/*   Ejercicio #2   */
    int contarElementosIterativo() {
        int contador = 0;
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        return contador;
    }
    /*  Metodo recursivo  */
    int contarElementosRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarElementosRecursivo(nodo->siguiente);
    }
    
	/*   Ejercicio #3   */
    void intercambiarPorIndices(int indice1, int indice2) {
        if (indice1 == indice2) return;

        Nodo* nodo1 = cabeza;
        Nodo* nodo2 = cabeza;
        int contador = 0;

        while (nodo1 != nullptr && contador < indice1) {
            nodo1 = nodo1->siguiente;
            contador++;
        }

        contador = 0;
        while (nodo2 != nullptr && contador < indice2) {
            nodo2 = nodo2->siguiente;
            contador++;
        }

        if (nodo1 != nullptr && nodo2 != nullptr) {
            int temp = nodo1->valor;
            nodo1->valor = nodo2->valor;
            nodo2->valor = temp;
        }
    }

	/*   Ejercicio #4   */
    void eliminarPorParidad(bool eliminarPares) {
        Nodo* temp = cabeza;
        Nodo* previo = nullptr;

        while (temp != nullptr) {
            bool esPar = (temp->valor % 2 == 0);
            if ((eliminarPares && esPar) || (!eliminarPares && !esPar)) {
                if (previo == nullptr) {
                    cabeza = temp->siguiente;
                }
                else {
                    previo->siguiente = temp->siguiente;
                }
                Nodo* aEliminar = temp;
                temp = temp->siguiente;
                delete aEliminar;
            }
            else {
                previo = temp;
                temp = temp->siguiente;
            }
        }
    }

	/*   Ejercicio #5   */
    void moverAlFinal(int valor) {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

        Nodo* temp = cabeza;
        Nodo* previo = nullptr;
        Nodo* nodoEncontrado = nullptr;

        while (temp != nullptr) {
            if (temp->valor == valor) {
                nodoEncontrado = temp;
                break;
            }
            previo = temp;
            temp = temp->siguiente;
        }

        if (nodoEncontrado == nullptr || nodoEncontrado->siguiente == nullptr) return;

        if (previo != nullptr) {
            previo->siguiente = nodoEncontrado->siguiente;
        }
        else {
            cabeza = nodoEncontrado->siguiente;
        }

        Nodo* ultimo = nodoEncontrado;
        while (ultimo->siguiente != nullptr) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nodoEncontrado;
        nodoEncontrado->siguiente = nullptr;
    }

	/*   Ejercicio #6   */
    void rotarLista(int n) {
        if (cabeza == nullptr || cabeza->siguiente == nullptr || n == 0) return;

        Nodo* actual = cabeza;
        int longitud = 1;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
            longitud++;
        }

        n = n % longitud;
        if (n == 0) return;

        actual->siguiente = cabeza; // Hacemos la lista circular temporalmente

        int avanzar = longitud - n;
        Nodo* nuevoFinal = cabeza;
        for (int i = 1; i < avanzar; i++) {
            nuevoFinal = nuevoFinal->siguiente;
        }

        cabeza = nuevoFinal->siguiente;
        nuevoFinal->siguiente = nullptr;
    }

	/*   Ejercicio #7   */
    bool detectarCiclo() {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) return false;

        Nodo* lento = cabeza;
        Nodo* rapido = cabeza;

        while (rapido != nullptr && rapido->siguiente != nullptr) {
            lento = lento->siguiente;
            rapido = rapido->siguiente->siguiente;
            if (lento == rapido) return true;
        }

        return false;
    }
};

class NodoDoble {
public:
    int valor;
    NodoDoble* siguiente;
    NodoDoble* previo;

    NodoDoble(int val) : valor(val), siguiente(nullptr), previo(nullptr) {}
};

/*  Bonus  */
class ListaCircularDoble {
private:
    NodoDoble* cabeza;

public:
    ListaCircularDoble() : cabeza(nullptr) {}

    void agregarAlFinal(int valor) {
        NodoDoble* nuevo = new NodoDoble(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            cabeza->previo = cabeza;
        }
        else {
            NodoDoble* ultimo = cabeza->previo;
            ultimo->siguiente = nuevo;
            nuevo->previo = ultimo;
            nuevo->siguiente = cabeza;
            cabeza->previo = nuevo;
        }
    }

    void mostrarAdelante() {
        if (cabeza == nullptr) return;
        NodoDoble* temp = cabeza;
        do {
            std::cout << temp->valor << " -> ";
            temp = temp->siguiente;
        } while (temp != cabeza);
        std::cout << "(circular)" << std::endl;
    }

    void mostrarAtras() {
        if (cabeza == nullptr) return;
        NodoDoble* temp = cabeza->previo;
        do {
            std::cout << temp->valor << " -> ";
            temp = temp->previo;
        } while (temp != cabeza->previo);
        std::cout << "(circular)" << std::endl;
    }
};


int main() {
    Lista lista;

    // Agregar elementos a la lista
    lista.agregarAlFinal(5);
    lista.agregarAlFinal(10);
    lista.agregarAlFinal(15);
	lista.agregarAlFinal(20);
	lista.agregarAlFinal(25);
	lista.agregarAlFinal(30);
	lista.agregarAlFinal(35);
	lista.agregarAlFinal(40);
	lista.agregarAlFinal(45);
	lista.agregarAlFinal(50);

    // Mostrar la lista
    cout << "Lista actual: ";
    lista.mostrar();

    // Eliminar un elemento
    lista.eliminar(30);
    cout << "Lista despues de eliminar 30: ";
    lista.mostrar();

    return 0;
}
