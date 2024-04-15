/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:31:18 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 14:30:01 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_pf(unsigned int n, int tf)
{
	char	*lowercase;
	char	*uppercase;
	int		num_chars;

	num_chars = 0;
	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	if (n >= 16)
	{
		num_chars += ft_putbase_pf(n / 16, tf);
		num_chars += ft_putbase_pf(n % 16, tf);
	}
	else
	{
		if (tf == 1)
			num_chars += ft_putchar_pf(lowercase[n]);
		else
			num_chars += ft_putchar_pf(uppercase[n]);
	}
	return (num_chars);
}
