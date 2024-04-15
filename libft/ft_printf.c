/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:43:28 by nvillalt          #+#    #+#             */
/*   Updated: 2024/04/15 14:29:33 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_types(unsigned int total, int c, va_list args)
{
	if (c == 'c')
		total += ft_putchar_pf(va_arg(args, int));
	else if (c == 's')
		total += ft_putstr_pf(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		total += ft_putnbr_pf(va_arg(args, int));
	else if (c == 'x')
		total += ft_putbase_pf(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		total += ft_putbase_pf(va_arg(args, unsigned int), 0);
	else if (c == 'p')
		total += ft_putptr_pf(va_arg(args, void *));
	else if (c == 'u')
		total += ft_putunsig_pf(va_arg(args, unsigned int));
	else
		total += ft_putchar_pf('%');
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	int				total;
	char			*arr;

	i = 0;
	total = 0;
	arr = "cspdiuxX%";
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr(arr, (const char)str[i + 1]))
		{
			i++;
			total = print_types(total, (int)str[i], args);
		}
		else
			total += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(args);
	return (total);
}
