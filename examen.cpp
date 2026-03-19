/*
Nombre del estudiante: Dylan Sebastian Cabrera Enríquez
Curso: Bootcamp Programación Cero a POO
Clase: 10 - Examen 1 (C++)
Fecha: 18/03/2026
Tema:
Sistema de registro y análisis de notas de estudiantes
*/
#include <iostream>
using namespace std;
void registrar(string nombres[], float notas[], int &n);
void mostrarListado(string nombres[], float notas[], int n);
void calcularPromedio(float notas[], int n);
void mayorMenor(string nombres[], float notas[], int n);
void aprobadosReprobados(float notas[], int n);
void buscar(string nombres[], float notas[], int n);
int menu();

int main() {
    string nombres[20];
    float notas[20];
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
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while(opcion != 7);

    return 0;
}

