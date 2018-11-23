#include "main.h"

int *ensamblar(cadena sous_chaine, int *individuo);
cadena sub_cadena(int *padre);
cadena sub_cadena_menos_padre(cadena sous_chaine, int *individuo);
int *producir_hijo(cadena sous_chaine, int *individuo);

int main()
{
    srand(time(NULL));
    int **poblacion;
    cadena sous_chaine;
    cadena sous_chaine2;
    int **nueva_poblacion;
    nueva_poblacion = llenar();
    poblacion = hacer_poblacion();

    for (int i = 0; i < TAMP; i = 2 + i)
    {
        sous_chaine = sub_cadena(poblacion[i]);
        nueva_poblacion[i] = producir_hijo(sous_chaine, poblacion[i]);
        sous_chaine2 = sub_cadena_menos_padre(sous_chaine, poblacion[i + 1]);
        nueva_poblacion[i] = ensamblar(sous_chaine2, nueva_poblacion[i]);
       
       sous_chaine=sub_cadena(poblacion[i+1]);
       nueva_poblacion[i+1]=producir_hijo(sous_chaine,poblacion[i+1]);
       sous_chaine2=sub_cadena_menos_padre(sous_chaine,poblacion[i]);
       nueva_poblacion[i+1]=ensamblar(sous_chaine2,nueva_poblacion[i+1]);
    }

    std::cout<<"Poblacion inicial"<<std::endl;
    display(poblacion);
    std::cout<<std::endl;
    std::cout<<"Nueva Poblacion"<<std::endl;
    display(nueva_poblacion);
    return 0;
}
int *ensamblar(cadena sous_chaine, int *individuo)
{
    int *hijo = (int *)malloc(sizeof(int) * NUMA);
    int contador = 0;
    for (int i = 0; i < NUMA; i++)
    {

        if (individuo[i] == -1)
        {
            hijo[i] = sous_chaine.elements[contador];
            contador++;
        }

        else
            hijo[i] = individuo[i];
    }
    return hijo;
}

cadena sub_cadena_menos_padre(cadena sous_chaine, int *individuo)
{
    cadena chain;
    chain.tam = NUMA - sous_chaine.tam;
    chain.elements = (int *)malloc(sizeof(int) * chain.tam);

    int contador = 0;
    int aux = 0;

    for (int k = 0; k < NUMA; k++)
    {
        aux = esta_ono_esta(sous_chaine.elements, individuo[k], sous_chaine.tam);
        if (aux == -1)
        {
            chain.elements[contador] = individuo[k];
            contador = contador + 1;
        }
    }

    return chain;
}



int *producir_hijo(cadena sous_chaine, int *individuo)
{
    int *hijo = (int *)malloc(sizeof(int) * NUMA);
    int contador = 0;
    for (int i = 0; i < NUMA; i++)
    {
        contador = 0;
        for (int j = 0; j < sous_chaine.tam; j++)
        {
            if (individuo[i] == sous_chaine.elements[j])
                hijo[i] = sous_chaine.elements[j];
            else
                contador++;
        }
        if (contador == sous_chaine.tam)
            hijo[i] = -1;
    }
    return hijo;
}


cadena sub_cadena(int *padre)
{
    cadena new_chain;
    new_chain.elements=(int * )malloc(sizeof(int)*3);
    new_chain.tam=3;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, NUMA - 1);
 

    for(int i=0;i<3;i++){
           new_chain.elements[i] = distribution(generator);
    }

    return new_chain;
}


