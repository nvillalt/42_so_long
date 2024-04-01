/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:08:38 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/01 20:43:51 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_graphics *graphs)
{
	mlx_destroy_window(graphs->ptr, graphs->win);
	system("leaks -q so_long");
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_exit(t_graphics *graphs)
{
	int	p_x;
	int p_y;
	int	exit_x;
	int	exit_y;

	p_x = graphs->parse_info->player.x;
	p_y = graphs->parse_info->player.y;
	exit_x = graphs->parse_info->exit.x;
	exit_y = graphs->parse_info->exit.y;
	if (graphs->parse_info->collectables == 0)
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->exit_op,  exit_y * PXL, exit_x * PXL);
	if (graphs->parse_info->clean_map[p_x][p_y] == 'E' && graphs->parse_info->collectables == 0)
		close_program(graphs);
	return ;
}

int		key_hook(int key, t_graphics *graphs)
{
	if (key == ESC || key == KEY_Q)
		close_program(graphs);
	else if (key == KEY_A || key == KEY_LEFT)
		move_character_A(graphs);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_character_D(graphs);
	else if (key == KEY_S || key == KEY_DOWN)
		move_character_S(graphs);
	else if (key == KEY_W || key == KEY_UP)
		move_character_W(graphs);
	return (0);
}