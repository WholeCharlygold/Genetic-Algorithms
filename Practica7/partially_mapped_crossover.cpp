#include "main.h"

int *doble_punto_cruza(int *individuo, int a, int b);
cadena sub_cadena(int *individuo, int a, int b);
int *completar(int *individuo, cadena chain, cadena chain2);
int *mapear(int *cruza, int *individuo, cadena chain2);

int main()
{
    srand(time(NULL));
    int **poblacion;
    int **nueva_poblacion;
    nueva_poblacion = llenar();
    poblacion = hacer_poblacion();
    
    for (int i = 0; i < TAMP; i = 2 + i)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distribution(0, NUMA - 1);
        int dice_roll = distribution(generator);
        int dice_roll2 = distribution(generator);
        while (dice_roll == dice_roll2)
        {
            dice_roll2 = distribution(generator);
        }

        nueva_poblacion[i] = doble_punto_cruza(poblacion[i + 1], dice_roll, dice_roll2);
        cadena chain = sub_cadena(poblacion[i + 1], dice_roll, dice_roll2);
        cadena chain2 = sub_cadena(poblacion[i], dice_roll, dice_roll2);
        nueva_poblacion[i] = mapear(nueva_poblacion[i], poblacion[i], chain);
        nueva_poblacion[i] = completar(nueva_poblacion[i], chain, chain2);

         nueva_poblacion[i+1] = doble_punto_cruza(poblacion[i], dice_roll, dice_roll2);
       chain = sub_cadena(poblacion[i], dice_roll, dice_roll2);
        chain2 = sub_cadena(poblacion[i+1], dice_roll, dice_roll2);
        nueva_poblacion[i+1] = mapear(nueva_poblacion[i+1], poblacion[i+1], chain);
        nueva_poblacion[i+1] = completar(nueva_poblacion[i+1], chain, chain2);
    }

    std::cout<<"Poblacion inicial"<<std::endl;
    display(poblacion);
    std::cout<<std::endl;
    std::cout<<"Nueva Poblacion"<<std::endl;
    display(nueva_poblacion);
    return 0;
}
int *completar(int *individuo, cadena chain, cadena chain2)
{
    int *hijo;
    hijo = (int *)malloc(sizeof(int) * NUMA);
    int contador = 0;
    for (int i = 0; i < NUMA; i++)
    {
        if (individuo[i] == -1)
        {
            if (esta_ono_esta(chain.elements, chain2.elements[contador], chain.tam) == -1)
            {
                hijo[i] = chain2.elements[contador];
                contador++;
            }
            else
            {
                contador++;
                for (int j = contador; j < chain2.tam; j++)
                {
                    if (esta_ono_esta(chain.elements, chain2.elements[j], chain.tam) == -1)
                    {
                        hijo[i] = chain2.elements[j];
                        contador=j;
                        contador++;
                        break;
                    }
                }
            }
        }
        else
            hijo[i] = individuo[i];
    }
    return hijo;
}
int *mapear(int *cruza, int *individuo, cadena chain)
{

    int *hijo = (int *)malloc(sizeof(int) * NUMA);

    for (int i = 0; i < NUMA; i++)
    {
        if (cruza[i] == -1)
        {
            if (si_esta(chain.elements, individuo[i], chain.tam) == -1)
                hijo[i] = individuo[i];
            else
                hijo[i] = -1;
        }
        else
        {
            hijo[i] = cruza[i];
        }
    }
    return hijo;
}

int *doble_punto_cruza(int *individuo, int a, int b)
{
    int *hijo = (int *)malloc(sizeof(int) * NUMA);
    int min = min_between_two_numbers(a, b);
    int max = max_between_two_numbers(a, b);
    for (int i = 0; i < NUMA; i++)
    {
        if (min <= i && i < max)
        {
            hijo[i] = individuo[i];
        }
        else
        {
            hijo[i] = -1;
        }
    }
    return hijo;
}
cadena sub_cadena(int *individuo, int a, int b)
{
    cadena chain;

    chain.tam = abs(a - b);
    chain.elements = (int *)malloc(sizeof(int) * chain.tam);
    int *hijo = (int *)malloc(sizeof(int) * NUMA);
    int min = min_between_two_numbers(a, b);
    int max = max_between_two_numbers(a, b);
    int contador = 0;
    for (int i = 0; i < NUMA; i++)
    {
        if (min <= i && i < max)
        {
            chain.elements[contador] = individuo[i];
            contador++;
        }
    }
    return chain;
}