/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 20:50:00 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ···· libraries ···· */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>
# include <stdio.h>
# include <mlx.h>

/* ···· window size ···· */
# define WINDOW 100
# define PIXELS 10

/* ···· sprites route ···· */
# define PATH "./assets/dirt_sprite.xpm"
# define GRASS "./assets/grass_sprite.xpm"

// Quizás luego hacer otro struct para ir almacenando todo lo que tiene el player (sumar 1 a los collectables)
// cuando los tenga, para cuando sea igual al número total de collectables, etc.

typedef struct s_sprites
{
	void		*floor;
	void		*wall;
	void		*apple;
	void		*exit_cl;
	void		*exit_op;
	// crash sprites here
} t_sprites;

typedef struct s_player
{
	int			x;
	int			y;
	int			movements; // Movements made by the player
	int			collectables; // Collectables picked up
} t_player;

typedef struct s_exit
{
	int			x;
	int			y;
} t_exit;

typedef	struct s_parsemap
{
	char		**map; // Copia del mapa para pintar y validar con el floodfill
	int			win_x;
	int			win_y;
	int			fd;
	int			collectables;
	int			collectables_check;
	int			exit_check;
	int			exit_num;
	int			player_num;
	t_player	player;
	t_exit		exit;
} t_parsemap;

typedef struct s_graph
{
	char		**map; // mapa guardado en doble matriz
	void		*mlx;
	void		*win;
	int			movements;
	t_sprites	*sprites;
} t_graph;

// INIT
t_parsemap		*init_struct(void);
t_graph			*init_graph(void);

// PARSE
bool 			parse_map(char *argv, t_parsemap **map_info, t_graph **map_graphs);

// GRAPHICS
void			init_window(t_parsemap **map_info, t_graph **mlx);

// VALIDATE
bool  			validate_map(t_parsemap **map_info);

// UTILS
bool  			check_chars(char *str);
bool 			error_message(int n);
bool			count_height(t_parsemap **map_info);

// SUPPORT FUNCTIONS
char			*gnl_modified(int fd); // + utils de gnl_modified
char			*ft_strjoin_mod(char *saved, char *buffer);
bool			ft_strncmpend(char *s1, char *s2, int n);
int				ft_strlen_mod(char *str);

#endif
