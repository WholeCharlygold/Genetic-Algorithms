
#include "main.h"
using namespace std;
int ** poblacion;
void display(int ** disp1,int** disp2, int * puntos);
int ** cruza_un_punto();

int main(){
	poblacion=crearpoblacion();
	cruza_un_punto();
	
	return 0;
}

int ** cruza_un_punto() {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, NUMA - 1);
	int * puntos;
	int j=0;
	puntos=(int *)malloc(sizeof(int)*TAMP);
	int ** desendencia = Crear();

	for (int i = 0; i < TAMP; i = i + 2) {
		
		int dice_roll = distribution(generator);
		if(i%2==0){

		puntos[j+i]=dice_roll;
		puntos[i+j+1]=dice_roll;
		}
		
		
		//std::cout << dice_roll << std::endl;
		for (int j = 0; j < NUMA; j++) {

			if (j <= dice_roll) {
				desendencia[i][j] = poblacion[i][j];
				desendencia[i + 1][j] = poblacion[i + 1][j];
			}
			else {
				desendencia[i][j] = poblacion[i + 1][j];
				desendencia[i + 1][j] = poblacion[i][j];
			}


		}

	}

	display(poblacion,desendencia,puntos);
	return desendencia;



}
void display(int ** disp1,int** disp2, int * puntos) {

	std::cout << "********" << std::endl;
	std::cout<<"Poblacion"<<" \tDescendencia"<<"\tpunto"<<endl;
	for (int i = 0; i < TAMP; i++) {

		for (int j = 0; j < NUMA; j++) {

			//std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
			std::cout<<disp1[i][j];
		}
		std::cout<<"\t \t";
		for (int j = 0; j < NUMA; j++) {

			//std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
			std::cout<<disp2[i][j];
		}
		std::cout<<" \t\t";
		std::cout<<puntos[i];
		std::cout << std::endl;
	}

}

int ** Crear() {
	int ** creacion;
	creacion = (int **)malloc(sizeof(int*)*TAMP);
	for (int i = 0; i < TAMP; i++) {
		creacion[i] = (int *)malloc(sizeof(int)*NUMA);
	}
	return creacion;
}