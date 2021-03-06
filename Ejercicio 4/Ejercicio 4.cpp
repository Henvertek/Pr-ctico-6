// Ejercicio 4.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct date {
	int day;
	int month;
	int year;
};

struct form {
	char legajo[8];
	char codigo[5];
	struct date fecha;
	char nombre[30];
};

int compareDate(struct date a, struct date b) {
	return(a.day == b.day && a.month == b.month && a.year == b.year);
}

int main()
{
	struct form constancias[70];
	int amount = 0;
	char trash[1];
	char query[4];
	struct date dia;
	char input;
	do {
		cout << "    MENU\n\n";
		cout << "    1. Cargar constancia\n    2. Mostrar alumnos que rinden una materia\n    3. Mostrar cantidad de examenes en una fecha determinada\n    4. Salir\n\n";
		cin >> input;
		cin.getline(trash, 1);
		int gente = 0;
		switch (input) {
		case '1':
			if (amount < 70) {
				cout << "Ingrese el nombre completo del alumno:\n>>> ";
				cin.getline(constancias[amount].nombre, 30);
				cout << "Ingrese el codigo del legajo(7 digitos)\n>>> ";
				cin.getline(constancias[amount].legajo, 8);
				cout << "Ingrese el codigo de la materia(4 digitos)\n>>> ";
				cin.getline(constancias[amount].codigo, 5);
				cout << "Ingrese el dia, el mes y el año separados por espacios;\n>>> ";
				cin >> constancias[amount].fecha.day >> constancias[amount].fecha.month >> constancias[amount].fecha.year;
				amount++;
				cout << "Constancia cargada con exito.\n\n";
			}
			else cout << "No queda espacio en la base de datos.\n\n";
			break;
		case '2':
			cout << "Ingrese el codigo de la materia(4 digitos)\n>>> ";
			cin.getline(query, 5);
			for (int i = 0; i < amount; i++) {
				if (!strcmp(query, constancias[i].codigo)) {
					cout << constancias[i].nombre << ", Legajo numero " << constancias[i].legajo << endl;
				}
			}
			break;
		case '3':
			cout << "Ingrese el dia, el mes y el año separados por espacios;\n>>> ";
			cin >> dia.day >> dia.month >> dia.year;
			for (int i = 0; i < amount; i++) {
				if (compareDate(dia, constancias[i].fecha)) gente++;
			}
			cout << "Hay " << gente << " alumnos inscriptos para esa fecha.\n";
			break;
		case '4':
			cout << "Saliendo...";
			break;
		default:
			cout << "Opcion no valida.\n\n";
		}
	} while (input != '4');
  return 0;
}