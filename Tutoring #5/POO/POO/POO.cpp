//##############################################################################################################//
//##############################################################################################################//
//################################################Ejercicio 1###################################################//
//##############################################################################################################//
//##############################################################################################################//

#include <iostream>
#include <string>

using namespace std;

class Estudiante {
private:
    string nombre;
    int id;
    float notaPromedio;
	if (notaPromedio < 0 || notaPromedio > 100) {
		throw invalid_argument("La nota promedio debe estar entre 0 y 100.");
	}
public:
    Estudiante(string nname, int nId, float nNotaPromedio) : nombre(nname), id(nId), notaPromedio(nNotaPromedio) {
        nombre = nname;
        id = nId;
        notaPromedio = nNotaPromedio;
    }

    Estudiante() {
        nombre = "";
        id = 0;
        notaPromedio = 0;
    }

    ~Estudiante() {
		cout << "Destructor llamado para " << nombre << endl;
        delete this;
	}

    void establecerDatos(string nom, int identificacion, float nota) {
        nombre = nom;
        id = identificacion;
        notaPromedio = nota;
    }

    void mostrarDatos() {
        printf("Nombre: %s, ID: %d, Nota Promedio: %.2f\n", nombre.c_str(), id, notaPromedio);
    }

    float obtenerNotaPromedio() {
        return notaPromedio;
    }
};

//encontrar en el arreglo estatico
void encontrarMejorEstudiante(Estudiante estudiantes[], int numEstudiantes) {
    int indiceMejor = 0;
    for (int i = 1; i < numEstudiantes; i++) {
        if (estudiantes[i].obtenerNotaPromedio() > estudiantes[indiceMejor].obtenerNotaPromedio()) {
            indiceMejor = i;
        }
    }
    printf("\nEstudiante con la mejor nota promedio:\n");
    estudiantes[indiceMejor].mostrarDatos();
}
/*
//encontrar en el arreglo dimanico
void encontrarMejorEstudiante(Estudiante* estudiantes, int numEstudiantes) {
    int indiceMejor = 0;
    for (int i = 1; i < numEstudiantes; i++) {
        if (estudiantes[i].obtenerNotaPromedio() > estudiantes[indiceMejor].obtenerNotaPromedio()) {
            indiceMejor = i;
        }
    }
    printf("\nEstudiante con la mejor nota promedio:\n");
    estudiantes[indiceMejor].mostrarDatos();
}*/

//Arreglo estatico
int main() {

    const int numEstudiantes = 3;
    Estudiante estudiantes[numEstudiantes];

    estudiantes[0].establecerDatos("Juan Perez", 1001, 88.5);
    estudiantes[1].establecerDatos("Maria Gomez", 1002, 92.0);
    estudiantes[2].establecerDatos("Carlos Lopez", 1003, 85.7);

    printf("Informacion de todos los estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        estudiantes[i].mostrarDatos();
    }

    encontrarMejorEstudiante(estudiantes, numEstudiantes);

    return 0;
}

//Arreglo dinamico
//int main() {
//    int numEstudiantes;
//    printf("Ingrese la cantidad de estudiantes: ");
//    scanf("%d", &numEstudiantes);
//
//    Estudiante* estudiantes = new Estudiante[numEstudiantes];
//
//    for (int i = 0; i < numEstudiantes; i++) {
//        char nombre[50];
//        int id;
//        float notaPromedio;
//
//        printf("\nEstudiante %d:\n", i + 1);
//        printf("Ingrese el nombre: ");
//        scanf("%s", nombre);
//        printf("Ingrese el ID: ");
//        scanf("%d", &id);
//        printf("Ingrese la nota promedio: ");
//        scanf("%f", &notaPromedio);
//
//        estudiantes[i].establecerDatos(string(nombre), id, notaPromedio);
//    }
//
//    printf("\nInformación de todos los estudiantes:\n");
//    for (int i = 0; i < numEstudiantes; i++) {
//        estudiantes[i].mostrarDatos();
//    }
//
//    encontrarMejorEstudiante(estudiantes, numEstudiantes);
//
//    delete[] estudiantes;
//
//    return 0;
//}



