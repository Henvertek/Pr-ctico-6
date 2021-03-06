// Ejercicio A1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct publisher {
	char nombre[25];
	char direccion[25];
	char contacto[25];
};

struct libro {
	char titulo[25];
	char autor[25];
	struct publisher editorial;
	int año;
	int stock;
};

void printMenu() {
	cout << ".____________________________________.\n";
	cout << "|___________MENU_PRINCIPAL___________|\n";
	cout << "|                                    |\n";
	cout << "|   1. Mostrar libros por autor      |\n";
	cout << "|   2. Mostrar datos de libro        |\n";
	cout << "|   3. Mostrar libros segun stock    |\n";
	cout << "|   4. Salir                         |\n";
	cout << "|____________________________________|\n\n>>> ";
}

int main(){
	struct libro libros[1500];
	int bookAmount = 1500;
	char trash[1];
	char query[25];
	int input;

	do {
		printMenu();
		cin >> input;
		cin.getline(trash, 1);
		int maxStock;
		switch (input) {
		case 1:
			cout << "Ingrese el nombre del autor:\n>>> ";
			cin.getline(query, 25);
			for (int i = 0; i < bookAmount; i++) {
				if (!strcmp(libros[i].autor, query)) {
					cout << i + 1 << ". " << libros[i].titulo << endl;
				}
			}
			break;
		case 2:
			cout << "Ingrese el nombre del libro:\n>>> ";
			cin.getline(query, 25);
			for (int i = 0; i < bookAmount; i++) {
				struct libro curr = libros[i];
				if (!strcmp(curr.titulo, query)) {
					cout << "AUTOR:                   " << curr.autor << endl;
					cout << "ULTIMO AÑO DE IMPRESION: " << curr.año << endl;
					cout << "STOCK:                   " << curr.stock << "unidades" << endl;
					cout << "____________________________________________\nDATOS DE EDITORIAL:\n\n";
					cout << "NOMBRE:    " << curr.editorial.nombre << endl;
					cout << "DIRECCION: " << curr.editorial.direccion << endl;
					cout << "CONTACTO:  " << curr.editorial.contacto << "\n\n";
				}
			}
			break;
		case 3:
			cout << "Ingrese el stock maximo:\n>>> ";
			cin >> maxStock;
			for (int i = 0; i < bookAmount; i++) {
				if (libros[i].stock <= maxStock) {
					cout << i + 1 << ". " << libros[i].titulo << endl;
				}
			}
			cin.getline(trash, 1);
			break;
		case 4:
			break;
		default:
			cout << "Opcion no valida.\n\n";
		}
	} while (input != 4);
	cout << "Saliendo...";
  return 0;
}