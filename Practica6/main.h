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
#define TAMP 10
#define REPR 1
#define NUMA 8
#define PI  3.14159265358979323846
#define PROB 70 //Probabildiad de torneno  0.7<p<1
#define MUTA .1 // Mutacion 
#define MAX 1.1
#define MIN .9 //2-MAX
struct numero{
int bit;
char cruza;
};

int ** Crear();
void print_array(std::array<int,NUMA/2> array);
int **  crearpoblacion();
struct numero** nuevo();

int maximo(int,int);
int minimo(int a, int b);
void llenar_array();