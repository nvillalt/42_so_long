/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 20:54:36 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_graphics(t_graph **mlx)
{
	(*mlx)->sprites->wall = 
	return ;
}

void	init_window(t_parsemap **map, t_graph **mlx)
{
	// es (*mlx)->mlx o (*mlx).mlx ???
	(*mlx)->mlx = mlx_init();
	if (!(*mlx)->mlx)
		return ;
	(*mlx)->win = mlx_new_window((*mlx)->mlx, ((*map)->win_x * 100), ((*map)->win_y * 100), "so_long");
	if (!(*mlx)->win)
		return ;
	(*mlx)->sprites = malloc(sizeof(t_sprites));
	if (!(*mlx)->sprites)
		return ;
	load_graphics(mlx);
	mlx_loop((*mlx)->mlx);
	return ;
}

	// mlx_destroy_window((*mlx)->mlx, (*mlx)->win); // Al terminar
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente