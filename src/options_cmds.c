#include "vm_corewar.h"

int	check_file(t_vm *vm, char *file_name, char *param)
{
  int	fd;

  (void)vm;
  (void)param;
  printf("%s\n", file_name);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (my_error(OPEN_FAILED(file_name)));
  else if (vm->file_opt == true &&
	   add_elem(vm->progs, file_name) == NULL)
    return (my_error("Could not create a new elem"));
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

int	my_load_address(t_vm *vm, char *param, char *next_param)
{
  printf("Fonction load address\n");
  (void)vm;
  (void)param;
  (void)next_param;
  return (1);
}

int	my_get_prognumber(t_vm *vm, char *param, char *next_param)
{
  printf("Fonction next prognumber\n");
  (void)vm;
  (void)param;
  (void)next_param;
  return (1);
}
