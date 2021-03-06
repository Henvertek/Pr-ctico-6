// Ejercicio 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct student {
	char fullName[30];
	char phoneNumber[17];
	char address[50];
	char major[45];
	char email[30];
};

int main(){
	struct student classroom[40];
	char trash[1];
	int amount = 0;
	char input;
	do {
		cout << "Desea agregar un alumno a la base de datos?(s/n)\n>>> ";
		cin >> input;
		cin.getline(trash, 1);
		if (input != 'n' && input != 'N') {
			cout << "\nIngrese el nombre del alumno:\n>>> ";
			cin.getline(classroom[amount].fullName, 30);
			cout << "\nIngrese el numero telefonico del alumno:\n>>> ";
			cin.getline(classroom[amount].phoneNumber, 17);
			cout << "\nIngrese el domicilio del alumno:\n>>> ";
			cin.getline(classroom[amount].address, 50);
			cout << "\nIngrese la carrera del alumno:\n>>> ";
			cin.getline(classroom[amount].major, 45);
			cout << "\nIngrese el correo electronico del alumno:\n>>> ";
			cin.getline(classroom[amount].email, 30);
			cout << "\nPerfil del alumno " << classroom[amount].fullName << " cargado correctamente.\n\n";
			amount++;
		}
	} while ((input != 'n' && input != 'N') && amount < 40);
	do {
		cout << "\n     MOSTRAR:\n\n";
		cout << "     1. Numeros de telefono\n     2. Domicilios\n     3. Carreras\n     4. Correos electronicos\n     5. Salir\n\n";
		cin >> input;
		switch (input) {
		case '1':
			cout << "NOMBRE";
			for (int i = 0; i < 24; i++) cout << " ";
			cout << " | NUMERO\n";
			for (int i = 0; i < amount; i++) {
				cout << classroom[i].fullName;
				int max = strlen(classroom[i].fullName);
				for (int i = 0; i < (30 - max) + 3; i++)
					cout << "_";
				
				cout << classroom[i].phoneNumber << endl;
			}
			break;
		case '2':
			cout << "NOMBRE";
			for (int i = 0; i < 24; i++) cout << " ";
			cout << " | DOMICILIO\n";
			for (int i = 0; i < amount; i++) {
				cout << classroom[i].fullName;
				int max = strlen(classroom[i].fullName);
				for (int i = 0; i < (30 - max) + 3; i++)
					cout << "_";

				cout << classroom[i].address << endl;
			}
			break;
		case '3':
			cout << "NOMBRE";
			for (int i = 0; i < 24; i++) cout << " ";
			cout << " | CARRERA\n";
			for (int i = 0; i < amount; i++) {
				cout << classroom[i].fullName;
				int max = strlen(classroom[i].fullName);
				for (int i = 0; i < (30 - max) + 3; i++)
					cout << "_";

				cout << classroom[i].major << endl;
			}
			break;
		case '4':
			cout << "NOMBRE";
			for (int i = 0; i < 24; i++) cout << " ";
			cout << " | CORREO ELECTRONICO\n";
			for (int i = 0; i < amount; i++) {
				cout << classroom[i].fullName;
				int max = strlen(classroom[i].fullName);
				for (int i = 0; i < (30 - max) + 3; i++)
					cout << "_";

				cout << classroom[i].email << endl;
			}
			break;
		case '5':
			cout << "Saliendo...";
			break;
		default:
			cout << "Opcion no valida\n";
		}
	} while (input != '5');
  return 0;
}