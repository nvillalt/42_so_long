/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 09:27:09 by nvillalt         ###   ########.fr       */
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
# define PX 50

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
# define KEY_LEFT 123
# define KEY_DOWN 125

typedef struct s_sprites
{
	void		*f;
	void		*wall;
	void		*apple;
	void		*excl;
	void		*exit_op;
	void		*crash_f;
	void		*crash_b;
	void		*crash_l;
	void		*crash_r;
}	t_sprites;

typedef struct s_player
{
	int	x;
	int	y;
	int	mov;
	int	obj;
}	t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}	t_exit;

typedef struct s_parsemap
{
	char		**clean_map;
	char		**map;
	int			w_x;
	int			w_y;
	int			fd;
	int			obj;
	int			obj_check;
	int			exit_check;
	int			exit_num;
	int			player_num;
	t_player	player;
	t_exit		exit;
}	t_parsemap;

typedef struct s_graphics
{
	t_sprites	*s;
	t_parsemap	*inf;
	void		*p;
	void		*w;
}	t_graphics;

// INIT
t_parsemap		*init_struct(void);

// PARSE
int				parse_map(char *argv, t_parsemap **mapinf);

// GRAPHICS & KEYBINDS
int				start_game(t_parsemap *mapinf);
void			move_character_w(t_graphics *g);
void			move_character_a(t_graphics *g);
void			move_character_s(t_graphics *g);
void			move_character_d(t_graphics *g);
void			check_exit(t_graphics *g);
int				close_program(t_graphics *g);
int				key_hook(int key, t_graphics *g);

// VALIDATE
int				validate_map(t_parsemap **mapinf);

// UTILS
int				check_chars(char *str, t_parsemap **mapinf);
int				error_message_parse(int n, t_parsemap *mapinf);
int				error_message_graph(int n, t_graphics *g);
void			free_parse_struct(t_parsemap *mapinf);
void			free_graph_struct(t_graphics *g);
int				count_height(t_parsemap **mapinf);

// SUPPORT FUNCTIONS
char			*gnl_modified(int fd);
char			*ft_strjoin_mod(char *saved, char *buffer);
int				ft_strncmpend(char *s1, char *s2, int n);
int				ft_strlen_mod(char *str);

#endif
