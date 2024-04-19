/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:49:19 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 14:17:11 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_sprites(t_graphics *g)
{
	if (open(ROCK, O_RDONLY) == -1 || open(PATH, O_RDONLY) == -1 
		|| open(CRASHBACK, O_RDONLY) == -1 || open(GRASS, O_RDONLY) == -1
		|| open(MASK, O_RDONLY) == -1 || open(APPLE, O_RDONLY) == -1
		|| open(CRASHFRONT, O_RDONLY) == -1 || open(CRASHLEFT, O_RDONLY) == -1
		|| open(CRASHRIGHT, O_RDONLY) == -1)
		{
			printf("me aseguro que paso por aqui\n");
		return (error_message_graph(20, g));
		}
	else
		return (1);
}

static int	load_crash(t_graphics *g, t_sprites *s)
{
	int	x;
	int	y;

	x = PX;
	y = PX;

	s->crash_f = mlx_xpm_file_to_image(g->p, CRASHFRONT, &x, &y);
	if (!s->exit_op)
		return (error_message_graph(20, g));
	s->crash_b = mlx_xpm_file_to_image(g->p, CRASHBACK, &x, &y);
	if (!s->exit_op)
		return (error_message_graph(20, g));
	s->crash_l = mlx_xpm_file_to_image(g->p, CRASHLEFT, &x, &y);
	if (!s->exit_op)
		return (error_message_graph(20, g));
	s->crash_r = mlx_xpm_file_to_image(g->p, CRASHRIGHT, &x, &y);
	if (!s->exit_op)
		return (error_message_graph(20, g));
	return (1);
}


static int	load_background(t_graphics *g, t_sprites *s)
{
	int	x;
	int	y;

	x = PX;
	y = PX;
	g->s->wall = mlx_xpm_file_to_image(g->p, GRASS, &x, &y);
	if (!s->wall)
		return (error_message_graph(20, g));
	s->f = mlx_xpm_file_to_image(g->p, PATH, &x, &y);
	if (!s->f)
		return (error_message_graph(20, g));
	s->apple = mlx_xpm_file_to_image(g->p, APPLE, &x, &y);
	if (!s->apple)
		return (error_message_graph(20, g));
	s->excl = mlx_xpm_file_to_image(g->p, ROCK, &x, &y);
	if (!s->excl)
		return (error_message_graph(20, g));
	s->exit_op = mlx_xpm_file_to_image(g->p, MASK, &x, &y);
	if (!s->exit_op)
		return (error_message_graph(20, g));
	return (1);
}

void	load_sprites(t_graphics *g, t_sprites *s)
{
	check_sprites(g);
	load_background(g, s);
	load_crash(g, s);
	return ;
}