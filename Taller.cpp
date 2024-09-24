#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float nota;
    Estudiante* siguiente;
};

void agregarEstudiante(Estudiante*& cabeza, string nombre, int codigo, float nota) {
    Estudiante* nuevoEstudiante = new Estudiante;
    nuevoEstudiante->nombre = nombre;
    nuevoEstudiante->codigo = codigo;
    nuevoEstudiante->nota = nota;
    nuevoEstudiante->siguiente = cabeza;
    cabeza = nuevoEstudiante;
}

void mostrarEstudiantes(Estudiante* cabeza) {
    Estudiante* actual = cabeza;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << ", Codigo: " << actual->codigo << ", Nota: " << actual->nota << endl;
        actual = actual->siguiente;
    }
}

void ordenarPorNota(Estudiante*& cabeza) {
    if (!cabeza) return;
    bool swapped;
    Estudiante* ptr1;
    Estudiante* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = cabeza;
        while (ptr1->siguiente != lptr) {
            if (ptr1->nota < ptr1->siguiente->nota) {
                swap(ptr1->nombre, ptr1->siguiente->nombre);
                swap(ptr1->codigo, ptr1->siguiente->codigo);
                swap(ptr1->nota, ptr1->siguiente->nota);
                swapped = true;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarPorCodigo(Estudiante*& cabeza) {
    if (!cabeza) return;
    bool swapped;
    Estudiante* ptr1;
    Estudiante* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = cabeza;
        while (ptr1->siguiente != lptr) {
            if (ptr1->codigo > ptr1->siguiente->codigo) {
                swap(ptr1->nombre, ptr1->siguiente->nombre);
                swap(ptr1->codigo, ptr1->siguiente->codigo);
                swap(ptr1->nota, ptr1->siguiente->nota);
                swapped = true;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    } while (swapped);
}

void liberarMemoria(Estudiante*& cabeza) {
    while (cabeza != nullptr) {
        Estudiante* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    Estudiante* listaEstudiantes = nullptr;
    int opcion;
    string nombre;
    int codigo;
    float nota;

    do {
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Ordenar por Nota\n";
        cout << "4. Ordenar por Codigo\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cin.ignore(); // Limpiar el búfer antes de leer una cadena
            cout << "Nombre: ";
            getline(cin, nombre); // Para leer nombres con espacios
            cout << "Codigo: ";
            cin >> codigo;
            cout << "Nota: ";
            cin >> nota;
            agregarEstudiante(listaEstudiantes, nombre, codigo, nota);
            break;
        case 2:
            mostrarEstudiantes(listaEstudiantes);
            break;
        case 3:
            ordenarPorNota(listaEstudiantes);
            cout << "Estudiantes ordenados por Nota.\n";
            mostrarEstudiantes(listaEstudiantes);
            break;
        case 4:
            ordenarPorCodigo(listaEstudiantes);
            cout << "Estudiantes ordenados por Codigo.\n";
            mostrarEstudiantes(listaEstudiantes);
            break;
        case 5:
            liberarMemoria(listaEstudiantes);
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida\n";
        }
    } while (opcion != 5);

    return 0;
}

