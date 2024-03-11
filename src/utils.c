/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 19:20:22 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The function check_chars makes sure that no character
   apart from the allowed ones are present in the lines read
   by gnl. If a not allowed character is present, the function
   exits.*/

bool  check_chars(char *str)
{
  int i;
  int len;
  
  i = 0;
  len = ft_strlen_mod(str);
  while (i < len) // len - 1 para poder saltar el \n
  {
    if (!(str[i] == '1' || str[i] == '0' || 
      str[i] == 'C' || str[i] == 'E' || str[i] == 'P'))
      return (error_message(1));
    i++;
  }
  return (true);
}

bool	count_height(t_parsemap **map_info)
{
	int	count;

	count = 0;
	if ((*map_info)->win_height == -1)
	{
		while ((*map_info)->map[count])
			count++;
	}
	(*map_info)->win_height = count;
	if (count < 4)
		return (error_message(3)); // Liberar las matrices de map_info y map_graphs antes de salir.
	return (true);
}

bool	error_message(int n)
{
	if (n == 1)
		write(1, "Wrong characters.", 17);
	if (n == 2)
		write(1, "Inconsistent width.", 19); // Da este error al terminar la última línea del mapa porque no cuenta el \n, ver cómo solucionar
	if (n == 3)
		write(1, "Wrong walls in map.", 19);
	if (n == 4)
		write(1, "Wrong number of exit or players.", 32);
	else if (n == 20)
		perror("so_long error");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

/* void	print_list(t_parsemap *map_info)
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