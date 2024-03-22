/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:08:38 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/22 19:16:39 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	close_program(t_graph *mlx)
{
	close_program();
	return ;
} */

int		key_hook(int key, t_graph *mlx)
{
	if (key == ESC || key == KEY_Q)
		printf("Hola");
			//close_program(mlx);
/* 	else if (key == KEY_A || key == KEY_LEFT)
		move_character(key, mlx);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_character(key, mlx);
	else if (key == KEY_S || key == KEY_DOWN)
		move_character(key, mlx);
	else if (key == KEY_W || key == KEY_UP)
		move_character(key, mlx);
	return (0); */
}