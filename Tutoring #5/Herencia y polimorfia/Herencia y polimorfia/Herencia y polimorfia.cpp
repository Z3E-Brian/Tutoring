#include <iostream>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;
public:
    Vehiculo(string m, string mod, int a)
        : marca(m), modelo(mod), anio(a) {}

    void mostrarInfo() {
        cout << "Marca: " << marca
            << " | Modelo: " << modelo
            << " | Anio: " << anio;
    }

    // Metodo base (puede ser generico, pero aqui no lo usaremos)
    virtual void llenarGasolina() {
        cout << marca << " " << modelo << " esta llenando gasolina." << endl;
    }
};

// Clase derivada Auto
class Auto : public Vehiculo {
    int numPuertas;
    string tipoCombustible;
public:
    Auto(string m, string mod, int a, int puertas, string combustible)
        : Vehiculo(m, mod, a), numPuertas(puertas), tipoCombustible(combustible) {}

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << " | Puertas: " << numPuertas
            << " | Combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada Moto
class Moto : public Vehiculo {
    int cilindrada;
    string tipoMoto;  // ejemplo: deportiva, scooter, cruiser
public:
    Moto(string m, string mod, int a, int cc, string tipo)
        : Vehiculo(m, mod, a), cilindrada(cc), tipoMoto(tipo) {}

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << " | Cilindrada: " << cilindrada << "cc"
            << " | Tipo de moto: " << tipoMoto << endl;
    }

    void llenarGasolina() {
        cout << marca << " " << modelo << " esta llenando gasolina SUPER." << endl;
    }
};

// Clase derivada Camion
class Camion : public Vehiculo {
    double capacidadToneladas;
    int numEjes;
public:
    Camion(string m, string mod, int a, double cap, int ejes)
        : Vehiculo(m, mod, a), capacidadToneladas(cap), numEjes(ejes) {}

    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << " | Capacidad: " << capacidadToneladas << " toneladas"
            << " | Ejes: " << numEjes << endl;
    }

    void llenarGasolina() {
        cout << marca << " " << modelo << " esta llenando DIESEL." << endl;
    }
};

int main() {
    Auto a("Porsche", "GT3RS", 2020, 2, "Gasolina");
    Moto m("Honda", "CBR600", 2021, 600, "Deportiva");
    Camion c("Volvo", "FH16", 2019, 18.0, 4);

    // Arreglo de punteros a Vehiculo
    Vehiculo* flota[3];
    flota[0] = &a;
    flota[1] = &m;
    flota[2] = &c;

    cout << "=== Informacion de la flota ===\n\n";
    for (int i = 0; i < 3; i++) {
        flota[i]->llenarGasolina();  // metodo especifico segun el tipo
        flota[i]->mostrarInfo();
        cout << endl;
    }

    return 0;
}
