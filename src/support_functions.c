/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:02:06 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/14 19:34:50 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_mod(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

bool	ft_strncmpend(char *s1, char *s2, int n)
{
	int	len;

	len = ft_strlen_mod(s1) - 1;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		--n;
		if (s1[len] != s2[n])
			return (false);
		len--;
	}
	return (true);
}

char	*ft_strjoin_mod(char *s, char *b)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = ft_calloc_gnl(sizeof(char), ft_strlen_gnl(s) + ft_strlen_gnl(b) + 1);
	if (!join)
	{
		free(s);
		return (NULL);
	}
	while (s && s[i] != '\0')
	{
		join[i] = s[i];
		i++;
	}
	while (b[j] != '\0')
	{
		join[i] = b[j];
		i++;
		j++;
	}
	free(s);
	return (join);
}

static char	*read_line(int fd, char *line)
{
	char	*b;
	int		rchar;

	rchar = 1;
	b = ft_calloc(sizeof(char), (1 + 1));
	if (!b)
		return (NULL);
	while (rchar > 0 && !ft_strchr(b, '\n'))
	{
		rchar = read(fd, b, 1);
		if (rchar == -1)
		{
			free(b);
			return (NULL);
		}
		if (rchar > 0)
		{
			b[rchar] = '\0';
			line = ft_strjoin_gnl(line, b);
		}
	}
	free(b);
	return (line);
}

char	*gnl_modified(int fd)
{
	char	*s;
	char	*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	s = read_line(fd, line);
	return (s);
}
