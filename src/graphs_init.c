/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 14:29:50 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_graphics *g, t_sprites *s)
{
	int	i;
	int	j;

	load_sprites(g, s);
	j = 0;
	while (g->inf->clean_map[j])
	{
		i = -1;
		while (g->inf->clean_map[j][++i])
		{
			if (g->inf->clean_map[j][i] == '1')
				mlx_put_image_to_window(g->p, g->w, s->wall, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == '0')
				mlx_put_image_to_window(g->p, g->w, s->f, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'E')
				mlx_put_image_to_window(g->p, g->w, s->excl, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'P')
				mlx_put_image_to_window(g->p, g->w, s->crash_r, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'C')
				mlx_put_image_to_window(g->p, g->w, s->apple, i * PX, j * PX);
		}
		j++;
	}
	return ;
}

int	start_game(t_parsemap *mapinf)
{
	t_sprites	*s;
	t_graphics	*g;

	g = malloc(sizeof(t_graphics));
	s = malloc(sizeof(t_sprites));
	if (!s || !g)
		return (error_message_parse(20, mapinf));
		
	// s->f = NULL;
	// s->wall = NULL;
	// s->apple = NULL;
	// s->excl = NULL;
	// s->exit_op = NULL;
	// s->crash_b = NULL;
	// s->crash_f = NULL;
	// s->crash_l = NULL;
	// s->crash_r = NULL;
	g->inf = mapinf;
	g->s = s;
	g->p = mlx_init();
	if (!g->p)
		return (error_message_graph(20, g));
	g->w = mlx_new_window(g->p, (mapinf->w_x * PX),
			(mapinf->w_y * PX), "so_long");
	if (!g->w)
		return (error_message_graph(20, g));
	init_image(g, s);
	mlx_key_hook(g->w, &key_hook, g);
	mlx_hook(g->w, 17, 0, close_program, g);
	mlx_loop(g->p);
	return (1);
}
