
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