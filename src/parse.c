/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/08 18:08:04 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_collectables_check(t_parsemap **map_info)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*map_info)->win_y)
	{
		y = 0;
		while (y < (*map_info)->win_x)
		{
			if ((*map_info)->map[x][y] == 'P')
				(*map_info)->player_num++;
			if ((*map_info)->map[x][y] == 'C')
				(*map_info)->collectables++;
			if ((*map_info)->map[x][y] == 'E')
				(*map_info)->exit_num++;
			y++;
		}
		x++;
	}
	if ((*map_info)->player_num != 1 || (*map_info)->exit_num != 1)
		return (error_message(4));
	return (1);
}

static int	borders_check(t_parsemap **map_info)
{
	int	total;
	int	len;
	int	x;
	int	y;

	x = 0;
	y = 0;
	total = (*map_info)->win_y;
	len = (*map_info)->win_x;
	while (y < len)
	{
		if ((*map_info)->map[0][y] != '1' ||
			(*map_info)->map[total - 1][y] != '1')
			return (error_message(3));
		y++;
	}
	while (x < (total - 1))
	{
		if ((*map_info)->map[x][0] != '1' ||
			(*map_info)->map[x][len - 1] != '1')
			return (error_message(3));
		x++;
	}
	return (1);
}

static int	file_to_map(t_parsemap **map_info)
{
	char	*str;
	char	*aux;

	str = "";
	aux = NULL;
	while (str)
	{
		str = gnl_modified((*map_info)->fd);
		if (str && check_chars(str))
		{
			if ((*map_info)->win_x == -1)
				(*map_info)->win_x = ft_strlen_mod(str);
			if ((*map_info)->win_x != -1
				&& (ft_strlen_mod(str) != (*map_info)->win_x))
				return (error_message(2));
			aux = ft_strjoin_mod(aux, str);
			free(str);
		}
	}
	free(str);
	(*map_info)->map = ft_split(aux, '\n');
	(*map_info)->clean_map = ft_split(aux, '\n');
	free(aux);
	return (1);
}

int	parse_map(char *argv, t_parsemap **map_info)
{
	(*map_info)->fd = open(argv, O_RDONLY);
	if ((*map_info)->fd == -1)
		return (error_message(20));
	if (!file_to_map(map_info))
		return (error_message(20));
	count_height(map_info);
	if (!borders_check(map_info))
		return (error_message(3));
	if (!exit_collectables_check(map_info))
		return (error_message(4));
	if (!validate_map(map_info))
		return (error_message(20));
	return (1);
}
