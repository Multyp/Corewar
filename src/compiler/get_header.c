/*
** get_header.c for getheader in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 16 17:17:26 2016 Clement Peau
** Last update Fri Mar 18 14:18:14 2016 Clement Peau
*/

#include "asm.h"

t_file		*get_name(t_header *header, t_file *list)
{
  int	i;
  int	k;

  k = 0;
  if (my_strncmp(list->str, ".name", 5) == 0)
    return (NULL);
  i = 0;
  while (list->str[i++] != '"')
    if (list->str[i] == 0)
      return (NULL);
  k = i;
  while (list->str[i++] != '"')
    if (list->str[i] == 0)
      return (NULL);
  list->str[i - 1] = 0;
  my_strcpy(header->prog_name, list->str + k);
  list = free_first(list);
  return (list);
}

t_file		*get_comment(t_header *header, t_file *file)
{
  int		i;
  int		k;

  if (my_strncmp(file->str, ".comment ", 9) == 0)
    return (file);
  i = 0;
  while (file->str[i++] != '"')
    if (file->str[i] == 0)
      {
	write(2, "Wrong comment format\n", 21);
	return (NULL);
      }
  k = i;
  while (file->str[i++] != '"')
    if (file->str[i] == 0)
      {
	write(2, "Wrong comment format\n", 21);
	return (NULL);
      }
  file->str[i - 1] = 0;
  my_strcpy(header->comment, file->str + k);
  file = free_first(file);
  return (file);
}

t_file		*get_header(int fd, t_header *header)
{
  char		*str;
  t_file	*file;

  if ((str = get_line_not_empty(fd)) != NULL)
    file = create_file_list(str);
  while ((str = get_line_not_empty(fd)))
      add_to_back_file(file, str);
  my_memset(header, 0, sizeof(t_header));
  file = get_name(header, file);
  printf("header->progname = |%s|\n", header->prog_name);
  file = get_comment(header, file);
  printf("header->comment = |%s|\n", header->comment);
  return (file);
}
