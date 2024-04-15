/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:51:02 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The function check_chars makes sure that no character
   apart from the allowed ones are present in the lines read
   by gnl. If a not allowed character is present, the function
   exits.*/

int	check_chars(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_mod(str);
	while (i < len)
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C'
				|| str[i] == 'E' || str[i] == 'P'))
			return (error_message(1));
		i++;
	}
	return (1);
}

int	count_height(t_parsemap **mapinf)
{
	int	count;

	count = 0;
	if ((*mapinf)->w_y == -1)
	{
		while ((*mapinf)->map[count])
			count++;
	}
	(*mapinf)->w_y = count;
	if (count < 3)
		return (error_message(3));
	return (1);
}

int	error_message(int n)
{
	if (n == 1)
		write(1, "Wrong characters.\n", 18);
	if (n == 2)
		write(1, "Inconsistent width.\n", 20);
	if (n == 3)
		write(1, "Wrong walls in map.\n", 20);
	if (n == 4)
		write(1, "Wrong number of exit or players.\n", 33);
	if (n == 5)
		write(1, "Unsolvable map.\n", 16);
	else if (n == 20)
		perror("so_long error");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
