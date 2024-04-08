/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:57:01 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/08 18:08:55 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_character_D(t_graphics *graphs)
{
	int	x;
	int	y;

	x = graphs->parse_info->player.x;
	y = graphs->parse_info->player.y;
	if (graphs->parse_info->clean_map[x][y + 1] != '1')
	{
		if (graphs->parse_info->clean_map[x][y] == '0' || graphs->parse_info->clean_map[x][y] == 'P')
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->floor,  y * PXL, x * PXL);
		if (graphs->parse_info->clean_map[x][y] == 'E' && graphs->parse_info->collectables != 0)
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->exit_cl,  y * PXL, x * PXL);
		graphs->parse_info->player.y += 1;
		y = graphs->parse_info->player.y;
		if (graphs->parse_info->clean_map[x][y] == 'C')
		{
			graphs->parse_info->collectables--;
			graphs->parse_info->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->crash_r,  y * PXL, x * PXL);
		graphs->parse_info->player.movements += 1;
	}
	printf("Taps: %d\n", graphs->parse_info->player.movements); //CAMBIAR POR FT_PRINTF
	check_exit(graphs);
}

void	move_character_A(t_graphics *graphs)
{
	int	x;
	int	y;

	x = graphs->parse_info->player.x;
	y = graphs->parse_info->player.y;
	if (graphs->parse_info->clean_map[x][y - 1] != '1')
	{
		if (graphs->parse_info->clean_map[x][y] == '0' || graphs->parse_info->clean_map[x][y] == 'P')
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->floor,  y * PXL, x * PXL);
		if (graphs->parse_info->clean_map[x][y] == 'E' && graphs->parse_info->collectables != 0)
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->exit_cl,  y * PXL, x * PXL);
		graphs->parse_info->player.y -= 1;
		y = graphs->parse_info->player.y;
		if (graphs->parse_info->clean_map[x][y] == 'C')
		{
			graphs->parse_info->collectables--;
			graphs->parse_info->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->crash_l,  y * PXL, x * PXL);
		graphs->parse_info->player.movements += 1;
	}
	printf("Taps: %d\n", graphs->parse_info->player.movements); //CAMBIAR POR FT_PRINTF
	check_exit(graphs);
}

void	move_character_W(t_graphics *graphs)
{
	int	x;
	int	y;

	x = graphs->parse_info->player.x;
	y = graphs->parse_info->player.y;
	if (graphs->parse_info->clean_map[x - 1][y] != '1')
	{
		if (graphs->parse_info->clean_map[x][y] == '0' || graphs->parse_info->clean_map[x][y] == 'P')
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->floor,  y * PXL, x * PXL);
		if (graphs->parse_info->clean_map[x][y] == 'E' && graphs->parse_info->collectables != 0)
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->exit_cl,  y * PXL, x * PXL);
		graphs->parse_info->player.x -= 1;
		x = graphs->parse_info->player.x;
		if (graphs->parse_info->clean_map[x][y] == 'C')
		{
			graphs->parse_info->collectables--;
			graphs->parse_info->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->crash_b,  y * PXL, x * PXL);
		graphs->parse_info->player.movements += 1;
	}
	printf("Taps: %d\n", graphs->parse_info->player.movements); //CAMBIAR POR FT_PRINTF
	check_exit(graphs);
}

void	move_character_S(t_graphics *graphs)
{
	int	x;
	int	y;

	x = graphs->parse_info->player.x;
	y = graphs->parse_info->player.y;
	if (graphs->parse_info->clean_map[x + 1][y] != '1')
	{
		if (graphs->parse_info->clean_map[x][y] == '0' || graphs->parse_info->clean_map[x][y] == 'P')
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->floor,  y * PXL, x * PXL);
		if (graphs->parse_info->clean_map[x][y] == 'E' && graphs->parse_info->collectables != 0)
			mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->exit_cl,  y * PXL, x * PXL);
		graphs->parse_info->player.x += 1;
		x = graphs->parse_info->player.x;
		if (graphs->parse_info->clean_map[x][y] == 'C')
		{
			graphs->parse_info->collectables--;
			graphs->parse_info->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(graphs->ptr, graphs->win, graphs->sprites->crash_f,  y * PXL, x * PXL);
		graphs->parse_info->player.movements += 1;
	}
	printf("Taps: %d\n", graphs->parse_info->player.movements); //CAMBIAR POR FT_PRINTF
	check_exit(graphs);
}
