/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:32 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/22 19:43:19 by nvillalt         ###   ########.fr       */
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
	map_info->clean_map = NULL;
	map_info->collectables = 0;
	map_info->exit_num = 0;
	map_info->player_num = 0;
	map_info->exit_check = 0;
	map_info->collectables_check = 0;
	return (map_info);
}


t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->movements = 0;
	player->collectables = 0;
	return (player);
}
