/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 16:22:41 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The function check_chars makes sure that no character
   apart from the allowed ones are present in the lines read
   by gnl. If a not allowed character is present, the function
   exits.*/

static bool  check_chars(char *str)
{
  int i;
  int len;
  
  i = 0;
  len = ft_strlen(str);
  while (i < len) // len - 1 para poder saltar el \n
  {
    if (!(str[i] == '1' || str[i] == '0' || 
      str[i] == 'C' || str[i] == 'E' || str[i] == 'P'))
      return (error_message(1));
    i++;
  }
  return (true);
}

  // Check str y ver que solo contenga los caracteres permitidos
  // Si da error > liberar str / liberar la lista, print error y exit
  // Si no da error, new node + addlistback.
  // Guardarlo en una lista de nodos y luego la lista de nodos meterla en la doble matriz una vez lo tenga

/* file_to_list adds to a node in a linked list the
   string read from the map file after being checked for
   allowed characters. */

static bool  file_to_map(t_mapgraph **map_info)
{
  char  *str;
  char  *aux;

  str = "";
  while (str)
  {
    str = gnl_modified((*map_info)->fd);
    if (str && check_chars(str)) // LIBERAR SI DA ERROR?
    {
      if ((*map_info)->win_width == 0)
        (*map_info)->win_width = ft_strlen(str);
      if ((*map_info)->win_width != 0 && (ft_strlen(str) != (*map_info)->win_width)) //Da este error al terminar la última línea del mapa porque no cuenta el \n, ver cómo solucionar
        return (error_message(2)); // Una linea que tiene una longitud distinta a las otras == caca. Liberar????
      aux = ft_strjoin_mod(aux, str);
      free(str);
    }
  }
  free(str);
  free(aux);
/*   (*map_info)->map = ft_split(aux, '\n');
  int i = 0;
  while ((*map_info)->map[i])
  {
    printf("%s", (*map_info)->map[i]);
    i++;
  } */
  return (true);
}

bool  parse_map(char *argv, t_mapgraph **map_info)
{
  (*map_info)->fd = open(argv, O_RDONLY); // Close ???
  if (!(*map_info)->fd)
    return (error_message(20));
  if (!file_to_map(map_info))
    return (error_message(20));
  return (true);
}