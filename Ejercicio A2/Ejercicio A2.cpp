// Ejercicio A2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct date {
	unsigned short int dia, mes, año;
};

struct movimiento {
	struct date fecha;
	char tipo[14];
	float monto;
};

struct cuenta {
	char ID[11];
	char password[6];
	char apellido[15];
	char nombre[15];
	float saldo;
	int amount = 0;
	struct movimiento movimientos[30];
};

int main() {
	struct date fechaActual;
	fechaActual.dia = 17;
	fechaActual.mes = 5;
	fechaActual.año = 2018;
	struct cuenta database[10];
	int input;
	char trash[1];
	char tiposDeMovimientos[4][14] = { "extraccion", "deposito", "transferencia", "pago" };
	char nombres[9][15] = { "Juan", "Pedro", "Maria", "Jose", "Laura", "Camila", "Carlos", "Andrea", "Julio" };
	char apellidos[9][15] = { "Rodriguez", "Lopez", "Moreno", "Zapata", "Croft", "Douglas", "Ramirez", "McCallister", "Johnson" };
	for (int i = 0; i < 9; i++) {//Todos los clientes menos uno
		for (int n = 0; n < 10; n++) {//Se genera el numero de cuenta
			database[i].ID[n] = (rand() % 10) + 48;
		}
		database[i].ID[10] = '\0';
		for (int n = 0; n < 5; n++) {
			database[i].password[n] = (rand() % 10) + 48;
		}
		database[i].password[5] = '\0';
		strcpy_s(database[i].nombre, nombres[i]);
		strcpy_s(database[i].apellido, apellidos[i]);
		database[i].saldo = float(rand()) + float(rand()) / 100;
	}

	struct cuenta cliente;
	do {
		cout << "Bienvenido. Para crear su cuenta, por favor ingrese su apellido:\n>>> ";
		cin.getline(cliente.apellido, 15);
	} while (strlen(cliente.apellido) == 0);
	do {
		cout << "Por favor ingrese su nombre:\n>>> ";
		cin.getline(cliente.nombre, 15);
	} while (strlen(cliente.nombre) == 0);
	do {
		cout << "Por favor ingrese su numero de cuenta de 10 digitos:\n>>> ";
		cin.getline(cliente.ID, 11);
	} while (strlen(cliente.ID) != 10);
	do {
		cout << "Ingrese su contraseña(hasta 5 caracteres):\n>>> ";
		cin.getline(cliente.password, 6);
	} while (strlen(cliente.password) == 0);
	cliente.saldo = 0;
	database[9] = cliente;

	cout << "Cuenta creada con exito. Bienvenido\n\n";

	do {
		cliente = database[9];
		cout << "\n.____________________________________.\n";
		cout << "|__________MENU_OPERACIONES__________|\n";
		cout << "|                                    |\n";
		cout << "|     1. Extraccion en efectivo      |\n";
		cout << "|     2. Deposito                    |\n";
		cout << "|     3. Consulta de saldo           |\n";
		cout << "|     4. Transferencia               |\n";
		cout << "|     5. Salir                       |\n";
		cout << "|____________________________________|\n\n>>> ";
		cin >> input;
		cin.getline(trash, 1);
		switch (input) {
		case 1:
			if (cliente.saldo) {
				cout << "Su saldo actual es de $" << cliente.saldo << ".\nIngrese la cantidad a extraer:\n>>> $";
				float amount;
				cin >> amount;
				if (amount <= cliente.saldo) {
					cliente.saldo -= amount;
					strcpy_s(cliente.movimientos[cliente.amount].tipo, tiposDeMovimientos[0]);
					cliente.movimientos[cliente.amount].fecha = fechaActual;
					cliente.movimientos[cliente.amount].monto = amount;
					cliente.amount++;
					cout << "Su nuevo saldo es de $" << cliente.saldo << ".\n";
					database[9] = cliente;
				}
				else {
					cout << "Saldo insuficiente.\n";
				}
			}
			else cout << "Para realizar extracciones, primero debe realizar al menos un deposito.\n";
			break;
		case 2:
			cout << "Su saldo actual es de $" << cliente.saldo << ".\nIngrese la cantidad que desea depositar:\n>>> $";
			float amount;
			cin >> amount;
			cliente.saldo += amount;
			strcpy_s(cliente.movimientos[cliente.amount].tipo, tiposDeMovimientos[1]);
			cliente.movimientos[cliente.amount].fecha = fechaActual;
			cliente.movimientos[cliente.amount].monto = amount;
			cliente.amount++;
			cout << "Su nuevo saldo es de $" << cliente.saldo << ".\n";
			database[9] = cliente;
			break;
		case 3:
			cout << "Su saldo es de $" << cliente.saldo << ".\n";
			break;
		case 4:
			if (cliente.saldo) {
				cout << "Su saldo actual es de $" << cliente.saldo << ".\nIngrese la cantidad a transferir:\n>>> $";
				float amount;
				char nroDestino[11];
				cin >> amount;
				cin.getline(trash, 1);
				if (amount <= cliente.saldo) {
					do {
						cout << "Por favor ingrese el numero de 10 digitos de la cuenta a la que desea transferir:\n>>> ";
						cin.getline(nroDestino, 11);
					} while (strlen(nroDestino) != 10);
					for (int i = 0; i < 10; i++) {
						if (!strcmp(nroDestino, database[i].ID)) {
							cout << "Transfiriendo $" << amount << " a la cuenta perteneciente a " << database[i].nombre << " " << database[i].apellido << "...\n";
							cliente.saldo -= amount;
							strcpy_s(cliente.movimientos[cliente.amount].tipo, tiposDeMovimientos[2]);
							cliente.movimientos[cliente.amount].fecha = fechaActual;
							cliente.movimientos[cliente.amount].monto = amount;
							cliente.amount++;
							database[9] = cliente;
							database[i].saldo += amount;
							cliente = database[9];
							cout << "Transferencia exitosa.";
							cout << "Su nuevo saldo es de $" << cliente.saldo << ".\n";
							break;
						}
					}
				}
				else {
					cout << "Saldo insuficiente.\n";
				}
			}
			else cout << "Para realizar transferencias, primero debe realizar al menos un deposito.\n";
			break;
		case 5:
			break;
		case -1337:
			for (int i = 0; i < 10; i++) {
				cout << endl << i << ". NOMBRE Y APELLIDO: " << database[i].nombre << " " << database[i].apellido << ".\n  ";
				cout << "ID: " << database[i].ID << ".\n  ";
				cout << "CONTRASEÑA: " << database[i].password << ".\n  ";
				cout << "SALDO: $" << database[i].saldo << ".\n";
				for (int j = 0; j < database[i].amount; j++) {
					cout << "  "<< j << ". TIPO DE MOVIMIENTO: " << database[i].movimientos[j].tipo << ".\n     ";
					cout << "FECHA: " << database[i].movimientos[j].fecha.dia << "/" << database[i].movimientos[j].fecha.mes << "/" << database[i].movimientos[j].fecha.año << "\n     ";
					cout << "MONTO: $" << database[i].movimientos[j].monto << ".\n";
				}
			}
			break;
		default:
			cout << "Opcion no valida.\n\n";
		}
		if (input == 5) break;

	} while (input != 5);
	cout << "Saliendo...";
	return 0;
}