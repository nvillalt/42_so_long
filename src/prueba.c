#include "so_long.h"

bool  file_to_map2(t_parsemap **map_info)
{
  char  *str;
  char  *aux;
  str = "";
  while (str)
  {
    str = gnl_modified((*map_info)->fd);
    if (str && check_chars(str)) // LIBERAR SI DA ERROR?
    {
      // if ((*map_info)->win_width == 0)
      //   (*map_info)->win_width = ft_strlen_mod(str);
      // if ((*map_info)->win_width != 0 && (ft_strlen_mod(str) != (*map_info)->win_width)) //Da este error al terminar la última línea del mapa porque no cuenta el \n, ver cómo solucionar
      //   return (error_message(2)); // Una linea que tiene una longitud distinta a las otras == caca. Liberar????
      aux = ft_strjoin_mod(aux, str);
      free(str);
    }
  }
  free(str);
  //free(aux);
/*   (*map_info)->map = ft_split(aux, '\n');
  int i = 0;
  while ((*map_info)->map[i])
  {
    printf("%s", (*map_info)->map[i]);
    i++;
  } */
  (*map_info)->map = ft_split(aux, '\n');
  return (true);
}