//##############################################################################################################//
//##############################################################################################################//
//################################################Ejercicio 2###################################################//
//##############################################################################################################//
//##############################################################################################################//

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Producto {
//private:
//    string nombre;
//    float precio;
//    int cantidad;
//public:
//    Producto(string nom, float pre, int cant) : nombre(nom), precio(pre), cantidad(cant) {}
//
//    void mostrarDetalles() {
//        printf("Nombre: %s, Precio: %.2f, Cantidad: %d\n", nombre.c_str(), precio, cantidad);
//    }
//};
//
//void agregarProducto(Producto** inventario, int& numProductos, string nombre, float precio, int cantidad) {
//    Producto* nuevoProducto = new Producto(nombre, precio, cantidad);
//    inventario[numProductos] = nuevoProducto;
//    numProductos++;
//}
//
//void mostrarInventario(Producto** inventario, int numProductos) {
//    for (int i = 0; i < numProductos; i++) {
//        inventario[i]->mostrarDetalles();
//    }
//}
//
//int main() {
//    int capacidad = 5;
//    int numProductos = 0;
//
//    // Crear un arreglo dinamico de punteros a Producto
//    Producto** inventario = new Producto * [capacidad];
//
//    // Agregar productos al inventario
//    agregarProducto(inventario, numProductos, "Laptop", 899.99, 10);
//    agregarProducto(inventario, numProductos, "Mouse", 19.99, 50);
//    agregarProducto(inventario, numProductos, "Teclado", 49.99, 30);
//
//    // Mostrar el inventario
//    mostrarInventario(inventario, numProductos);
//
//    // Liberar la memoria
//    for (int i = 0; i < numProductos; i++) {
//        delete inventario[i];
//    }
//    delete[] inventario;
//
//    return 0;
//}


//##############################################################################################################//
//##############################################################################################################//
//################################################Ejercicio 3###################################################//
//##############################################################################################################//
//##############################################################################################################//

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Empleado; // Declaracion adelantada para usar en la clase Tarea
//
//class Tarea {
//private:
//    string descripcion;
//    int duracion;
//    vector<Empleado*> empleadosAsignados;
//public:
//    Tarea(string desc, int dur) : descripcion(desc), duracion(dur) {}
//
//    void asignarEmpleado(Empleado* empleado);
//
//    void mostrarEmpleados();
//
//    string getDescripcion() { return descripcion; }
//};
//
//class Empleado {
//private:
//    string nombre;
//    int id;
//    vector<Tarea*> tareasAsignadas;
//public:
//    Empleado(string nom, int ident) : nombre(nom), id(ident) {}
//
//    void asignarTarea(Tarea* tarea) {
//        tareasAsignadas.push_back(tarea);
//    }
//
//    void mostrarTareas() {
//        printf("Tareas asignadas a %s:\n", nombre.c_str());
//        for (Tarea* tarea : tareasAsignadas) {
//            printf("%s\n", tarea->getDescripcion().c_str());
//        }
//    }
//
//    string getNombre() { return nombre; }
//};
//
//void Tarea::asignarEmpleado(Empleado* empleado) {
//    empleadosAsignados.push_back(empleado);
//    empleado->asignarTarea(this);
//}
//
//void Tarea::mostrarEmpleados() {
//    printf("Empleados asignados a la tarea %s:\n", descripcion.c_str());
//    for (Empleado* empleado : empleadosAsignados) {
//        printf("%s\n", empleado->getNombre().c_str());
//    }
//}
//
//class Proyecto {
//private:
//    string nombre;
//    vector<Tarea*> tareas;
//public:
//    Proyecto(string nom) : nombre(nom) {}
//
//    void agregarTarea(Tarea* tarea) {
//        tareas.push_back(tarea);
//    }
//
//    void mostrarTareas() {
//        printf("Tareas del proyecto %s:\n", nombre.c_str());
//        for (Tarea* tarea : tareas) {
//            printf("Tarea: %s\n", tarea->getDescripcion().c_str());
//            tarea->mostrarEmpleados();
//        }
//    }
//};
//
//int main() {
//    Empleado e1("Juan", 1);
//    Empleado e2("Maria", 2);
//    Empleado e3("Carlos", 3);
//
//    Tarea t1("Diseno de Base de Datos", 10);
//    Tarea t2("Desarrollo de Backend", 20);
//    Tarea t3("Implementacion de Frontend", 15);
//
//    t1.asignarEmpleado(&e1);
//    t1.asignarEmpleado(&e2);
//
//    t2.asignarEmpleado(&e2);
//    t2.asignarEmpleado(&e3);
//
//    t3.asignarEmpleado(&e1);
//    t3.asignarEmpleado(&e3);
//
//    Proyecto proyecto("Sistema de Gestion");
//    proyecto.agregarTarea(&t1);
//    proyecto.agregarTarea(&t2);
//    proyecto.agregarTarea(&t3);
//
//    proyecto.mostrarTareas();
//
//    return 0;
//}