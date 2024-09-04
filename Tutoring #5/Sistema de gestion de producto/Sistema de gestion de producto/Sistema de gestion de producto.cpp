#include <iostream>
#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;

public:
    void establecerDatos(string nom, int cod, float pre) {
        nombre = nom;
        codigo = cod;
        precio = pre;
    }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Código: " << codigo << endl;
        cout << "Precio: " << precio << endl;
    }

    void actualizarPrecio(float nuevoPrecio) {
        precio = nuevoPrecio;
    }

    float obtenerPrecio() const {
        return precio;
    }

    int obtenerCodigo() const {
        return codigo;
    }
};

class Inventario {
private:
    Producto* productos;
    int cantidad;

public:
    Inventario(int tamano) {
        cantidad = tamano;
        productos = new Producto[cantidad];
    }

    ~Inventario() {
        delete[] productos;
    }

    void agregarProducto(int indice, string nom, int cod, float pre) {
        productos[indice].establecerDatos(nom, cod, pre);
    }

    void mostrarInventario() const {
        for (int i = 0; i < cantidad; i++) {
            cout << "Producto " << i + 1 << ":" << endl;
            productos[i].mostrarDatos();
            cout << endl;
        }
    }

    void actualizarPrecioPorCodigo(int cod, float nuevoPrecio) {
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].obtenerCodigo() == cod) {
                productos[i].actualizarPrecio(nuevoPrecio);
                cout << "Precio actualizado para el producto con código " << cod << endl;
                return;
            }
        }
        cout << "Producto con código " << cod << " no encontrado." << endl;
    }

    void encontrarProductoMasCaro() const {
        if (cantidad == 0) {
            cout << "El inventario está vacío." << endl;
            return;
        }

        Producto* masCaro = &productos[0];
        for (int i = 1; i < cantidad; i++) {
            if (productos[i].obtenerPrecio() > masCaro->obtenerPrecio()) {
                masCaro = &productos[i];
            }
        }
        cout << "El producto más caro es:" << endl;
        masCaro->mostrarDatos();
    }
};

int main() {
    int cantidadProductos;

    cout << "Ingrese la cantidad de productos: ";
    cin >> cantidadProductos;

    Inventario inventario(cantidadProductos);

    for (int i = 0; i < cantidadProductos; i++) {
        string nombre;
        int codigo;
        float precio;

        cout << "Ingrese los datos del producto " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Código: ";
        cin >> codigo;
        cout << "Precio: ";
        cin >> precio;

        inventario.agregarProducto(i, nombre, codigo, precio);
    }

    inventario.mostrarInventario();

    int codigoActualizar;
    float nuevoPrecio;
    cout << "Ingrese el código del producto para actualizar el precio: ";
    cin >> codigoActualizar;
    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;
    inventario.actualizarPrecioPorCodigo(codigoActualizar, nuevoPrecio);

    inventario.mostrarInventario();
    inventario.encontrarProductoMasCaro();

    return 0;
}