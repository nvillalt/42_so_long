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

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>
#include<stdio.h>

typedef struct s_graphics
{
	void	*mlx;
	void	*window_ptr;
} t_graphics;

bool parse_map(char *argv, char **map);
bool ft_strncmpend(char *s1, char *s2, size_t n);

#endif
