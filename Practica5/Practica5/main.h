#pragma once

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <random> //Libreria para la generacion de numeros aleatorios
#include <chrono>
#include <algorithm>
#include <vector>
#define TAMP 16
#define REPR 1
#define NUMA 4
#define PI  3.14159265358979323846
#define PROB 70 //Probabildiad de torneno  0.7<p<1
#define MUTA .1 // Mutacion 
#define MAX 1.1
#define MIN .9 //2-MAX

struct hierarchy {
	float  fitness;
	int pos;
};



float * probabilidad(int ** poblacion);
int ** barajeo(int ** poblacion_inicial);
float maximo_float(float * aptitud);
float minimo_float(float * aptitud);
float maximo_de_maximos(float * aptitud);
int**  crearpoblacion();
int ** Crear();
void AG_Ruleta(int ** poblacion_inicial);
int * valor(int ** poblacion);
long long convertDecimalToBinary(int n);
int convertBinaryToDecimal(int * n);
float * aptitud(int ** poblacion);
int minimo(int * aptitud);
int * Ruleta(float * fitness, int ** poblacion_inicial);
int * Torneo(int ** poblacion_inicial);
int maximo(int * v);
int ** seleccion_padres(int * padres_index, int ** poblacion);
int ** punto_de_cruza(int ** poblacion);
int ** mutacion(int ** desendencia);
void display(int ** disp);
hierarchy *  jerarquia(int ** poblacion_inicial);
float * valor_esperado(int ** poblacion_inicial);












int ** binario(int **); //PROTOTIPOS
int ** gray(int **);
void real(float **);
int ** entero(int **);
void despliega(int **, float **);