/*
** header.c for header in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 01:49:07 2016 Arthur ARNAUD
** Last update Sun Mar  6 16:30:09 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	print_header(int fd_s, t_header *header)
{
  if (my_putstr_instruct(".name", fd_s) ||
      write(fd_s, "\"", 1) == -1 ||
      my_putstr_file(header->name, fd_s) ||
      write(fd_s, "\"\n", 2) == -1 ||
      my_putstr_instruct(".comment", fd_s) ||
      write(fd_s, "\"", 1) == -1 ||
      my_putstr_file(header->comment, fd_s) ||
      write(fd_s, "\"\n\n", 3) == -1)
    return (1);
  return (0);
}
