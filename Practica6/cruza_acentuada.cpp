
#include "main.h"
using namespace std;
struct numero **poblacion;
void display(struct numero **x, struct numero **y);
struct numero **cruza_acentuada();
struct numero **CrearAcentos();

int main()
{
    poblacion = nuevo();
    cruza_acentuada();

    return 0;
}

struct numero **cruza_acentuada()
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, NUMA - 1);
    int *puntos;
    int j = 0;
    int trigger = 0;
    puntos = (int *)malloc(sizeof(int) * TAMP);
    struct numero **desendencia = CrearAcentos();

    for (int i = 0; i < TAMP; i = i + 2)
    {

       trigger=0;

        //std::cout << dice_roll << std::endl;
        for (int j = 0; j < NUMA; j++)
        {
            if (trigger == 0)
            {

                desendencia[i][j] = poblacion[i][j];
                desendencia[i][j].cruza = NULL;
                desendencia[i + 1][j] = poblacion[i + 1][j];

                if (poblacion[i][j].cruza != NULL || poblacion[i + 1][j].cruza != NULL)
                {
                    trigger = 1;
                    desendencia[i + 1][j].cruza = '!';
                }

                else
                    desendencia[i + 1][j].cruza = NULL;
            }
            else
            {
                desendencia[i][j].bit = poblacion[i + 1][j].bit;
                desendencia[i][j].cruza = NULL;
                desendencia[i + 1][j].bit = poblacion[i][j].bit;
               
                if (poblacion[i][j].cruza != NULL || poblacion[i + 1][j].cruza != NULL)
                {
                    trigger = 0;
                    desendencia[i + 1][j].cruza = '!';
                }

                else
                    desendencia[i + 1][j].cruza = NULL;
            }
        }
    }
    display(poblacion, desendencia);
    return desendencia;
}
void display(struct numero **disp1, struct numero **disp2)
{

    std::cout << "********" << std::endl;
    std::cout << "Poblacion"
              << " \t\tDescendencia"
               << endl;
    for (int i = 0; i < TAMP; i++)
    {

        for (int j = 0; j < NUMA; j++)
        {

            //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
            std::cout << disp1[i][j].bit << disp1[i][j].cruza;
        }
        std::cout << " \t";
        for (int j = 0; j < NUMA; j++)
        {

            //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
            std::cout << disp2[i][j].bit << disp2[i][j].cruza;
        }
        std::cout << " \t\t";

        std::cout << std::endl;
    }
}

int **Crear()
{
    int **creacion;
    creacion = (int **)malloc(sizeof(int *) * TAMP);
    for (int i = 0; i < TAMP; i++)
    {
        creacion[i] = (int *)malloc(sizeof(int) * NUMA);
    }
    return creacion;
}

struct numero **CrearAcentos()
{
    struct numero **creacion;
    creacion = (struct numero **)malloc(sizeof(struct numero *) * TAMP);
    for (int i = 0; i < TAMP; i++)
    {
        creacion[i] = (struct numero *)malloc(sizeof(struct numero) * NUMA);
    }
    return creacion;
}