#include "main.h"
extern "C" {
#include "mainc.h"
}

int * valor(int ** poblacion) {
	int * resultado;
	int valor_x=0;
	resultado = (int *)malloc(sizeof(int)*TAMP);

	for (int i = 0; i < TAMP; i++) {

		valor_x = convertBinaryToDecimal(poblacion[i]);
		resultado[i] = valor_x;
		//std::cout << resultado[i]<<std::endl;
	}

	return resultado;

}

float * probabilidad(int ** poblacion) {
	float suma = 0;
	float * proba = (float *)malloc(sizeof(float)*TAMP);

	for (int i = 0; i < TAMP; i++) {
		suma += aptitud(poblacion)[i];
	}
	for (int i = 0; i < TAMP; i++) {
		proba[i] = aptitud(poblacion)[i] / suma;
	//	std::cout << proba[i] << std::endl;
	}
	return proba;
}

int * aptitud(int ** poblacion) {
	
	int * resultado;
	int * x=valor(poblacion);
	resultado = (int *)malloc(sizeof(int)*TAMP);


	for (int i = 0; i < TAMP; i++) {
		resultado[i] = x[i] * x[i]; //APTITUD F(X)
	//	std::cout << resultado[i] << std::endl;
	}
	return resultado;
}


int maximo(int * aptitud) {
	int max_value;
	max_value = *std::max_element(aptitud, aptitud + TAMP);
	return max_value;
}
float maximo_float(float * aptitud) {
	float max_value;
	max_value = *std::max_element(aptitud, aptitud + TAMP);
	return max_value;
}

int minimo(int * aptitud) {

	int min_value;
	min_value = *std::min_element(aptitud, aptitud + TAMP);
	return min_value;
}
float minimo_float(float * aptitud) {

	float min_value;
	min_value = *std::min_element(aptitud, aptitud + TAMP);
	return min_value;
}

int * Ruleta(int * fitness) {

	float* probabilidad;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<float> distribution(0.00f, 1.00f);
	int * padres;
	float suma = 0;
	float * probabilidad_acumulada;
	float aux;
	probabilidad = (float*)malloc(sizeof(float)*TAMP);
	padres = (int *)malloc(sizeof(int)*TAMP);
	probabilidad_acumulada = (float *)malloc(sizeof(int)*TAMP);

	probabilidad_acumulada[0] = 0;
	aux = 0;

	for (int i = 0; i < TAMP; i++) {
		suma += fitness[i];
	}
	for (int i = 0; i < TAMP; i++) {
		probabilidad[i] = fitness[i] / suma;
		probabilidad_acumulada[i] = probabilidad[i] + aux;
		aux = probabilidad_acumulada[i];

	}
	//std::cout << "PADRES_INDEX" << std::endl;
	for (int i = 0; i < TAMP; i++) {
		float dice_roll = distribution(generator); 
		if (probabilidad_acumulada[0] > dice_roll) {
			padres[i] = 0;
		//	std::cout << padres[i] << std::endl;
		}
		else {
			for (int j = 0; j < TAMP; j++) {

				if (probabilidad_acumulada[j]<dice_roll && probabilidad_acumulada[j + 1] >dice_roll) {
					padres[i] = j + 1;
					//std::cout << padres[i] << std::endl;


				}

			}

		}
		

		


	}
	return padres;
}

int ** seleccion_padres(int * padres_index, int ** poblacion) {

	int ** padres;
	padres = (int **)malloc(sizeof(int*)*TAMP);
	for (int i = 0; i < TAMP; i++) {
		padres[i] = (int *)malloc(sizeof(int)*NUMA);
	}
	

	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < NUMA; j++) {
			padres[i][j] = poblacion[padres_index[i]][j];
		}
		

	}
	return padres;
}

int ** punto_de_cruza(int ** poblacion) {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, NUMA - 1);
	int ** desendencia = Crear();

	for (int i = 0; i < TAMP; i=i+2) {
		int dice_roll = distribution(generator);
		//std::cout << dice_roll << std::endl;
		for (int j = 0; j < NUMA; j++) {
			
			if (j <= dice_roll) {
				desendencia[i][j] = poblacion[i][j];
				desendencia[i + 1][j] = poblacion[i+1][j];
			}
			else {
				desendencia[i][j] = poblacion[i + 1][j];
				desendencia[i + 1][j] = poblacion[i][j];
			}


		}
	}
	
	//display(poblacion);
	//display(desendencia);
	return desendencia;



}

int ** mutacion(int ** desendencia){

	float individuos_mutados = TAMP * .1;
	int ** mutantes = Crear();
	for (int cont = 0; cont < round(individuos_mutados); cont++) {
	
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution1(0, TAMP-1);
		int dice_roll = distribution1(generator);
		std::uniform_int_distribution<int> distribution2(0, NUMA - 1);
		int dice_roll2 = distribution2(generator);

		desendencia[dice_roll][dice_roll2] = desendencia[dice_roll][dice_roll2] ^ 1;

		

	}
	return desendencia;




}

void AG_Ruleta(int ** poblacion_inicial) {

	int generaciones = NUMG;
	int **  padres;
	int ** desendencia;
	float * lista_de_maximos = (float*)malloc(sizeof(float)*NUMG);
	float * lista_de_minimos = (float*)malloc(sizeof(float)*NUMG);
	int ** nueva_poblacion = poblacion_inicial;
	std::cout << "NO. MAX//MIN" << std::endl;
	//display(poblacion_inicial);
	for (int i = 0; i < generaciones; i++) {
		padres = seleccion_padres(Ruleta(aptitud(nueva_poblacion)), nueva_poblacion);
		//display(padres);
		desendencia = punto_de_cruza(padres);
		//display(desendencia);
		nueva_poblacion = mutacion(desendencia);
		//display(nueva_poblacion);
		lista_de_maximos[i] =maximo( aptitud(nueva_poblacion));
		lista_de_minimos[i] = minimo(aptitud(nueva_poblacion));

		std::cout << i+1<< ".- "<<lista_de_maximos[i] <<"//"<< lista_de_minimos[i]<<std::endl;
		//display(nueva_poblacion);
	}
	//display(nueva_poblacion);
	 graficar(2, lista_de_maximos,lista_de_minimos);

	

}

int ** Crear() {
	int ** creacion;
	creacion = (int **)malloc(sizeof(int*)*TAMP);
	for (int i = 0; i < TAMP; i++) {
		creacion[i] = (int *)malloc(sizeof(int)*NUMA);
	}
	return creacion;
}

void display(int ** disp) {

	std::cout << "********" << std::endl;
	for (int i = 0; i < TAMP; i++) {
		
		for (int j = 0; j < NUMA; j++) {

			std::cout << disp[i][j];
		}
		std::cout << std::endl;
	}

}
