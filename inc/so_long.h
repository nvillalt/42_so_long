/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 19:17:30 by nvillalt         ###   ########.fr       */
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

// Quizás luego hacer otro struct para ir almacenando todo lo que tiene el player (sumar 1 a los collectables)
// cuando los tenga, para cuando sea igual al número total de collectables, etc.

typedef	struct s_mapgraph
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		**mapcpy; // Copia para pintar con el flood_fill
	int			win_width;
	int			win_height;
	int			fd;
	int			collectables;
	int			exit;
	int			player;
	int			movements;
} t_mapgraph;

// PARSE
bool parse_map(char *argv, t_mapgraph **map_info);

// UTILS
bool 		error_message(int n);
bool	count_height(t_mapgraph **map_info);
t_mapgraph	*init_struct(void);

// SUPPORT FUNCTIONS
char	*gnl_modified(int fd); // + utils de gnl_modified
char	*ft_strjoin_mod(char *saved, char *buffer);
bool	ft_strncmpend(char *s1, char *s2, int n);
bool  	check_chars(char *str);
int		ft_strlen_mod(char *str);

#endif
