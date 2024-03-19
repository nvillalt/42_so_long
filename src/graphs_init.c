/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/19 20:03:29 by nvillalt         ###   ########.fr       */
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
	// Proteger esta función
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
	j = 0;
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->wall,  i * PXL, j * PXL);
			else if (mlx->map[j][i] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->floor, i * PXL, j * PXL);
			else if (mlx->map[j][i] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->exit_cl, i * PXL, j * PXL);
			else if (mlx->map[j][i] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->crash_r, i * PXL, j * PXL);
			else if (mlx->map[j][i] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->apple, i * PXL, j * PXL);
			i++;
		}
		j++;
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
	mlx_key_hook(mlx->win, &key_hook, mlx);
	//mlx_destroy_display(mlx->mlx);
	// Keys hook
	mlx_loop(mlx->mlx);
}

	// mlx_destroy_window((*mlx)->mlx, (*mlx)->win); // Al terminar
	// mlx_destroy_image()
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente