#include "main.h"

void display(int **poblacion)
{
    for (int i = 0; i < TAMP; i++)
    {
        for (int j = 0; j < NUMA; j++)
        {
            std::cout << poblacion[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void shuffle(int *individuo)
{

    unsigned seed = rand();

    std::shuffle(individuo, individuo + NUMA, std::default_random_engine(seed));
    //hola
}

int *hacer_individuo()
{
    int *individuo = (int *)malloc(sizeof(int) * NUMA);

    for (int i = 0; i < NUMA; i++)
    {
        individuo[i] = i + 1;
    }

    shuffle(individuo);

    return individuo;
}

int **hacer_poblacion()
{
    int **poblacion = (int **)malloc(sizeof(int *) * TAMP);

    for (int i = 0; i < TAMP; i++)
    {
        poblacion[i] = (int *)malloc(sizeof(int) * NUMA);
    }
    for (int i = 0; i < TAMP; i++)
    {
        poblacion[i] = hacer_individuo();
    }

    return poblacion;
}
int min_between_two_numbers(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int max_between_two_numbers(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int **llenar()
{
    int **jar = (int **)malloc(sizeof(int *) * TAMP);
    for (int i = 0; i < TAMP; i++)
    {
        jar[i] = (int *)malloc(sizeof(int) * NUMA);
    }
    return jar;
}
int esta_ono_esta(int *sujeto, int elemento, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        if (sujeto[i] == elemento)
            return i;
    }
    return -1;
}
int si_esta(int sujeto[], int elemento, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        if (sujeto[i] == elemento)
            return i;
    }
    return -1;
}