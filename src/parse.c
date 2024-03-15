/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:08 by nvillalt          #+#    #+#             */
/*   Updated: 2024/03/15 19:55:50 by nvillalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int exit_collectables_check(t_parsemap **map_info)
{
  int x;
  int y;

  x = 0;
  while (x < (*map_info)->win_y)
  {
    y = 0;
    while (y < (*map_info)->win_x)
    {
      if ((*map_info)->map[x][y] == 'P')
        (*map_info)->player_num++;
      if ((*map_info)->map[x][y] == 'C')
        (*map_info)->collectables++;
      if ((*map_info)->map[x][y] == 'E')
        (*map_info)->exit_num++;
      y++;
    }
    x++;
  }
  // Si hay error, liberar las matrices de map_graph y map_info
  if ((*map_info)->player_num != 1 || (*map_info)->exit_num != 1)
    return (error_message(4));
  return (1);
}

/*
  EXPLICACIÓN DE LA FUNCIÓN
  */

static int borders_check(t_parsemap **map_info)
{
  int total;
  int len;
  int x;
  int y;

  x = 0;
  y = 0;
  total = (*map_info)->win_y;
  len = (*map_info)->win_x;
  while (y < len)
  {
    if ((*map_info)->map[0][y] != '1' || (*map_info)->map[total - 1][y] != '1')
      return (error_message(3));
    y++;
  }
  while (x < (total - 1))
  {
    if ((*map_info)->map[x][0] != '1' || (*map_info)->map[x][len - 1] != '1')
      return (error_message(3));
    x++;
  }
  return (1);
}

// Check str y ver que solo contenga los caracteres permitidos
// Si da error > liberar str / liberar la lista, print error y exit
// Si no da error, new node + addlistback.
// Guardarlo en una lista de nodos y luego la lista de nodos meterla en la doble matriz una vez lo tenga

/* file_to_list adds to a node in a linked list the
   string read from the map file after being checked for
   allowed characters. */

static int file_to_map(t_parsemap **map_info, t_graph **map_graphs)
{
  char *str;
  char *aux; // Quizás en algun punto me de error por variable no inicializada

  str = "";
  aux = NULL;
  while (str)
  {
    str = gnl_modified((*map_info)->fd);
    if (str && check_chars(str)) // LIBERAR SI DA ERROR?
    {
      if ((*map_info)->win_x == -1)
        (*map_info)->win_x = ft_strlen_mod(str);
      if ((*map_info)->win_x != -1 && (ft_strlen_mod(str) != (*map_info)->win_x))
        return (error_message(2));
      aux = ft_strjoin_mod(aux, str); // Junta todas las líneas y quita el '\n' con el split
      free(str);
    }
  }
  free(str);
  (*map_info)->map = ft_split(aux, '\n');
  (*map_graphs)->map = ft_split(aux, '\n');
  
  int i = 0;
  while((*map_graphs)->map[i])
  {
    printf("%s\n", (*map_graphs)->map[i]);
    i++;
  }
  //
  free(aux);
  return (1);
}

// LIBERAR LA ALOJACIÓN DE MEMORIA DEL MAPA.
int parse_map(char *argv, t_parsemap **map_info, t_graph **map_graphs)
{
  (*map_info)->fd = open(argv, O_RDONLY); // Close ???
  if (!(*map_info)->fd)
    return (error_message(20)); // Maybe I can remove the.. returns.
  if (!file_to_map(map_info, map_graphs))
    return (error_message(20)); // Ver si tendría que liberar si hay errores después (solo hay memoria alojada en la doble matriz y en el struct)
  count_height(map_info);
  if (!borders_check(map_info))
    return (error_message(3));
  if (!exit_collectables_check(map_info))
    return (error_message(4));
  if (!validate_map(map_info))
    return (error_message(20));
  return (1);
}

/*

  int i = 0;
  while ((*map_info)->map[i])
  {
    printf("%s", (*map_info)->map[i]);
    printf("\n");
    i++;
  }

  Checar leaks con la doble matriz
  int i = 0;
  while ((*map_info)->map[i])
  {
    free((*map_info)->map[i]);
    i++;
  }
  free((*map_info)->map); */