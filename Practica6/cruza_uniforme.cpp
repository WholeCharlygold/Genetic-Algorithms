
#include "main.h"
void display(int *disp1, int *disp2, int lista1[NUMA/2], int lista2[NUMA/2]);
int **cruza_uniforme();

using namespace std;
int **poblacion;
std::array<int, NUMA> aux;


int main()
{
    std::cout << "********" << std::endl;
    std::cout << "Poblacion"
              << " \tDescendencia"
              << "\tPuntos" << endl;
    llenar_array();
    poblacion = crearpoblacion();
    cruza_uniforme();

    return 0;
}

int **cruza_uniforme()
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    int lista1_index[NUMA/2];
    int lista2_index[NUMA/2];
    

    std::uniform_int_distribution<int> distribution(0, NUMA - 1);

    int j = 0;

    int **desendencia = Crear();

    for (int i = 0; i < TAMP; i = i + 2)
    {
        shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));

        for (int i = 0; i < aux.size() / 2; i++)
        {
            lista1_index[i] = aux[i];
            lista2_index[i] = aux[i + aux.size() / 2];
        }
        /* print_array(lista1_index);
        cout<<",";
        print_array(lista2_index);
        cout<<endl;*/
        
            for (int contador = 0; contador < NUMA/2; contador++)
            {
                desendencia[i][lista1_index[contador]-1] = poblacion[i][lista1_index[contador]-1];

                desendencia[i][lista2_index[contador]-1] = poblacion[i + 1][lista2_index[contador]-1];

                desendencia[i+1][lista1_index[contador]-1]=poblacion[i+1][lista1_index[contador]-1];
                desendencia[i+1][lista2_index[contador]-1]=poblacion[i][lista2_index[contador]-1];
            }
        
        display(poblacion[i], desendencia[i], lista1_index, lista2_index);
        display(poblacion[i + 1], desendencia[i + 1], lista1_index, lista2_index);
    }

    return desendencia;
}
void display(int *disp1, int *disp2, int lista1[NUMA/2], int lista2[NUMA/2])
{

    for (int j = 0; j < NUMA; j++)
    {

        //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
        std::cout << disp1[j];
    }
    std::cout << "\t \t";
    for (int j = 0; j < NUMA; j++)
    {

        //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
        std::cout << disp2[j];
    }
    std::cout << " \t\t";
    for (int j = 0; j < NUMA / 2; j++)
    {

        //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
        std::cout << lista1[j];
    }
    std::cout << ",";
    for (int j = 0; j < NUMA / 2; j++)
    {

        //std::cout << disp1[i][j]<<" "<<disp2[i][j]<<" "<<puntos[i] <<std::endl;
        std::cout << lista2[j];
    }
    std::cout << std::endl;
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

int maximo(int a, int b)
{

    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int minimo(int a, int b)
{

    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void llenar_array()
{
    for (int i = 0; i < NUMA; i++)
    {
        aux[i] = i + 1;
    }
}

void print_array(std::array<int, NUMA / 2> array)
{
    for (int i = 0; i < NUMA / 2; i++)
    {
        cout << array[i];
    }
}