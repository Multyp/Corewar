#include "vm_corewar.h"

char            *get_binary(char *binary)
{
  static char   *stock_binary = NULL;

  if (stock_binary == NULL)
    stock_binary = binary;
  return (stock_binary);
}

int	show_help(t_vm *vm, char *param)
{
  char	*binary;

  (void)vm;
  (void)param;
  binary = get_binary(NULL);
  my_printf("Usage: %s [options]\n"
            "Options:\n"
            "\t--help\t\t\tDisplay this help\n"
	    "\t-dump\n"
	    "\t-a\n"
	    "\t-n\n", binary);
  return (1);
}

int	my_dump_memory(t_vm *vm, char *param)
{
  printf("Fonction dump memory\n");
  (void)vm;
  (void)param;
  return (1);
}


int	my_load_address(t_vm *vm, char *param)
{
  printf("Fonction load address\n");
  (void)vm;
  (void)param;
  return (1);
}


int	my_next_prognumber(t_vm *vm, char *param)
{
  printf("Fonction next prognumber\n");
  (void)vm;
  (void)param;
  return (1);
}
