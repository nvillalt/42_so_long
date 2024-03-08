/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 16:11:47 by nvillalt         ###   ########.fr       */
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
	void		*mlx;
	void		*mlx_win;
	char		**map;
	size_t		win_width;
	size_t		win_height;
	int			fd;
	int			collectables;
	int			exit;
	int			movements;
} t_mapgraph;

// PARSE
bool parse_map(char *argv, t_mapgraph **map_info);

// UTILS
bool error_message(int n);
t_mapgraph	*init_struct(void);

// FUNCTIONS
char	*gnl_modified(int fd);
char	*ft_strjoin_mod(char *saved, char *buffer);
bool	ft_strncmpend(char *s1, char *s2, size_t n);

#endif
