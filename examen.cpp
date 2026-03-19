/*
Nombre del estudiante: Dylan Sebastian Cabrera Enríquez
Curso: Bootcamp Programación Cero a POO
Clase: 10 - Examen 1 (C++)
Fecha: 18/03/2026
Tema:
Sistema de registro y análisis de notas de estudiantes
Entrada:
- Cantidad de estudiantes
- Nombres de estudiantes
- Nota de cada estudiante
Proceso:
- Validar datos ingresados
- Almacenar información en arreglos
- Calcular promedio general
- Buscar una nota mayor y una nota menor
- Mostrar reporte de aprobados y reprobados
- Permitir consultar un estudiante por nombre
Salida:
- Listado de estudiantes y notas
- Promedio general
- Nota mayor y nota menor
- Cantidad de aprobados y reprobados
- Resultado de búsqueda por nombre
*/
#include <iostream>
using namespace std;
void registrar(string nombres[], double notas[], int &n);
void mostrarListado(string nombres[], double notas[], int n);
void calcularPromedio(double notas[], int n);
void mayorMenor(string nombres[], double notas[], int n);
void aprobadosReprobados(double notas[], int n);
void buscar(string nombres[], double notas[], int n);
int menu();
int menu() {
    int op;
    cout << "Menu";
    cout << "1. Registrar estudiantes y notas" << endl ;
    cout << "2. Mostrar listado completo" << endl ;
    cout << "3. Mostrar promedio general" << endl ;
    cout << "4. Mostrar nota mayor y nota menor" << endl;
    cout << "5. Mostrar aprobados y reprobados" << endl;
    cout << "6. Buscar estudiante por nombre" << endl;
    cout << "7. Salir" << endl ;
    cout << "Seleccione una opcion: " << endl;
    cin >> op;

    return op;
}
int main() {
    string nombres[20];
    double notas[20];
    int n = 0;
    int opcion;
 do {
        opcion = menu();

        switch(opcion) {
            case 1:
                registrar(nombres, notas, n);
                break;
            case 2:
                mostrarListado(nombres, notas, n);
                break;
            case 3:
                calcularPromedio(notas, n);
                break;
            case 4:
                mayorMenor(nombres, notas, n);
                break;
            case 5:
                aprobadosReprobados(notas, n);
                break;
            case 6:
                buscar(nombres, notas, n);
                break;
            case 7:
                cout << "Saliendo del programa";
                break;
            default:
                cout << "Opcion invalida";
        }
    } while(opcion != 7);
    return 0;
}
void registrar(string nombres[], double notas[], int &n) {
    do {
        cout << "Ingrese cantidad de estudiantes: ";
        cin >> n;
    } while(n < 1 || n > 20);
    for(int i = 0; i < n; i++) {
        do {
            cout << "Nombre del estudiante " << i+1 << ": ";
            getline(cin, nombres[i]);
        } while(nombres[i] == "");

        do {
            cout << "Nota : ";
            cin >> notas[i];
        } while(notas[i] < 0 || notas[i] > 20);

    }
}
void mostrarListado(string nombres[], double notas[], int n) {
    if(n == 0) {
        cout << "No hay estudiantes registrados";
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << i+1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}
void calcularPromedio(double notas[], int n) {
    if(n == 0) {
        cout << "No hay datos";
        return;
    }
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += notas[i];
    }
    cout << "Promedio: " << suma / n << endl;
}
void mayorMenor(string nombres[], double notas[], int n) {
    if(n == 0) {
        cout << "No hay datos";
        return;
    }
    double mayor = notas[0];
    double menor = notas[0];
    string nomMayor = nombres[0];
    string nomMenor = nombres[0];
    for(int i = 1; i < n; i++) {
        if(notas[i] > mayor) {
            mayor = notas[i];
            nomMayor = nombres[i];
        }
        if(notas[i] < menor) {
            menor = notas[i];
            nomMenor = nombres[i];
        }
    }
    cout << "Mayor: " << nomMayor << " - " << mayor << endl;
    cout << "Menor: " << nomMenor << " - " << menor << endl;
}
void aprobadosReprobados(double notas[], int n) {
    if(n == 0) {
        cout << "No hay datos.\n";
        return;
    }
    int aprobados = 0, reprobados = 0;
    for(int i = 0; i < n; i++) {
        if(notas[i] >= 14)
            aprobados++;
        else
            reprobados++;
    }
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}
void buscar(string nombres[], double notas[], int n) {
    if(n == 0) {
        cout << "No hay datos.\n";
        return;
    }
    string buscado;
    cout << "Ingrese nombre a buscar: ";
    cin >> buscado;
    bool encontrado = false;
    for(int i = 0; i < n; i++) {
        if(nombres[i] == buscado) {
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Nota: " << notas[i] << endl;
            if(notas[i] >= 14)
                cout << "Estado: Aprobado\n";
            else
                cout << "Estado: Reprobado\n";
            encontrado = true;
            break;
        }
    }
    if(!encontrado) {
        cout << "Estudiante no encontrado";
    }
}
