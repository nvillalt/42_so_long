/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:42:23 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 09:26:48 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

void	free_parse_struct(t_parsemap *mapinf)
{
	if (mapinf->map != NULL)
		free_matrix(mapinf->map);
	if (mapinf->clean_map != NULL)
		free_matrix(mapinf->clean_map);
	if (mapinf != NULL)
		free(mapinf);
	return ;
}

void	free_graph_struct(t_graphics *g)
{
	if (g->inf != NULL)
		free_parse_struct(g->inf);
	if (g->p != NULL)
		free(g->p); // Si no da doble liberación, we don't know
	if (g->s != NULL)
		free(g->s);
	if (g != NULL)
		free(g);
	return ;
}

int	error_message_graph(int n, t_graphics *g)
{	
	if (n == 1)
		write(1, "Wrong characters.\n", 18);
	if (n == 2)
		write(1, "Inconsistent width.\n", 20);
	if (n == 3)
		write(1, "Wrong walls in map.\n", 20);
	if (n == 4)
		write(1, "Wrong number of exit or players.\n", 33);
	if (n == 5)
		write(1, "Unsolvable map.\n", 16);
	if (n == 6)
		ft_printf("Map too big.\n");
	else if (n == 20)
		perror("so_long error");
	free_graph_struct(g);
	system("leaks -q so_long");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
	
}

int	error_message_parse(int n, t_parsemap *mapinf)
{
	if (n == 1)
		write(1, "Wrong characters.\n", 18);
	if (n == 2)
		write(1, "Inconsistent width.\n", 20);
	if (n == 3)
		write(1, "Wrong walls in map.\n", 20);
	if (n == 4)
		write(1, "Wrong number of exit or players.\n", 33);
	if (n == 5)
		write(1, "Unsolvable map.\n", 16);
	if (n == 6)
		ft_printf("Map too big.\n");
	else if (n == 20)
		perror("so_long error");
	free_parse_struct(mapinf);
	system("leaks -q so_long");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
