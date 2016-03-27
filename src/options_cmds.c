/*
** options_cmds.c for options_cmds in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:56:41 2016 Da Fonseca Samuel
** Last update Sun Mar 27 20:03:13 2016 Marwane
*/

#include "vm_corewar.h"

int		check_file(t_vm *vm, char *file_name, char *param)
{
  int		fd;
  t_prog	*tmp;

  (void)param;
  tmp = vm->progs;
  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (my_error(OPEN_FAILED));
  else if (vm->file_opts[1] == false && vm->file_opts[0] == false &&
	   (vm = add_prog(vm, file_name)) == NULL)
    {
      close(fd);
      return (1);
    }
  else if (vm->file_opts[1] == true || vm->file_opts[0] == true)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->prog_name = my_strdup(file_name);
      vm->file_opts[0] = false;
      vm->file_opts[1] = false;
    }
  close(fd);
  return (1);
}

int	show_help(t_vm *vm, char *param, char *next_param)
{
  char	*binary;

  (void)vm;
  (void)param;
  (void)next_param;
  binary = get_binary(NULL);
  my_printf("Usage: %s [options]\n"
            "Options:\n"
            "\t--help\t\t\tDisplay this help\n"
	    "\t-dump\t\t\t<cycles>\n"
	    "\t-a\t\t\t<address>\n"
	    "\t-n\t\t\t<programme number>\n", binary);
  return (1);
}

int	my_dump_memory(t_vm *vm, char *param, char *next_param)
{
  (void)vm;
  (void)param;
  (void)next_param;
  vm->dump = my_getnbr(next_param);
  return (2);
}

int		my_load_address(t_vm *vm, char *param, char *next_param)
{
  t_prog	*tmp;
  int		nb;

  (void)param;
  nb = my_getnbr(next_param);
  if (nb < 0)
    return (my_error(INVALID_NUMBER) + 1);
  if (check_list_for_address(vm, nb) == 1 ||
      (vm->file_opts[1] == false && vm->file_opts[0] == false &&
       add_prog(vm, NULL) == NULL))
    return (2);
  tmp = vm->progs;
  vm->file_opts[0] = true;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->address = nb % MEM_SIZE;
  return (2);
}

int		my_get_prognumber(t_vm *vm, char *param, char *next_param)
{
  t_prog	*tmp;
  int		nb;

  (void)param;
  nb = my_getnbr(next_param);
  if (check_list_for_prognb(vm, nb) == 1 ||
      (vm->file_opts[0] == false && vm->file_opts[1] == false &&
       add_prog(vm, NULL) == NULL))
    return (2);
  tmp = vm->progs;
  vm->file_opts[1] = true;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->prog_number = nb;
  return (2);
}
