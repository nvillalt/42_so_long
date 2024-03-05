/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/02/28 19:29:46 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool  read_map(t_mapgraph *map_info)
{
  char  *str;
  int   i;

  i = 0;
  str = get_next_line(map_info->fd);
  map_info->map[i] = str;  // Da error porque la doble matriz no está bien hecha
  printf("%s", str);
  printf("%s", map_info->map[i]);
  // free(str);
/*   while (str)
  {
    map_info->map[i] = ft_strdup(str);
    free(str);
    str = get_next_line(map_info->fd);
    i++;
  } */
  return (true);
}

bool  parse_map(char *argv, t_mapgraph *map_info)
{
  map_info->fd = open(argv, O_RDONLY);
  if (!map_info->fd)
    return (error_message());
  if (!read_map(map_info))
    return (error_message());
  return (true);
}