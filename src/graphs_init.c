/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:03 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	check_null_sprite(t_graphics *graphs)
{
	
} */

void	load_sprites(t_graphics *graphs, t_sprites *sprites)
{
	int	x;
	int	y;

	x = PXL;
	y = PXL;
	// Mirar si alguno es nulo/no existe el archivo y luego si no, liberar todo
	// Proteger esta función
	sprites->wall = mlx_xpm_file_to_image(graphs->ptr, GRASS, &x, &y);
	sprites->floor = mlx_xpm_file_to_image(graphs->ptr, PATH, &x, &y);
	sprites->apple = mlx_xpm_file_to_image(graphs->ptr, APPLE, &x, &y);
	sprites->exit_cl = mlx_xpm_file_to_image(graphs->ptr, ROCK, &x, &y);
	sprites->exit_op = mlx_xpm_file_to_image(graphs->ptr, MASK, &x, &y);
	sprites->crash_f = mlx_xpm_file_to_image(graphs->ptr, CRASHFRONT, &x, &y);
	sprites->crash_b = mlx_xpm_file_to_image(graphs->ptr, CRASHBACK, &x, &y);
	sprites->crash_l = mlx_xpm_file_to_image(graphs->ptr, CRASHLEFT, &x, &y);
	sprites->crash_r = mlx_xpm_file_to_image(graphs->ptr, CRASHRIGHT, &x, &y);

	return ;
}

void	init_image(t_graphics *graphs, t_sprites *sprites)
{
	int	i;
	int	j;

	load_sprites(graphs, sprites);
	j = 0;
	while (graphs->parse_info->clean_map[j])
	{
		i = 0;
		while (graphs->parse_info->clean_map[j][i])
		{
			if (graphs->parse_info->clean_map[j][i] == '1')
				mlx_put_image_to_window(graphs->ptr, graphs->win, sprites->wall, i * PXL, j * PXL);
			else if (graphs->parse_info->clean_map[j][i] == '0')
				mlx_put_image_to_window(graphs->ptr, graphs->win, sprites->floor, i * PXL, j * PXL);
			else if (graphs->parse_info->clean_map[j][i] == 'E')
				mlx_put_image_to_window(graphs->ptr, graphs->win, sprites->exit_cl, i * PXL, j * PXL);
			else if (graphs->parse_info->clean_map[j][i] == 'P')
				mlx_put_image_to_window(graphs->ptr, graphs->win, sprites->crash_r, i * PXL, j * PXL);
			else if (graphs->parse_info->clean_map[j][i] == 'C')
				mlx_put_image_to_window(graphs->ptr, graphs->win, sprites->apple, i * PXL, j * PXL);
			i++;
		}
		j++;
	}
	return ;
}

void	start_game(t_parsemap *map_info)
{
	t_sprites	*sprites;
	t_graphics	*graphs;

	graphs = malloc(sizeof(t_graphics));
	sprites = malloc(sizeof(t_sprites));
	if (!sprites || !graphs)
		return ;
	printf("--->function: %p\n", graphs);
	graphs->parse_info = map_info;
	graphs->sprites = sprites;
	graphs->ptr = mlx_init();
	if (!graphs->ptr)
		return ;
	graphs->win = mlx_new_window(graphs->ptr, (map_info->win_x * PXL), (map_info->win_y * PXL), "so_long");
	if (!graphs->win)
		return ;
	init_image(graphs, sprites);
	mlx_key_hook(graphs->win, &key_hook, graphs);
	mlx_hook(graphs->win, 17, 0, close_program, graphs);
	//mlx_destroy_display(graphs->ptr);
	mlx_loop(graphs->ptr);
}

	// mlx_destroy_window((*mlx)->mlx, (*mlx)->win); // Al terminar
	// mlx_destroy_image()
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente