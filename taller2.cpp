#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (UPDATE)
void modificarEstudiante() {
// Debes permitir actualizar nombre, carnet y/o edad
// de un estudiante identificado por su carnet.
// Puedes usar o no manejo de archivos.
// Si lo implementas con archivos correctamente, obtendrás **2 puntos extra**.

ifstream archivo("estudiantes.txt"); //se lee el txt
ofstream temp("temp.txt"); //archivo temporal para poder guardar la modificacion
Estudiante alumno; //llamamos al struct
string buscar; //variable a buscar carnet
bool nuevo = false; //booleana para encontrar el carnet inicia como falsa

cout << "Ingrese el carnet que desea modificar: "; //el usuario ingresa el carnet
cin >> buscar; //se lee el carnet

if (archivo.is_open() && temp.is_open()) { //si el archivo original y el temporal estan abiertos
while (archivo >> alumno.nombre >> alumno.carnet >> alumno.edad) { //mientras lea el txt
if (alumno.carnet == buscar) { //si se encuentra un carnet igual al digitado
Estudiante actualizado; //la variable para los atributos actualizados del estudiante
cout << "Digite el nuevo nombre: "; //se pide nombre nuevo
cin >> actualizado.nombre; //se lee
cout << "Digite el nuevo carnet: "; //se pide carnet nuevo
cin >> actualizado.carnet;//se lee
cout << "Digite la nueva edad: ";//se pide edad nueva
cin >> actualizado.edad; //se lee
temp << actualizado.nombre << " " << actualizado.carnet << " " << actualizado.edad << endl; //se manda al temp
nuevo = true; //estudiante modificado verdadero
} 
else {
temp << alumno.nombre << " " << alumno.carnet << " " << alumno.edad << endl; //se mantiene la lista sin modificaciones
}
}
archivo.close(); //cierra archivo
temp.close(); //cierra el temporal
remove("estudiantes.txt"); //se remueve el txt original
rename("temp.txt", "estudiantes.txt"); // el txt temporal pasa a ser el original con las modificaciones realizadas

if (nuevo) //si nuevo es verdadero
cout << "Estudiante actualizado correctamente.\n"; //cambios realizados
else // si no es
cout << "Lo siento carnet no encontrado.\n"; //carnet no se encuentra en el archivo
} else { 
cout << "No se pudo abrir los archivos.\n"; //error abriendo los archivos txt
}
}

// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                eliminado = true;               // No se copia: se “borra”
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: modificarEstudiante(); break;  // 👉 Completa aquí
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}
