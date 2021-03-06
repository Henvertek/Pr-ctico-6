// Ejercicio 3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct curso {
	char nombre[20];
	int cupo;
	int costo;
};

int main(){
	struct curso cursos[40];
	char trash[1];
	char input;
	int amount = 0;
	do {
		cout << "Desea agregar un curso a la base de datos?(s/n)\n>>> ";
		cin >> input;
		cin.getline(trash, 1);
		if (input != 'n' && input != 'N') {
			cout << "\nIngrese el nombre del curso:\n>>> ";
			cin.getline(cursos[amount].nombre, 30);
			cout << "\nIngrese el cupo del curso:\n>>> ";
			cin >> cursos[amount].cupo;
			cout << "\nIngrese el costo del curso:\n>>> ";
			cin >> cursos[amount].costo;
			cout << "\nPerfil del curso " << cursos[amount].nombre << " cargado correctamente.\n\n";
			amount++;
		}
	} while ((input != 'n' && input != 'N') && amount < 40);
	do {
		cout << "\n     BUSCAR:\n\n";
		cout << "     1. Cursos bajo cierto costo\n     2. Buscar por nombre\n     3. Salir\n\n";
		cin >> input;
		switch (input) {
		case '1':
			int top;
			cout << "Ingrese el costo maximo:\n>>> ";
			cin >> top;
			cout << "NOMBRE";
			for (int i = 0; i < 14; i++) cout << " ";
			cout << " | COSTO\n";
			for (int i = 0; i < amount; i++) {
				if (cursos[i].costo <= top) {
					cout << cursos[i].nombre;
					int max = strlen(cursos[i].nombre);
					for (int i = 0; i < (20 - max) + 3; i++)
						cout << "_";

					cout << "$" <<cursos[i].costo << endl;
				}
			}
			break;
		case '2':
			cout << "Que curso busca?\n>>> ";
			char query[20];
			cin.getline(trash, 1);
			cin.getline(query, 20);
			cout << "NOMBRE";
			for (int i = 0; i < 14; i++) cout << " ";
			cout << " | CUPO  | COSTO \n";
			for (int i = 0; i < amount; i++) {
				if (strcmp(cursos[i].nombre, query) == 0) {
					cout << cursos[i].nombre;
					int max = strlen(cursos[i].nombre);
					for (int i = 0; i < (20 - max) + 3; i++)
						cout << "_";

					cout << cursos[i].cupo << "      " << cursos[i].costo << endl;
					break;
				}
			}
			break;
		case '3':
			cout << "Saliendo...";
			break;
		default:
			cout << "Opcion no valida\n";
		}
	} while (input != '3');
  return 0;
}