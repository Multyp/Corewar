/*
** realloc.c for realloc in /home/da-fon_s/rendu/Bsq/test
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Sat Nov 28 23:35:48 2015 samuel da-fonseca
** Last update Fri Jan 29 09:58:11 2016 samuel da-fonseca
*/

#include <libmy.h>

char	*my_realloc(char *ptr, int size)
{
  char	*ptr_realloc;
  int	c;

  c = 0;
  if (ptr == NULL || size < 1)
    return (NULL);
  ptr_realloc = malloc(sizeof(char) * (size + 1));
  if (ptr_realloc == NULL)
    return (NULL);
  while (c != size && ptr[c] != '\0')
    {
      ptr_realloc[c] = ptr[c];
      c = c + 1;
    }
  if (ptr[c] == '\0')
    while (c < size)
      ptr_realloc[c++] = '\0';
  ptr_realloc[c] = '\0';
  free(ptr);
  return (ptr_realloc);
}
