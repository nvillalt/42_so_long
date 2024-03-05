/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/02/28 19:15:18 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>
# include <stdio.h>

typedef	struct s_mapgraph
{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		fd;
	char	**map;
	int		collectables;
	int		exit;
	int		movements;
} t_mapgraph;

bool parse_map(char *argv, t_mapgraph *map_info);
bool ft_strncmpend(char *s1, char *s2, size_t n);
bool error_message(void);

void	init_struct(t_mapgraph	*map_info);

#endif
