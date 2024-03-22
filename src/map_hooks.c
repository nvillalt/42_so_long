/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:08:38 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/22 22:34:02 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_character_A(t_graphics *graphs)
{
	int	x;
	int	y;

	x = graphs->parse_info->player.x;
	y = graphs->parse_info->player.y;
	printf("\n%d\n%d\n", x, y);
	if (graphs->parse_info->clean_map[x][y - 1] != 1)
	{
		if (graphs->parse_info->clean_map[x][y - 1] == 'C')
		{
			graphs->parse_info->collectables--;
			graphs->parse_info->clean_map[x][y - 1] = '0';
		}
		graphs->parse_info->player.y -= 1;
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->floor,  y * PXL, x * PXL);
		if (graphs->parse_info->clean_map[x][y] == '0')
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->wall,  y * PXL, x * PXL);
		graphs->parse_info->player.movements += 1;
	}
	printf("Taps: %d\n", graphs->parse_info->player.movements);
}

void	close_program(t_graphics *graphs)
{
	mlx_destroy_window(graphs->ptr, graphs->win);
	system("leaks -q so_long");
	exit(EXIT_SUCCESS);
	return ;
}

int		key_hook(int key, t_graphics *graphs)
{
	printf("--> %d", key);
	if (key == ESC || key == KEY_Q)
		close_program(graphs);
	else if (key == KEY_A || key == KEY_LEFT)
		move_character_A(graphs);
/* 	else if (key == KEY_D || key == KEY_RIGHT)
		move_character_D(graphs, 'D');
	else if (key == KEY_S || key == KEY_DOWN)
		move_character_S(graphs, 'S');
	else if (key == KEY_W || key == KEY_UP)
		move_character_W(graphs, 'W'); */
	return (0);
}