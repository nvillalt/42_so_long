/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 20:44:23 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
https://en.wikipedia.org/wiki/Flood_fill

El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un
muro, C para un coleccionable, E para salir del mapa y P para la posición inicial
del jugador.
Este es un ejemplo simple de un mapa válido:
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

El mapa debe tener una salida, al menos un objeto y una posición inicial.
*/

// Tu programa debe aceptar como primer argumento un archivo con la descripción
// del mapa de extensión .ber

/*	Struct global y structs especificas para todo:
	- 
	*/
// SI SE LE PASA UN ARCHIVO QUE NO EXISTE O VACÍO DA SEGFAULT, PROTEGER
int	main(int argc, char **argv)
{
	t_parsemap	*map_info;
	t_graph		*map_graphs;

	map_info = NULL;
	if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == false)
	{
		write(1, "Wrong extension or arg amount.\n", 31);
		return (EXIT_FAILURE);
	}
	map_info = init_struct(); // Inicializado aquí pero algunas asignaciones de memoria se harán en otros puntos, cuidado con eso (cuidado con la doble matriz)
	map_graphs = init_graph(); // Inicializado aquí pero asignada la memoria de la matriz dentro de parse.c
	parse_map(argv[1], &map_info, &map_graphs);
	init_window(&map_info, &map_graphs);
	//	init_graphics(&map);
	//free(map_info);
	//system("leaks -q so_long");
	return (0);
}

/*
	void	*mlx;
	void	*window;

 	mlx = mlx_init();
	if (mlx)
		return (1);
	window = mlx_new_window (mlx, 1080, 720, "window");
	if (!window)
		return(1);
	mlx_loop (mlx);
	mlx_destroy_window (mlx, window);
	free (mlx); // liberar el puntero que inicializa la mlx cuando se termine */

/* 	void	*mlx;
	void	*window;

 	mlx = mlx_init();
	if (mlx)
		return (1);
	window = mlx_new_window (mlx, 1080, 720, "window");
	if (!window)
		return(1);
	mlx_loop (mlx);
	mlx_destroy_window (mlx, window);
	free (mlx); // liberar el puntero que inicializa la mlx cuando se termine */