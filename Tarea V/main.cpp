#include <iostream>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

Nodo* head = NULL;


void insertarInicio() {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin.ignore();
    getline(cin, nuevo->carrera);

    nuevo->siguiente = head;
    head = nuevo;

    cout << "Estudiante insertado al inicio.\n";
}

void insertarFinal() {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin.ignore();
    getline(cin, nuevo->carrera);

    nuevo->siguiente = NULL;

    if (head == NULL) {
        head = nuevo;
    } else {
        Nodo* temp = head;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }

    cout << "Estudiante insertado al final.\n";
}

void mostrar() {
    if (head == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* temp = head;

    while (temp != NULL) {
        cout << "\nCarne: " << temp->carne << endl;
        cout << "Nombre: " << temp->nombre << endl;
        cout << "Apellido: " << temp->apellido << endl;
        cout << "Carrera: " << temp->carrera << endl;
        cout << "-----------------------------\n";

        temp = temp->siguiente;
    }
}


void buscar() {
    int carne;
    cout << "Ingrese carne a buscar: ";
    cin >> carne;

    Nodo* temp = head;

    while (temp != NULL) {
        if (temp->carne == carne) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << temp->nombre << endl;
            cout << "Apellido: " << temp->apellido << endl;
            cout << "Carrera: " << temp->carrera << endl;
            return;
        }
        temp = temp->siguiente;
    }

    cout << "Estudiante no encontrado.\n";
}


void eliminar() {
    int carne;
    cout << "Ingrese carne a eliminar: ";
    cin >> carne;

    Nodo* temp = head;
    Nodo* anterior = NULL;

    while (temp != NULL && temp->carne != carne) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        cout << "Estudiante no encontrado.\n";
        return;
    }

    // Si es el primero
    if (anterior == NULL) {
        head = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }

    delete temp;
    cout << "Estudiante eliminado correctamente.\n";
}


void menu() {
    int opcion;

    do {
        cout << "\n    SISTEMA DE ESTUDIANTES     \n";
        cout << "Nombre: Elder Geovani Samayoa Esquivel\n"; // IMPORTANTE PARA LA EVIDENCIA
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: insertarInicio(); break;
            case 2: insertarFinal(); break;
            case 3: mostrar(); break;
            case 4: buscar(); break;
            case 5: eliminar(); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);
}

// Función principal
int main() {
    menu();
    return 0;
}