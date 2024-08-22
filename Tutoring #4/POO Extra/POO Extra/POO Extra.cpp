#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;

public:
    // Metodos para establecer y mostrar los datos del producto
    void establecerDatos(string nombre, int codigo, float precio) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->precio = precio;
    }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Codigo: " << codigo << ", Precio: $" << precio << endl;
    }

    // Metodo para actualizar el precio
    void actualizarPrecio(float nuevoPrecio) {
        precio = nuevoPrecio;
    }

    // Metodos para obtener el precio y el codigo del producto
    float obtenerPrecio() const {
        return precio;
    }

    int obtenerCodigo() const {
        return codigo;
    }
};

// Funcion para agregar un producto al inventario
void agregarProducto(Producto*& inventario, int& cantidadProductos, string nombre, int codigo, float precio) {
    Producto* nuevoInventario = new Producto[cantidadProductos + 1];
    for (int i = 0; i < cantidadProductos; i++) {
        nuevoInventario[i] = inventario[i];
    }
    nuevoInventario[cantidadProductos].establecerDatos(nombre, codigo, precio);
    cantidadProductos++;
    delete[] inventario;
    inventario = nuevoInventario;
}

// Funcion para mostrar la informacion de todos los productos en el inventario
void mostrarInventario(const Producto* inventario, int cantidadProductos) {
    for (int i = 0; i < cantidadProductos; i++) {
        inventario[i].mostrarDatos();
    }
}

// Funcion para actualizar el precio de un producto dado su codigo
void actualizarPrecioPorCodigo(Producto* inventario, int cantidadProductos, int codigo, float nuevoPrecio) {
    for (int i = 0; i < cantidadProductos; i++) {
        if (inventario[i].obtenerCodigo() == codigo) {
            inventario[i].actualizarPrecio(nuevoPrecio);
            cout << "El precio del producto con codigo " << codigo << " ha sido actualizado a $" << nuevoPrecio << endl;
            return;
        }
    }
    cout << "Producto con codigo " << codigo << " no encontrado." << endl;
}

// Funcion para encontrar y mostrar el producto mas caro del inventario
void encontrarProductoMasCaro(const Producto* inventario, int cantidadProductos) {
    if (cantidadProductos == 0) {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    const Producto* productoMasCaro = &inventario[0];
    for (int i = 1; i < cantidadProductos; i++) {
        if (inventario[i].obtenerPrecio() > productoMasCaro->obtenerPrecio()) {
            productoMasCaro = &inventario[i];
        }
    }

    cout << "El producto mas caro es:" << endl;
    productoMasCaro->mostrarDatos();
}

int main() {
    Producto* inventario = nullptr;
    int cantidadProductos = 0;
    int cantidad;

    cout << "Ingrese la cantidad de productos que desea agregar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        string nombre;
        int codigo;
        float precio;

        cout << "\nIngrese los datos del producto " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Codigo: ";
        cin >> codigo;
        cout << "Precio: ";
        cin >> precio;

        agregarProducto(inventario, cantidadProductos, nombre, codigo, precio);
    }

    cout << "\nInventario de productos:" << endl;
    mostrarInventario(inventario, cantidadProductos);

    int codigo;
    float nuevoPrecio;
    cout << "\nIngrese el codigo del producto cuyo precio desea actualizar: ";
    cin >> codigo;
    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;

    actualizarPrecioPorCodigo(inventario, cantidadProductos, codigo, nuevoPrecio);

    cout << "\nInventario actualizado:" << endl;
    mostrarInventario(inventario, cantidadProductos);

    cout << "\nBuscando el producto mas caro..." << endl;
    encontrarProductoMasCaro(inventario, cantidadProductos);

    delete[] inventario;
    return 0;
}
