/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:08:38 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/26 20:05:29 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		exit_check(t_graphics *graphs)
{
	
	return (1);
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
	printf("---->in key hook: %p\n", graphs);
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