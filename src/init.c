/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:32 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 20:52:16 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_parsemap	*init_struct(void)
{
	t_parsemap	*map_info;

	map_info = malloc(sizeof(t_parsemap));
	if (!map_info)
		error_message(20);
	map_info->win_x = -1;
	map_info->win_y = -1;
	map_info->fd = 0;
	map_info->map = NULL;
	map_info->collectables = 0;
	map_info->collectables_check = 0;
	map_info->exit_num = 0;
	map_info->exit_check = 0;
	map_info->player_num = 0;
	return (map_info);
}

t_graph	*init_graph(void)
{
	t_graph	*mlx_map;

	mlx_map = malloc(sizeof(mlx_map));
	if (!mlx_map)
		return (NULL);
	mlx_map->map = NULL;
	mlx_map->mlx = NULL;
	mlx_map->win = NULL;
	mlx_map->movements = 0;
	//mlx_map->sprites = NULL;
	return (mlx_map);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->movements = 0;
	player->collectables = 0;
	return (player);
}
