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
#define TAMP 32
#define REPR 1
#define NUMA 5


float * probabilidad(int ** poblacion);

float maximo_float(float * aptitud);
float minimo_float(float * aptitud);

int**  crearpoblacion();
int ** Crear();
void AG_Ruleta(int ** poblacion_inicial);
int * valor(int ** poblacion);
long long convertDecimalToBinary(int n);
int convertBinaryToDecimal(int * n);
int * aptitud(int ** poblacion);
int minimo(int * aptitud);
int * Ruleta(int * fitness);
int maximo(int * v);
int ** seleccion_padres(int * padres_index, int ** poblacion);
int ** punto_de_cruza(int ** poblacion);
int ** mutacion(int ** desendencia);
void display(int ** disp);












int ** binario(int **); //PROTOTIPOS
int ** gray(int **);
void real(float **);
int ** entero(int **);
void despliega(int **, float **);