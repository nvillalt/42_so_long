/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:03 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 09:13:11 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_parsemap **mapinf, int x, int y)
{
	int	wall;

	wall = '1';
	if ((*mapinf)->map[x][y] == wall || (*mapinf)->map[x][y] == 'A')
		return ;
	if ((*mapinf)->map[x][y] == 'C')
		(*mapinf)->obj_check++;
	if ((*mapinf)->map[x][y] == 'E')
		(*mapinf)->exit_check++;
	(*mapinf)->map[x][y] = 'A';
	flood_fill(mapinf, x, (y + 1));
	flood_fill(mapinf, x, (y - 1));
	flood_fill(mapinf, (x + 1), y);
	flood_fill(mapinf, (x - 1), y);
}

static int	check_exit_player(t_parsemap **mapinf)
{
	int	x;
	int	y;

	x = 0;
	while ((*mapinf)->map[x])
	{
		y = 0;
		while ((*mapinf)->map[x][y])
		{
			if ((*mapinf)->map[x][y] == 'P')
			{
				(*mapinf)->player.x = x;
				(*mapinf)->player.y = y;
			}
			if ((*mapinf)->map[x][y] == 'E')
			{
				(*mapinf)->exit.x = x;
				(*mapinf)->exit.y = y;
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	validate_map(t_parsemap **mapinf)
{
	check_exit_player(mapinf);
	flood_fill(mapinf, (*mapinf)->player.x, (*mapinf)->player.y);
	if ((*mapinf)->obj != (*mapinf)->obj_check)
		return (error_message_parse(5, *mapinf));
	if ((*mapinf)->exit_num != (*mapinf)->exit_check)
		return (error_message_parse(5, *mapinf));
	return (1);
}
