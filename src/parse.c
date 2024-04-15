/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:51:01 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_obj_check(t_parsemap **mapinf)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*mapinf)->w_y)
	{
		y = 0;
		while (y < (*mapinf)->w_x)
		{
			if ((*mapinf)->map[x][y] == 'P')
				(*mapinf)->player_num++;
			if ((*mapinf)->map[x][y] == 'C')
				(*mapinf)->obj++;
			if ((*mapinf)->map[x][y] == 'E')
				(*mapinf)->exit_num++;
			y++;
		}
		x++;
	}
	if ((*mapinf)->player_num != 1 || (*mapinf)->exit_num != 1)
		return (error_message(4));
	return (1);
}

static int	borders_check(t_parsemap **mapinf)
{
	int	total;
	int	len;
	int	x;
	int	y;

	x = 0;
	y = 0;
	total = (*mapinf)->w_y;
	len = (*mapinf)->w_x;
	while (y < len)
	{
		if ((*mapinf)->map[0][y] != '1' ||
			(*mapinf)->map[total - 1][y] != '1')
			return (error_message(3));
		y++;
	}
	while (x < (total - 1))
	{
		if ((*mapinf)->map[x][0] != '1' ||
			(*mapinf)->map[x][len - 1] != '1')
			return (error_message(3));
		x++;
	}
	return (1);
}

static int	file_to_map(t_parsemap **mapinf)
{
	char	*str;
	char	*aux;

	str = "";
	aux = NULL;
	while (str)
	{
		str = gnl_modified((*mapinf)->fd);
		if (str && check_chars(str))
		{
			if ((*mapinf)->w_x == -1)
				(*mapinf)->w_x = ft_strlen_mod(str);
			if ((*mapinf)->w_x != -1
				&& (ft_strlen_mod(str) != (*mapinf)->w_x))
				return (error_message(2));
			aux = ft_strjoin_mod(aux, str);
			free(str);
		}
	}
	free(str);
	(*mapinf)->map = ft_split(aux, '\n');
	(*mapinf)->clean_map = ft_split(aux, '\n');
	free(aux);
	return (1);
}

int	parse_map(char *argv, t_parsemap **mapinf)
{
	(*mapinf)->fd = open(argv, O_RDONLY);
	if ((*mapinf)->fd == -1)
		return (error_message(20));
	if (!file_to_map(mapinf))
		return (error_message(20));
	count_height(mapinf);
	if (!borders_check(mapinf))
		return (error_message(3));
	if (!exit_obj_check(mapinf))
		return (error_message(4));
	if (!validate_map(mapinf))
		return (error_message(20));
	return (1);
}
