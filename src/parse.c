/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/08 19:23:13 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool exit_collectables_check(t_mapgraph **map_info)
{
  int x;
  int y;

  x = 0;
  while (x < (*map_info)->win_height)
  {
    y = 0;
    while (y < (*map_info)->win_width)
    {
      if ((*map_info)->map[x][y] == 'P')
        (*map_info)->player++;
      if ((*map_info)->map[x][y] == 'C')
        (*map_info)->collectables++;
      if ((*map_info)->map[x][y] == 'E')
        (*map_info)->exit++;
      y++;
    }
    x++;
  }
//  printf("%d\n%d\n%d\n", (*map_info)->player, (*map_info)->collectables, (*map_info)->exit);
  if ((*map_info)->player != 1 || (*map_info)->exit != 1)
    return (error_message(4));
  return (true);
}

/* 
  EXPLICACIÓN DE LA FUNCIÓN
  */

static bool borders_check(t_mapgraph **map_info)
{
  int total;
  int len;
  int x;
  int y;

  x = 0;
  y = 0;
  total = (*map_info)->win_height;
  len = (*map_info)->win_width;
  while (y < len)
  {
    if ((*map_info)->map[0][y] != '1' || (*map_info)->map[total - 1][y] != '1')
      return (error_message(3));
    y++;
  }
  while (x < (total - 1))
  {
    if ((*map_info)->map[x][0] != '1' 
      || (*map_info)->map[x][len - 1] != '1')
      return (error_message(3));
    x++;
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
  char  *aux; // Quizás en algun punto me de error por variable no inicializada

  str = "";
  while (str)
  {
    str = gnl_modified((*map_info)->fd);
    if (str && check_chars(str)) // LIBERAR SI DA ERROR?
    {
      if ((*map_info)->win_width == -1)
        (*map_info)->win_width = ft_strlen_mod(str);
      if ((*map_info)->win_width != -1 && (ft_strlen_mod(str) != (*map_info)->win_width))
        return (error_message(2));
      aux = ft_strjoin_mod(aux, str); // Junta todas las líneas y quita el '\n' con el split
      free(str);
    }
  }
  free(str);
  (*map_info)->map = ft_split(aux, '\n');
  free(aux);
  return (true);
}

// LIBERAR LA ALOJACIÓN DE MEMORIA DEL MAPA. 
bool  parse_map(char *argv, t_mapgraph **map_info)
{
  (*map_info)->fd = open(argv, O_RDONLY); // Close ???
  if (!(*map_info)->fd)
    return (error_message(20));
  if (!file_to_map(map_info))
    return (error_message(20)); // Ver si tendría que liberar si hay errores después (solo hay memoria alojada en la doble matriz y en el struct)
  count_height(map_info);
  if (!borders_check(map_info))
    return (error_message(3));
  if (!exit_collectables_check(map_info))
    return (error_message(4));
  return (true);
}

/*   
  Checar leaks con la doble matriz
  int i = 0;
  while ((*map_info)->map[i])
  {
    free((*map_info)->map[i]);
    i++;
  }
  free((*map_info)->map); */