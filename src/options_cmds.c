#include "vm_corewar.h"

int		check_file(t_vm *vm, char *file_name, char *param)
{
  int		fd;
  t_prog	*tmp;

  (void)param;
  tmp = vm->progs;
  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (my_error(OPEN_FAILED(file_name)));
  else if (vm->file_opts[2] == false && vm->file_opts[1] == false &&
	   vm->file_opts[0] == false &&
	   add_prog(vm, file_name) == NULL)
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
  vm->file_opts[2] = true;
  vm->progs_nb++;
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
  printf("Fonction dump memory\n");
  (void)vm;
  (void)param;
  (void)next_param;
  return (1);
}

int		my_load_address(t_vm *vm, char *param, char *next_param)
{
  t_prog	*tmp;

  (void)vm;
  (void)param;
  (void)next_param;
  printf("Fonction load address\n");
  if (vm->file_opts[1] == false && vm->file_opts[2] == false &&
      vm->file_opts[0] == false &&
      add_prog(vm, NULL) == NULL)
    return (2);
  tmp = vm->progs;
  vm->file_opts[0] = true;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->address = my_getnbr(next_param);
  return (2);
}

int		my_get_prognumber(t_vm *vm, char *param, char *next_param)
{
  t_prog	*tmp;

  printf("Fonction next prognumber\n");
  (void)vm;
  (void)param;
  (void)next_param;
  if (vm->file_opts[0] == false && vm->file_opts[1] == false &&
      vm->file_opts[2] == false &&
      add_prog(vm, NULL) == NULL)
    return (2);
  tmp = vm->progs;
  vm->file_opts[1] = true;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->prog_number = my_getnbr(next_param);
  return (2);
}
