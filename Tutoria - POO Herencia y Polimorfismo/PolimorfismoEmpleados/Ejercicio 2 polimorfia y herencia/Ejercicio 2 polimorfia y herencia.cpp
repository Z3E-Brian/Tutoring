#include <iostream>
#include <iomanip>
using namespace std;

// Clase base abstracta
class Empleado {
protected:
    string id;
    string nombre;
public:
    Empleado(string id, string nombre) : id(id), nombre(nombre) {}
    virtual ~Empleado() {}

    virtual double calcularPagoSemanal() const = 0;  // contrato
    virtual void mostrarInfo() const {
        cout << "Empleado: " << nombre << " (ID: " << id << ")";
    }
};

// Empleado Asalariado
class Asalariado : public Empleado {
    double salarioMensual;
public:
    Asalariado(string id, string nombre, double salario)
        : Empleado(id, nombre), salarioMensual(salario) {}

    double calcularPagoSemanal() const override {
        return salarioMensual / 4.0;
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << " | Tipo: Asalariado"
            << " | Pago semanal: $" << fixed << setprecision(2) << calcularPagoSemanal() << endl;
    }
};

// Empleado Por Hora
class PorHora : public Empleado {
    double tarifaHora;
    int horasTrabajadas;
public:
    PorHora(string id, string nombre, double tarifa, int horas)
        : Empleado(id, nombre), tarifaHora(tarifa), horasTrabajadas(horas) {}

    double calcularPagoSemanal() const override {
        int horasNormales = min(horasTrabajadas, 40);
        int horasExtra = max(0, horasTrabajadas - 40);
        return (horasNormales * tarifaHora) + (horasExtra * tarifaHora * 1.5);
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << " | Tipo: Por Hora"
            << " | Horas: " << horasTrabajadas
            << " | Pago semanal: $" << fixed << setprecision(2) << calcularPagoSemanal() << endl;
    }
};

// Empleado Comisionista
class Comisionista : public Empleado {
    double salarioBase;
    double ventasSemana;
    double porcentajeComision; // ej. 0.10 = 10%
public:
    Comisionista(string id, string nombre, double base, double ventas, double comision)
        : Empleado(id, nombre), salarioBase(base), ventasSemana(ventas), porcentajeComision(comision) {}

    double calcularPagoSemanal() const override {
        return salarioBase + (ventasSemana * porcentajeComision);
    }

    void mostrarInfo() const override {
        Empleado::mostrarInfo();
        cout << " | Tipo: Comisionista"
            << " | Ventas: $" << ventasSemana
            << " | Pago semanal: $" << fixed << setprecision(2) << calcularPagoSemanal() << endl;
    }
};

int main() {
    // Arreglo de punteros a Empleado
    Empleado* empleados[3];

    empleados[0] = new Asalariado("E001", "Ana", 1200.0);
    empleados[1] = new PorHora("E002", "Luis", 10.0, 45); // 5 horas extra
    empleados[2] = new Comisionista("E003", "Carlos", 300.0, 2000.0, 0.1); // 10% comisión

    cout << "=== Reporte de Nómina ===\n";
    for (int i = 0; i < 3; i++) {
        empleados[i]->mostrarInfo();
    }

    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete empleados[i];
    }

    return 0;
}
