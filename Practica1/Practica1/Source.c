
#include "stdio.h" //Encabezados necesarios para el despliegue
#include "time.h"  //de los graficos.
#include "plot.h"
#include "llist.h"
#include "stdlib.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("usage: %s font file name (.ttf)\n", argv[0]); 
		return EXIT_FAILURE; //Se carga el formato de letra.
	}



	int a[10]; //Se crea el arreglo de numeros
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		a[i] = rand()%50; //Se llena el arreglo de forma aleatoria.
	}

	//Se crea el label con los datos.
	captionlist caption_list = NULL;

	caption_list = push_back_caption(caption_list, "Linea de puntos", 0, 0x0000FF);


	//Se crean los puntos que tendra el histrograma en una lista de puntos.
	coordlist coordinate_list = NULL;

	for (int i = 0; i < 10; i++) {
		coordinate_list = push_back_coord(coordinate_list, 0, i, a[i]);

	}



	//print_list_coord(coordinate_list);

	//Se llenan las propiedades que va a tener el histograma.
	plot_params params;

	params.screen_width = 800; //Ancho
	params.screen_heigth = 640; //Alto
	params.plot_window_title = "Histograma"; //label de la ventana
	params.font_text_path = argv[1];
	params.font_text_size = 15; //Numero de letra
	params.caption_text_x = "X"; //Label del eje X
	params.caption_text_y = "Y"; //Label del eje Y
	params.caption_list = caption_list; //Se le pasa la lista de label que creamos antes
	params.coordinate_list = coordinate_list; //Se le pasa la lista de puntos
	params.scale_x = 1; //Escala del eje X
	params.scale_y = 5; //Escala del eje Y
	params.max_x = 10; //Maximo del eje X
	params.max_y = 50; //Maxicmo del eje Y

	int ret = plot_graph(&params); //Inicia el histograma

	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n", ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}