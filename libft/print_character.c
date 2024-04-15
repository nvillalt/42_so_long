/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:34:28 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:54:28 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_pf(int c)
{
	int	num_char;

	num_char = write(1, &c, 1);
	return (num_char);
}
