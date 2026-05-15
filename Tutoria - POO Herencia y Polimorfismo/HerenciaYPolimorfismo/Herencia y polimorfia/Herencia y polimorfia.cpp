#include <iostream>
using namespace std;

class METODODETRANSPORTE {
protected:
    string marca;
    string modelo;
    int anio;
public:
    METODODETRANSPORTE(string m, string mod, int a){
		marca = m;
		modelo = mod;
		anio = a;
    }

	METODODETRANSPORTE() {
		marca = "MarcaX";
		modelo = "ModeloY";
		anio = 2000;
    }

    void mostrarInfo() {
        cout << "Marca: " << marca
            << " | Modelo: " << modelo
            << " | Anio: " << anio;
    }

    virtual void llenarGasolina() {
        cout << marca << " " << modelo << " esta llenando gasolina." << endl;
    }
};

// Clase derivada Auto
class Auto : public METODODETRANSPORTE {
private:
    int numPuertas;
    string tipoCombustible;
public:
    Auto(string m, string mod, int a, int puertas, string combustible) : METODODETRANSPORTE(m,mod,a) {
		numPuertas = puertas;
		tipoCombustible = combustible;
    }

    void mostrarInfo() {
        cout << "Puertas: " << numPuertas
            << " | Combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada Moto
class Moto : public METODODETRANSPORTE {
private:
    int cilindrada;
    string tipoMoto;  // ejemplo: deportiva, scooter, cruiser
public:
    Moto(string m, string mod, int a, int cc, string tipo)
        : METODODETRANSPORTE(m, mod, a), cilindrada(cc), tipoMoto(tipo) {}

    void mostrarInfo() {
        cout << " | Cilindrada: " << cilindrada << "cc"
            << " | Tipo de moto: " << tipoMoto << endl;
    }

    void llenarGasolina() override {
        cout << marca << " " << modelo << " esta llenando gasolina SUPER." << endl;
    }
};

// Clase derivada Camion
class Camion : public METODODETRANSPORTE {
private:
    double capacidadToneladas;
    int numEjes;
public:
    Camion(string m, string mod, int a, double cap, int ejes)
        : METODODETRANSPORTE(m, mod, a), capacidadToneladas(cap), numEjes(ejes) {}

    void mostrarInfo() {
        METODODETRANSPORTE::mostrarInfo();
        cout << " | Capacidad: " << capacidadToneladas << " toneladas"
            << " | Ejes: " << numEjes << endl;
    }

    void llenarGasolina() override {
        cout << marca << " " << modelo << " esta llenando DIESEL." << endl;
    }
};

int main() {
    Auto a("Porsche", "GT3RS", 2020, 2, "Gasolina");
    Moto m("Honda", "CBR600", 2021, 600, "Deportiva");
    Camion c("Volvo", "FH16", 2019, 18.0, 4);

    // Arreglo de punteros a Vehiculo
    METODODETRANSPORTE* flota[3];
    flota[0] = &a;
    flota[1] = &m;
    flota[2] = &c;

    cout << "=== Informacion de la flota ===\n\n";
    for (int i = 0; i < 3; i++) {
        flota[i]->llenarGasolina();  // metodo especifico segun el tipo
        flota[i]->mostrarInfo();
        cout << endl << endl;
    }

    return 0;
}
