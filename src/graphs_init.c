/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:40:16 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:53:47 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_sprites(t_graphics *g, t_sprites *s)
{
	int	x;
	int	y;

	x = PX;
	y = PX;
	s->wall = mlx_xpm_file_to_image(g->p, GRASS, &x, &y);
	if (!s->wall)
		return (error_message(20));
	s->f = mlx_xpm_file_to_image(g->p, PATH, &x, &y);
	if (!s->f)
		return (error_message(20));
	s->apple = mlx_xpm_file_to_image(g->p, APPLE, &x, &y);
	if (!s->apple)
		return (error_message(20));
	s->excl = mlx_xpm_file_to_image(g->p, ROCK, &x, &y);
	if (!s->excl)
		return (error_message(20));
	s->exit_op = mlx_xpm_file_to_image(g->p, MASK, &x, &y);
	if (!s->exit_op)
		return (error_message(20));
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
		return (error_message(20));
	s->crash_b = mlx_xpm_file_to_image(g->p, CRASHBACK, &x, &y);
	if (!s->exit_op)
		return (error_message(20));
	s->crash_l = mlx_xpm_file_to_image(g->p, CRASHLEFT, &x, &y);
	if (!s->exit_op)
		return (error_message(20));
	s->crash_r = mlx_xpm_file_to_image(g->p, CRASHRIGHT, &x, &y);
	if (!s->exit_op)
		return (error_message(20));
	return (1);
}

void	init_image(t_graphics *g, t_sprites *s)
{
	int	i;
	int	j;

	load_sprites(g, s);
	load_crash(g, s);
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

void	start_game(t_parsemap *mapinf)
{
	t_sprites	*s;
	t_graphics	*g;

	g = malloc(sizeof(t_graphics));
	s = malloc(sizeof(t_sprites));
	if (!s || !g)
		return ;
	g->inf = mapinf;
	g->s = s;
	g->p = mlx_init();
	if (!g->p)
		return ;
	g->w = mlx_new_window(g->p, (mapinf->w_x * PX),
			(mapinf->w_y * PX), "so_long");
	if (!g->w)
		return ;
	init_image(g, s);
	mlx_key_hook(g->w, &key_hook, g);
	mlx_hook(g->w, 17, 0, close_program, g);
	//mlx_destroy_display(g->p);
	mlx_loop(g->p);
}

	// mlx_destroy_wdow((*mlx)->mlx, (*mlx)->w); // Al terminar
	// mlx_destroy_image()
	// mlx_destroy_display((*mlx)->mlx);
	//free ((*mlx)->mlx); -> Liberar eventualmente