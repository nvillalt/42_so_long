/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:02:06 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 18:03:06 by nvillalt         ###   ########.fr       */
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
	return(true);
}

char	*ft_strjoin_mod(char *saved, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = ft_calloc_gnl(sizeof(char), ft_strlen_gnl(saved) + ft_strlen_gnl(buffer) + 1);
	if (!join)
	{
		free(saved); 
		return (NULL);
	}
	while (saved && saved[i] != '\0')
	{
		join[i] = saved[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		join[i] = buffer[j];
		i++;
		j++;
	}
	free(saved);
	return (join);
}

static char	*read_line(int fd, char *line)
{
	char	*buffer;
	int		rchar;

	rchar = 1;
	buffer = ft_calloc(sizeof(char), (1 + 1));
	if (!buffer)
		return (NULL);
	while (rchar > 0 && !ft_strchr(buffer, '\n'))
	{
		rchar = read(fd, buffer, 1);
		if (rchar == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (rchar > 0)
		{
			buffer[rchar] = '\0';
			line = ft_strjoin_gnl(line, buffer);
		}
	}
	free(buffer);
	return (line);
}

char	*gnl_modified(int fd)
{
	char	*saved;
	char	*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	saved = read_line(fd, line);
	return (saved);
}