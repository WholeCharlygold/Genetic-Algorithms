#include "main.h"
int** binario(int** arreglo);
int ** entero(int** arreglo);
void real(float** farreglo);
void despliega(int** arreglo, float** farreglo);
int ** gray(int** arreglo) ;
using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


int **  crearpoblacion() {
	int opcion; //Inicializacion de arreglos para los individuos
	int** arreglo;
	arreglo = (int **)malloc(sizeof(int*) * TAMP); //Se creean 10 individuos 
	float** farreglo;
	farreglo = (float **)malloc(sizeof(float*) * TAMP);
	for (int i = 0; i < TAMP; i++) {
		farreglo[i] = (float*)malloc(sizeof(float) * NUMA); //Se crea cada individuo con 10 alelos
	}

	for (int i = 0; i <TAMP; i++) 
	{
		arreglo[i] = (int*)malloc(sizeof(int) * NUMA);
	}

	/*cout << "1. BINARIO" << endl <<	 //MENU DESPLEGABLE PARA SELECCIONAR EL TIPO DE REPRESENTACION
		"2. CODIGO GRAY" << endl <<
		"3. NUMEROS REALES" << endl <<
		"4. NUMEROS ENTEROS" << endl <<
		"5. Salir" << endl <<
		"Teclee la opcion deseada" << endl;
	cin >> opcion;*/

	switch (REPR)
	{
	case 1:
		binario(arreglo); //1. Representacion binaria
		//crearpoblacion(TAMP,NUMA,representacion);
		break;
	case 2:
		gray(arreglo); //2. Representacion con codigo gray
		//crearpoblacion(TAMP,NUMA,representacion);
		break;
	case 3:
		real(farreglo); //3. Representación real
		//crearpoblacion(TAMP,NUMA,representacion);
		break;
	case 4:
		entero(arreglo); //4. Representacion entera
		//crearpoblacion(TAMP,NUMA,representacion);
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

struct numero** nuevo() {
	std::default_random_engine generator (seed); //Motor generador de numeros aleatorios
	std::uniform_int_distribution<int> distribution(0, 1); //Tipode distribucion para generar aleatorios
	 numero ** a;
	 a=(struct numero **)malloc(sizeof(struct numero *)* TAMP);
	for(int i=0;i<TAMP;i++){
		a[i]=(struct numero *)malloc(sizeof(struct numero  )*NUMA);
	}

	for (int i = 0; i < TAMP; i++) {
		std::uniform_int_distribution<int> distribution5(0,NUMA-1);
		int dice_roll2=distribution5(generator);
		for (int j = 0; j < NUMA; j++) {
			int dice_roll = distribution(generator); 
			 // Se generan los numeros aleatorios
			a[i][j].bit = dice_roll;					//Se llena cada individuo
			if(dice_roll2==j)
			a[i][dice_roll2].cruza='!';
			else
			a[i][j].cruza=NULL;
		}

	}
	return a;
	//despliega(arreglo, NULL); //Se despliegan los 10 individuos

}

int** binario(int** arreglo) {
	std::default_random_engine generator (seed); //Motor generador de numeros aleatorios
	std::uniform_int_distribution<int> distribution(0, 1); //Tipode distribucion para generar aleatorios
	 numero ** a;
	 a=(struct numero **)malloc(sizeof(struct numero *)* TAMP);
	for(int i=0;i<TAMP;i++){
		a[i]=(struct numero *)malloc(sizeof(struct numero  )*NUMA);
	}

	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < NUMA; j++) {
			int dice_roll = distribution(generator);  // Se generan los numeros aleatorios
			arreglo[i][j] = dice_roll;					//Se llena cada individuo

		}

	}
	return arreglo;
	//despliega(arreglo, NULL); //Se despliegan los 10 individuos

}


void real(float** farreglo) {
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(1.00f, 100.00f);

	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < NUMA; j++) {
			float dice_roll = distribution(generator);  // Genera numeros reales
			farreglo[i][j] = dice_roll;


		}


	}

	despliega(NULL, farreglo);
}
int ** entero(int** arreglo) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 100);

	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < NUMA; j++) {
			int dice_roll = distribution(generator);  // Se generan numeros 1-0
			arreglo[i][j] = dice_roll;

		}

	}
	return arreglo;
	//despliega(arreglo, NULL);
}
int ** gray(int** arreglo) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 1);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int dice_roll = distribution(generator);  // Se generan numeros 1-0
			arreglo[i][j] = dice_roll;

		}

	}
	return arreglo;
	//despliega(arreglo, NULL);

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

