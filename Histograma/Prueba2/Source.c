/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Bertrand Martel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 /**
	 main.c
	 testing plot-sdl-lib : create a new SDL window, plot points in a created graph featuring a cartesian coordinate system
	 @author Bertrand Martel
	 @version 0.1
 */
#include "stdio.h"
#include "plot.h"
#include "llist.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("usage: %s font file name (.ttf)\n", argv[0]);
		return EXIT_FAILURE;
	}

	int a[10] = { 10,2,8,15,30,29,45,1,5,4 };

	//populate caption list
	captionlist caption_list = NULL;

	caption_list = push_back_caption(caption_list, "Linea de puntos", 0, 0x0000FF);

	//print_list_caption(caption_list);

	//populate coordinate list
	coordlist coordinate_list = NULL;

	for (int i = 0; i < 10; i++) {
		coordinate_list = push_back_coord(coordinate_list, 0, i, a[i]);

	}
	
	

	//print_list_coord(coordinate_list);

	//populate plot parameter object
	plot_params params;

	params.screen_width = 800;
	params.screen_heigth = 640;
	params.plot_window_title = "Histograma";
	params.font_text_path = argv[1];
	params.font_text_size = 15;
	params.caption_text_x = "X";
	params.caption_text_y = "Y";
	params.caption_list = caption_list;
	params.coordinate_list = coordinate_list;
	params.scale_x = 1;
	params.scale_y = 5;
	params.max_x = 10;
	params.max_y = 50;

	int ret = plot_graph(&params);

	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n", ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}