/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:32 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 09:15:09 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_parsemap	*init_struct(void)
{
	t_parsemap	*mapinf;

	mapinf = malloc(sizeof(t_parsemap));
	if (!mapinf)
		error_message_parse(20, mapinf);
	mapinf->w_x = -1;
	mapinf->w_y = -1;
	mapinf->fd = 0;
	mapinf->map = NULL;
	mapinf->clean_map = NULL;
	mapinf->obj = 0;
	mapinf->exit_num = 0;
	mapinf->player_num = 0;
	mapinf->exit_check = 0;
	mapinf->obj_check = 0;
	mapinf->player.mov = 0;
	return (mapinf);
}
