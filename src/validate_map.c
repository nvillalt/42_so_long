/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:03 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 17:24:15 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Algoritmo de flood-fill

/* if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;
*/

void	flood_fill(t_parsemap **map_info, int x, int y)
{
	int	wall;

	wall = '1';
	if ((*map_info)->map[x][y] == wall || (*map_info)->map[x][y] == 'A')
		return ;
	if ((*map_info)->map[x][y] == 'C')
		(*map_info)->collectables_check++;
	if ((*map_info)->map[x][y] == 'E')
		(*map_info)->exit_check++;
	(*map_info)->map[x][y] = 'A';
/* 	int i = 0;
	while ((*map_info)->map[i])
	{
		printf("---> %s\n", (*map_info)->map[i]);
		i++;
	}
	printf("\n\n\n"); */
	flood_fill(map_info, x, (y + 1));
	flood_fill(map_info, x, (y - 1));
	flood_fill(map_info, (x + 1), y);
	flood_fill(map_info, (x - 1), y);
}

static bool  check_exit_player(t_parsemap **map_info)
{
	int	x;
	int	y;

	x = 0;
	while ((*map_info)->map[x])
	{
		y = 0;
		while ((*map_info)->map[x][y])
		{
			if ((*map_info)->map[x][y] == 'P')
			{
				(*map_info)->player.x = x;
				(*map_info)->player.y = y;
			}
			if ((*map_info)->map[x][y] == 'E')
			{
				(*map_info)->exit.x = x;
				(*map_info)->exit.y = y;
			}
			y++;
		}
		x++;
	}
  return (true);
}

bool	validate_map(t_parsemap **map_info)
{
	//int	i = 0;

	//i = 0;
	check_exit_player(map_info);
	printf("Coordenadas player: %d - %d\nCoordenadas exit: %d - %d\n-------\n", (*map_info)->player.x, (*map_info)->player.y, (*map_info)->exit.x, (*map_info)->exit.y);
	flood_fill(map_info, (*map_info)->player.x, (*map_info)->player.y);
	printf("Collectables check: %d\nExit check: %d\n", (*map_info)->collectables_check, (*map_info)->exit_check);
	if ((*map_info)->collectables != (*map_info)->collectables_check)
		return (error_message(5));
	if ((*map_info)->exit_num != (*map_info)->exit_check)
		return (error_message(5));
/* 	while ((*map_info)->map[i])
	{
		printf("---> %s\n", (*map_info)->map[i]);
		i++;
	} */
	return (true);
}