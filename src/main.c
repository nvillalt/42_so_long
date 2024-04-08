/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/08 18:12:21 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_parsemap	*map_info;

	map_info = NULL;
	if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
	{
		write(1, "Wrong extension or arg amount.\n", 31);
		return (EXIT_FAILURE);
	}
	map_info = init_struct();
	parse_map(argv[1], &map_info);
	start_game(map_info);
	// FREE ADD HERE
	free(map_info);
	system("leaks -q so_long");
	return (0);
}
