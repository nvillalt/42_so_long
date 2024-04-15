/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:33:26 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 17:54:24 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_pf(int n)
{
	long int	num;
	int			num_chars;

	num = n;
	num_chars = 0;
	if (num < 0)
	{
		num_chars++;
		write (1, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		num_chars += ft_putnbr_pf(num / 10);
		num_chars += ft_putnbr_pf(num % 10);
	}
	else
		num_chars += ft_putchar_pf(num + '0');
	return (num_chars);
}
