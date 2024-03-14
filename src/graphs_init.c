/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 20:24:15 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_graphs(t_parsemap **map, t_graph **mlx)
{
	// es (*mlx)->mlx o (*mlx).mlx ???
	(*mlx)->mlx = mlx_init();
	if (!(*mlx)->mlx)
		return (false);
	(*mlx)->win = mlx_new_window((*mlx)->mlx, ((*map)->win_x * 100), ((*map)->win_y * 100), "so_long");
	if (!(*mlx)->win)
		return (false);
	
	mlx_loop((*mlx)->mlx);
	return (true);
}

	// mlx_destroy_window((*mlx)->mlx, (*mlx)->win); // Al terminar
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente