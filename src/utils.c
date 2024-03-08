#include "so_long.h"

bool	error_message(int n)
{
	if (n == 1)
		write(1, "Wrong characters.", 17);
	if (n == 2)
		write(1, "Inconsistent width.", 19); // Da este error al terminar la última línea del mapa porque no cuenta el \n, ver cómo solucionar
	else if (n == 20)
		perror("so_long error");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

t_mapgraph	*init_struct(void)
{
	t_mapgraph	*map_info;
	
	map_info = malloc(sizeof(t_mapgraph));
	if (!map_info)
		error_message(20);
//  map_info->mlx = mlx_init(); //map_info->mlx = mlx_init();
	map_info->mlx_win = NULL;
	map_info->win_width = 0;
	map_info->win_height = 0;
	map_info->fd = 0;
	map_info->map = NULL;
	map_info->collectables = -1;
	map_info->exit = -1;
	map_info->movements = -1;

	return(map_info);
}

/* void	print_list(t_mapgraph *map_info)
{
	int		i;
	int		len;

	i = 0;
	len = list_len(map_info);
	while (i < len)
	{
		printf("%s", map_info->map_nodes);
		i++;
	}
} */