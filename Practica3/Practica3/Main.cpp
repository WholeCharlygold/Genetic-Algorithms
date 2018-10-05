#include "main.h"
#include "mainc.h"

using namespace std;

int main() {
	int ** poblacion_inicial;
	int ** padres = Crear();
	int ** descendencia = Crear();
	int** mutantes = Crear();
	poblacion_inicial=crearpoblacion();	

	AG_Ruleta(poblacion_inicial);
	
/*
		 	 	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < NUMA; j++) {
			
			cout << poblacion_inicial[i][j];
		}
		cout << endl;
	}
	 
	
		valor(poblacion_inicial);

		//maximo(aptitud(poblacion_inicial));


		padres=seleccion_padres(Ruleta(aptitud(poblacion_inicial)), poblacion_inicial);
		for (int i = 0; i < TAMP; i++) {
			for (int j = 0; j < NUMA; j++) {

				cout << padres[i][j];
			}
			cout << endl;
		}
		descendencia = punto_de_cruza(padres);
		cout << "descendencia" << endl;
		for (int i = 0; i < TAMP; i++) {
			for (int j = 0; j < NUMA; j++) {

				cout << descendencia[i][j];
			}
			cout << endl;
		}

		mutantes= mutacion(descendencia);
		cout << "mutants"<< endl;
		for (int i = 0; i < TAMP; i++) {
			for (int j = 0; j < NUMA; j++) {

				cout << mutantes[i][j];
			}
			cout << endl;
		}
		 
		 */
		
	return 0;
}
