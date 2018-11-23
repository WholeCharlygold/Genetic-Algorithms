#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <random> //Libreria para la generacion de numeros aleatorios
#include <chrono>
#include <algorithm>
#include <vector>
#include <array>
#define TAMP 6
#define REPR 1
#define NUMA 10
#define PI  3.14159265358979323846
#define PROB 70 //Probabildiad de torneno  0.7<p<1
#define MUTA .1 // Mutacion 
#define MAX 1.1
#define MIN .9 //2-MAX
struct cadena{
    int tam;
    int * elements;
};
struct cadena_array{
    int tam;
    int elements[];
};

void display(int **poblacion);
int si_esta(int sujeto[], int elemento, int tam);
int *hacer_individuo();
int **hacer_poblacion();
void shuffle(int *individuo);
int *mapear(int *cruza, int *individuo, cadena_array chain);
int esta_ono_esta(int *sujeto, int elemento, int tam);
int **llenar();
int min_between_two_numbers(int a, int b);

int max_between_two_numbers(int a, int b);