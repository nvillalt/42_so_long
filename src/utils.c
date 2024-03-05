#include "so_long.h"

bool	error_message(void)
{
	perror("so_long error");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

bool ft_strncmpend(char *s1, char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1) - 1;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		--n;
		if (s1[len] != s2[n])
			return (false);
		len--;
	}
	return(true);
}

void	init_struct(t_mapgraph *map_info)
{
	map_info = malloc(sizeof(t_mapgraph));
	if (!map_info)
		error_message();
//  map_info->mlx = mlx_init(); //map_info->mlx = mlx_init();
	map_info->mlx_win = NULL;
	map_info->win_width = -1;
	map_info->win_height = -1;
	map_info->fd = 0;
	map_info->map = NULL;
	map_info->collectables = -1;
	map_info->exit = -1;
	map_info->movements = -1;
}