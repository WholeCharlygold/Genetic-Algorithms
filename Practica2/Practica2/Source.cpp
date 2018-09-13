#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random> //Libreria para la generacion de numeros aleatorios

using namespace std;

void binario(int **); //PROTOTIPOS
void gray(int **);
void real(float **);
void entero(int **);
void despliega(int **, float **);



void main() {
	int opcion; //Inicializacion de arreglos para los individuos
	int** arreglo;
	arreglo = (int **)malloc(sizeof(int*)*10); //Se creean 10 individuos 
	float** farreglo;
	farreglo = (float **)malloc(sizeof(float*) * 10);
	for (int i = 0; i < 10; i++) {
		farreglo[i] = (float*)malloc(sizeof(float) * 10); //Se crea cada individuo con 10 alelos
	}

	for (int i = 0; i < 10; i++) {
		arreglo[i] = (int*)malloc(sizeof(int) * 10);
	}

	cout << "1. BINARIO" << endl<<	 //MENU DESPLEGABLE PARA SELECCIONAR EL TIPO DE REPRESENTACION
			"2. CODIGO GRAY"<<endl<< 
		"3. NUMEROS REALES" << endl << 
		"4. NUMEROS ENTEROS" << endl <<
		"5. Salir"<<endl<<
		"Teclee la opcion deseada"<<endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		binario(arreglo); //1. Representacion binaria
		main();
		break;
	case 2:
		gray(arreglo); //2. Representacion con codigo gray
		main();
		break;
	case 3:
		real(farreglo); //3. Representación real
		main();
		break;
	case 4:
		entero(arreglo); //4. Representacion entera
		main();
		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "Opcion incorrecta" << endl;
		exit(0);
		break;
	}



}

void binario(int** arreglo) {
	std::default_random_engine generator; //Motor generador de numeros aleatorios
	std::uniform_int_distribution<int> distribution(0, 1); //Tipode distribucion para generar aleatorios

	for (int i=0;i<10;i++){
		for (int j = 0; j < 10; j++) {
			int dice_roll = distribution(generator);  // Se generan los numeros aleatorios
			arreglo[i][j] = dice_roll;					//Se llena cada individuo

		}
		
	}
	
	despliega(arreglo,NULL); //Se despliegan los 10 individuos

}
void real(float** farreglo) {
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(1.00f, 100.00f);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			float dice_roll = distribution(generator);  // Genera numeros reales
			farreglo[i][j] = dice_roll;
		

		}
		

	}

	despliega(NULL, farreglo);
}
void entero(int** arreglo) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 100);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int dice_roll = distribution(generator);  // Se generan numeros 1-0
			arreglo[i][j] = dice_roll;

		}

	}

	despliega(arreglo, NULL);
}
void gray(int** arreglo) { 
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 1);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int dice_roll = distribution(generator);  // Se generan numeros 1-0
			arreglo[i][j] = dice_roll;

		}

	}

	despliega(arreglo, NULL);

}

void despliega(int** arreglo, float** farreglo) { //Funcion para desplegar a los individuos
	cout << "Los individuos son:" << endl;
	if (arreglo != NULL) {
		for (int i = 0; i < 10; i++) {
			cout << endl;
			for (int j = 0; j < 10; j++) {
				cout << arreglo[i][j] << " ";

			}


		}
		free(arreglo);
		cout << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			cout << endl;
			for (int j = 0; j < 10; j++) {
				cout << farreglo[i][j] << " ";

			}
			

		}
		free(farreglo);
		cout << endl;
	}



}
	
