/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:31:45 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:54:17 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsig_pf(unsigned int n)
{
	int				num_chars;
	unsigned int	num;

	num = n;
	num_chars = 0;
	if (n > 9)
	{
		num_chars += ft_putunsig_pf(num / 10);
		num_chars += ft_putunsig_pf(num % 10);
	}
	else
		num_chars += ft_putchar_pf(num + '0');
	return (num_chars);
}
