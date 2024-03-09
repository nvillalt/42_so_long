
#include  "so_long.h"

t_parsemap	*init_struct(void)
{
	t_parsemap	*map_info;

	map_info = malloc(sizeof(t_parsemap));
	if (!map_info)
		error_message(20);
	map_info->win_width = -1;
	map_info->win_height = -1;
	map_info->fd = 0;
	map_info->map = NULL;
	map_info->player = 0;
	map_info->collectables = 0;
	map_info->exit = 0;
	map_info->movements = -1;
	return(map_info);
}

t_graph			*init_graph(t_parsemap **map_info)
{
	t_graph	*mlx_map;

	mlx_map = malloc(sizeof(mlx_map));
	if (!mlx_map)
		return (NULL);
	mlx_map->map = NULL;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, (*map_info)->win_width, (*map_info)->win_height, "so_long")
	return (mlx_map);
}

t_player		*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->movements = 0;
	player->collectables = 0;
	return (player);
}