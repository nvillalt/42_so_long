/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/19 13:12:25 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_graph *mlx, t_sprites *sprites)
{
	int	x;
	int	y;

	x = PXL;
	y = PXL;
	// Mirar si alguno es nulo y luego si no, liberar todo
	sprites->wall = mlx_xpm_file_to_image(mlx->mlx, GRASS, &x, &y);
	sprites->floor = mlx_xpm_file_to_image(mlx->mlx, PATH, &x, &y);
	sprites->apple = mlx_xpm_file_to_image(mlx->mlx, APPLE, &x, &y);
	sprites->exit_cl = mlx_xpm_file_to_image(mlx->mlx, ROCK, &x, &y);
	sprites->exit_op = mlx_xpm_file_to_image(mlx->mlx, MASK, &x, &y);
	sprites->crash_f = mlx_xpm_file_to_image(mlx->mlx, CRASHFRONT, &x, &y);
	sprites->crash_b = mlx_xpm_file_to_image(mlx->mlx, CRASHBACK, &x, &y);
	sprites->crash_l = mlx_xpm_file_to_image(mlx->mlx, CRASHLEFT, &x, &y);
	sprites->crash_r = mlx_xpm_file_to_image(mlx->mlx, CRASHRIGHT, &x, &y);
	return ;
}

void	init_image(t_graph *mlx, t_sprites *sprites)
{
	int	i;
	int	j;

	load_sprites(mlx, sprites);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
			
		while (mlx->map[i][j])
		{
			printf("%s\n", mlx->map[i]);
			if (mlx->map[i][j] == '1')
			{
				printf("------%s\n", mlx->map[i]);
				printf("%s\n", sprites->wall);
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->wall,  (i * PXL), (j * PXL));
				printf(".......%s\n", mlx->map[i]);
			}
			else if (mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->floor, i * PXL, j * PXL);
			else if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->exit_cl, i * PXL, j * PXL);
			else if (mlx->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->crash_r, i * PXL, j * PXL);
			else if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->apple, i * PXL, j * PXL);
			j++;
		}
		i++;
	}
	return ;
}
void	start_game(t_parsemap *map, t_graph *mlx)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
		return ;
	mlx->mlx = mlx_init();
	if (!mlx->mlx) // Liberaciones de memoria y volver
		return ;
	mlx->win = mlx_new_window(mlx->mlx, (map->win_x * PXL), (map->win_y * PXL), "so_long");
	if (!mlx->win)
		return ;
	init_image(mlx, sprites);
	// Destroy hook
	// Keys hook
	mlx_loop(mlx->mlx);
}

	// mlx_destroy_window((*mlx)->mlx, (*mlx)->win); // Al terminar
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente