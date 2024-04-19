/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/19 10:10:41 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_chars(char *str, t_parsemap **mapinf)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_mod(str);
	while (i < len)
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'C'
				|| str[i] == 'E' || str[i] == 'P'))
			return (error_message_parse(1, *mapinf));
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
		return (error_message_parse(3, *mapinf));
	if (count > 27 || (*mapinf)->w_x > 50)
		return (error_message_parse(6, *mapinf));
	return (1);
}

