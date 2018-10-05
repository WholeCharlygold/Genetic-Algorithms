

#include "stdio.h" //Encabezados necesarios para el despliegue
#include "time.h"  //de los graficos.
#include "plot.h"
#include "llist.h"
#include "stdlib.h"
#include "mainc.h"




int graficar(int argc, float *maximos, float * minimos)
{
	if (argc != 2)
	{
		printf("usage: %s font file name (.ttf)\n", "opensans.ttf");
		return EXIT_FAILURE; //Se carga el formato de letra.
	}




	//Se crea el label con los datos.
	captionlist caption_list = NULL;


	caption_list= push_back_caption(caption_list, "Maximos", 0, 0x0000FF);
	caption_list = push_back_caption(caption_list,"Minimos", 1, 0xFF0000);


	//Se crean los puntos que tendra el histrograma en una lista de puntos.
	coordlist coordinate_list = NULL;

	for (int i = 0; i < NUMG; i++) {
		coordinate_list = push_back_coord(coordinate_list, 0, i, maximos[i]);
		coordinate_list = push_back_coord(coordinate_list, 1, i, minimos[i]);

	}



	//print_list_coord(coordinate_list);

	//Se llenan las propiedades que va a tener el histograma.
	plot_params params;

	params.screen_width = 800; //Ancho
	params.screen_heigth = 640; //Alto
	params.plot_window_title = "Histograma"; //label de la ventana
	params.font_text_path = "opensans.ttf";
	params.font_text_size = 11; //Numero de letra
	params.caption_text_x = "Generaciones"; //Label del eje X
	params.caption_text_y = "Aptitud"; //Label del eje Y
	params.caption_list = caption_list; //Se le pasa la lista de label que creamos antes
	//params.caption_list = caption_list_min; //Se le pasa la lista de label que creamos antes
	params.coordinate_list = coordinate_list; //Se le pasa la lista de puntos
	params.scale_x = 1; //Escala del eje X
	params.scale_y = 100; //Escala del eje Y
	params.max_x = NUMG; //Maximo del eje X
	params.max_y =1000; //Maxicmo del eje Y

	int ret = plot_graph(&params); //Inicia el histograma

	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n", ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}