/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/22 19:45:23 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ···· libraries ···· */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>
# include <mlx.h>

/* ···· size ···· */
# define PXL 50

/* ···· sprites route ···· */
# define PATH "assets/path.xpm"
# define GRASS "assets/Grass.xpm"
# define APPLE "assets/collectable.xpm"
# define ROCK "assets/rock.xpm"
# define MASK "assets/mask.xpm"
# define CRASHFRONT "assets/crash_front.xpm"
# define CRASHBACK "assets/crash_back.xpm"
# define CRASHRIGHT "assets/crash_right.xpm"
# define CRASHLEFT "assets/crash_left.xpm"

/* ····· keybinds ····· */
# define ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0 
# define KEY_D 2
# define KEY_S 1
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_LEFT 125
# define KEY_DOWN 123

// Quizás luego hacer otro struct para ir almacenando todo lo que tiene el player (sumar 1 a los collectables)
// cuando los tenga, para cuando sea igual al número total de collectables, etc.

typedef struct s_sprites
{
	void		*floor;
	void		*wall;
	void		*apple;
	void		*exit_cl;
	void		*exit_op;
	void		*crash_f;
	void		*crash_b;
	void		*crash_l;
	void		*crash_r;
	void		*crash_rrun;
	void		*crash_lrun;
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
	char		**clean_map;
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

typedef struct s_global
{
	t_parsemap	*map_info;
	// Quizas los sprites
	void		*ptr;
	void		*win;
} t_global;

// INIT
t_parsemap		*init_struct(void);

// PARSE
int 			parse_map(char *argv, t_parsemap **map_info);

// GRAPHICS & KEYBINDS
void			start_game(t_parsemap *map);
// void			destroy_display(t_graph *mlx);
// int				key_hook(int key, t_graph *mlx);

// VALIDATE
int  			validate_map(t_parsemap **map_info);

// UTILS
int  			check_chars(char *str);
int 			error_message(int n);
int				count_height(t_parsemap **map_info);

// SUPPORT FUNCTIONS
char			*gnl_modified(int fd); // + utils de gnl_modified
char			*ft_strjoin_mod(char *saved, char *buffer);
int				ft_strncmpend(char *s1, char *s2, int n);
int				ft_strlen_mod(char *str);

#endif
