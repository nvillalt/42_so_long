/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 10:10:35 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_parsemap	*mapinf;

	mapinf = NULL;
	if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
	{
		write(1, "Wrong extension or arg amount.\n", 31);
		return (EXIT_FAILURE);
	}
	mapinf = init_struct();
	parse_map(argv[1], &mapinf);
	start_game(mapinf);
	free_parse_struct(mapinf);
	system("leaks -q so_long");
	return (0);
}
