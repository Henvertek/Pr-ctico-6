// Ejercicio 1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct day {
	int num;
	float maxTemp, minTemp;
};

int main(){
	struct day mes[30];
	float monthMinAvg = 0, monthMaxAvg = 0;
	for (int i = 0; i < 30; i++) {
		mes[i].num = i + 1;
		mes[i].minTemp = rand() % 20 - 2;
		mes[i].maxTemp = mes[i].minTemp + rand() % 10 + 3;
		monthMinAvg += mes[i].minTemp;
		monthMaxAvg += mes[i].maxTemp;
	}
	monthMinAvg /= 30;
	monthMaxAvg /= 30;
	cout << "La minima promedio del mes fue de " << monthMinAvg << " y la maxima promedio de " << monthMaxAvg << endl;
	system("pause");
  return 0;
}