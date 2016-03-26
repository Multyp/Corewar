/*
** write_header.c for write headder in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 13:01:09 2016 Poc
** Last update Sat Mar 26 19:57:45 2016 Poc
** Last update Sat Mar 26 19:07:21 2016 Arthur ARNAUD
*/

#include "asm.h"

char	*get_right_name(char *str)
{
  int	i;
  char	*new_str;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.')
	str[i] = 0;
      i++;
    }
  if ((new_str = malloc(my_strlen(str) + 7)) == NULL)
    return (write(2, "Can't perform malloc\n", 21), NULL);
  my_strcpy(new_str, str);
  my_strcat(new_str, ".cor");
  return (new_str);
}

int	write_header(t_header *header, char *name)
{
  int	fd;

  if ((name = get_right_name(name)) == NULL)
    return (1);
  header->prog_size = change_endian(header->prog_size);
  if ((fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1 ||
      (write(fd, header, sizeof(t_header) - 4) == -1))
    return (1);
  return (fd);
}
