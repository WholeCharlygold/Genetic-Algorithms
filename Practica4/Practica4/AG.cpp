#include "main.h"
extern "C" {
#include "mainc.h"
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
		padres = seleccion_padres(Torneo(poblacion_inicial), nueva_poblacion);
		//display(padres);
		desendencia = punto_de_cruza(padres);
		//display(desendencia);
		nueva_poblacion = mutacion(desendencia);
		//display(nueva_poblacion);
		lista_de_maximos[i] =maximo_float( probabilidad(nueva_poblacion))*100;
		lista_de_minimos[i] = minimo_float(probabilidad(nueva_poblacion)) * 100;
		//display(nueva_poblacion);
		std::cout << i+1<< ".- "<<lista_de_maximos[i] <<"//"<< lista_de_minimos[i]<<std::endl;
	
	}
	//display(nueva_poblacion);
	 graficar(2, lista_de_maximos,lista_de_minimos,maximo_de_maximos(lista_de_maximos));

	

}



