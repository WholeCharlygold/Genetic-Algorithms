#include "main.h"
extern "C" {
#include "mainc.h"
}



int * valor(int ** poblacion) {
	int * resultado;
	int valor_x = 0;
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

float * aptitud(int ** poblacion) {

	float * resultado;
	int * x = valor(poblacion);
	resultado = (float *)malloc(sizeof(float)*TAMP);


	for (int i = 0; i < TAMP; i++) {
		float rad = x[i] * PI / 180;
		resultado[i] = abs((x[i]-5)/(2+sin(rad))); //APTITUD F(X)
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
float maximo_de_maximos(float * aptitud) {
	float max_value;
	max_value = *std::max_element(aptitud, aptitud + NUMG);
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

int * Ruleta(float * fitness, int ** poblacion_inicial) {

	float* probabilidad;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<float> distribution(0.00f, TAMP);
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
		//probabilidad[i] = fitness[i] / suma;

		probabilidad[i] = valor_esperado(poblacion_inicial)[i];
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

	for (int i = 0; i < TAMP; i = i + 2) {
		int dice_roll = distribution(generator);
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

	//display(poblacion);
	//display(desendencia);
	return desendencia;



}

int ** mutacion(int ** desendencia) {

	float individuos_mutados = TAMP * MUTA;
	int ** mutantes = Crear();
	//display(desendencia);
	srand(time(NULL));

	for (int cont = 0; cont < round(individuos_mutados); cont++) {

		int dice_roll = std::rand() % (TAMP - 1) + 1;
		
		int dice_roll2 = std::rand() % (NUMA - 1) + 1;

		desendencia[dice_roll][dice_roll2] = desendencia[dice_roll][dice_roll2] ^ 1;
		//std::cout << dice_roll << "-" << dice_roll2 << std::endl;


	}
	//display(desendencia);
	return desendencia;




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

int * Torneo(int ** poblacion_inicial) {

	int * index = (int *)malloc(sizeof(int)*TAMP);
	int k=0;
	for (int j = 0;j < 2; j++) {
		int ** baraja = barajeo(poblacion_inicial);
		float * fitness = aptitud(baraja);
		srand(time(NULL));

		for (int i = 0; i < TAMP; i = i + 2) {

			int dice_roll = std::rand() % 100 + 1;
			if (dice_roll >= PROB) {
				if (fitness[i] >= fitness[i + 1]) {
					index[k] = i;
					k++;
				}
				else {
					index[k] = i + 1;
					k++;
				}
			}
			else {
				if (fitness[i] >= fitness[i + 1]) {
					index[k] = i +1;
					k++;
				}
				else {
					index[k] = i;
					k++;
				}
			}
		}
		
	}
	

	return index;
	
}

int ** barajeo(int ** poblacion_inicial) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(poblacion_inicial, poblacion_inicial + TAMP, std::default_random_engine(seed));

	return poblacion_inicial;

}


float * valor_esperado(int ** poblacion_inicial) {

	float * valor = (float *)malloc(sizeof(float)*TAMP);
	hierarchy * lista_ordenada = jerarquia(poblacion_inicial);

	for (int i = 0; i < TAMP; i++) {
		for (int j = 0; j < TAMP; j++) {
			if (lista_ordenada[j].pos == i ){
				float aux = (MAX - MIN)*((float)j / (TAMP - 1));
			valor[i] = MIN + ( MAX - MIN)*( (float)j / (TAMP - 1));
//			std::cout << valor[i]<<" " <<  (TAMP - 1) << "  "<<MIN << std::endl;
			}
			
		}
		
	}

	return valor;
}

hierarchy *  jerarquia(int ** poblacion_inicial) {


	hierarchy * lista_ordenada = (hierarchy*)malloc(sizeof(hierarchy)*TAMP);
	float * aux = (float *)malloc(sizeof(float)*TAMP);
	aux = aptitud(poblacion_inicial);

	

	for (int i = 0; i < TAMP; i++) {
		lista_ordenada[i].pos = i;
		lista_ordenada[i].fitness = aux[i];
	}

	float temp = 0;
	int contador = 0;
	int j = 0;

	for (int i = 1; i < TAMP; i++) {
		temp = lista_ordenada[i].fitness ;
		contador = lista_ordenada[i].pos;
		j = i - 1;
		while ((lista_ordenada[j].fitness  > temp) && (j >= 0)) {
			lista_ordenada[j + 1].fitness  = lista_ordenada[j].fitness ;
			lista_ordenada[j + 1].pos = lista_ordenada[j].pos;
			j--;
		}
		lista_ordenada[j + 1].fitness  = temp;
		lista_ordenada[j + 1].pos = contador;
	}
	/*for (int i = 0; i < TAMP; i++) {
		std::cout << lista_ordenada[i].pos <<"  "<<lista_ordenada[i].fitness << std::endl;
	}*/
	
	
	return lista_ordenada;
}




