#include "vm_corewar.h"

int		check_file(t_vm *vm, char *file_name, char *param)
{
  int		fd;
  t_prog	*tmp;

  (void)param;
  tmp = vm->progs;
  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (my_error(OPEN_FAILED(file_name)));
  else if (vm->file_opts[1] == false && vm->file_opts[0] == false &&
	   (vm = add_prog(vm, file_name)) == NULL)
    return (my_error("Could not create a new elem"));
  else if (vm->file_opts[1] == true || vm->file_opts[0] == true)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->prog_name = my_strdup(file_name);
      vm->file_opts[0] = false;
      vm->file_opts[1] = false;
      return (1);
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
	    "\t-dump\n"
	    "\t-a\n"
	    "\t-n\n", binary);
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
  if (check_list_for_address(vm, nb) == 1 ||
      (vm->file_opts[1] == false && vm->file_opts[0] == false &&
       add_prog(vm, NULL) == NULL))
    return (2);
  tmp = vm->progs;
  vm->file_opts[0] = true;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->address = nb;
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
