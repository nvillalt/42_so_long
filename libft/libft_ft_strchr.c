/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_strchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:22:13 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 14:30:00 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)str;
	while (copy[i] != '\0')
	{
		if (copy[i] == (unsigned char)c)
			return ((char *)copy + i);
		i++;
	}
	if (copy[i] == (unsigned char)c)
		return ((char *)copy + i);
	else
		return (0);
}
