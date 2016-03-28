/*
** list_champs_tool.c for list_champs in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:57:03 2016 Da Fonseca Samuel
** Last update Mon Mar 28 16:42:43 2016 Marwane
*/

#include "vm_corewar.h"

int		file_champion(t_champ *champ, char *file_path)
{
  int		fd;
  char		c;

  if (file_path != NULL && (fd = open(file_path, O_RDONLY)) == -1)
    return (my_error(OPEN_FAILED));
  if (file_path == NULL || (read(fd, champ, 2192) + read(fd, &c, 1)) < 2193)
    {
      my_printf("Error with file %s, invalid format .\n", file_path);
      champ->name[0] = 0;
      champ->magic = -1;
      champ->size = -1;
      champ->comment[0] = 0;
      champ->pc = -1;
      champ->alive = false;
      champ->cycles_to_wait = 0;
      (file_path != NULL ? close(fd) : 0);
      return (0);
    };
  champ->magic = change_endian(champ->magic);
  champ->size = change_endian(champ->size);
  champ->alive = false;
  champ->cycles_to_wait = 0;
  close(fd);
  return (0);
}

t_champ		*create_champ(char *file_path, int address, int prog_nb)
{
  t_champ	*new_champ;

  if ((new_champ = malloc(sizeof(t_champ))) == NULL)
    return (my_perror(MALLOC_FAILED));
  if (file_champion(new_champ, file_path) == 1)
    {
      free(new_champ);
      return (NULL);
    }
  new_champ->pc = address;
  new_champ->carry = 0;
  new_champ->next = NULL;
  my_imemset(new_champ->registres, 0, 16);
  new_champ->registres[0] = prog_nb;
  return (new_champ);
}

t_vm		*add_champ_to_list(t_vm *vm, char *file_path,
				   int address, int prog_nb)
{
  t_champ	*tmp_champ;

  tmp_champ = vm->champs;
  while (vm->champs != NULL && vm->champs->next != NULL)
    vm->champs = vm->champs->next;
  if (vm->champs == NULL)
    {
      if ((vm->champs = create_champ(file_path, address, prog_nb)) == NULL)
	return (NULL);
    }
  else
    {
      if ((vm->champs->next = create_champ(file_path,
					   address, prog_nb)) == NULL)
	return (NULL);
      vm->champs = tmp_champ;
    }
  return (vm);
}

void		*add_champions(t_vm *vm)
{
  t_prog	*tmp_progs;
  int		i;

  tmp_progs = vm->progs;
  i = 0;
  while (tmp_progs)
    {
      if (add_champ_to_list(vm, tmp_progs->prog_name,
			    tmp_progs->address, tmp_progs->prog_number) == NULL)
	  return (NULL);
      tmp_progs = tmp_progs->next;
      i++;
    }
  return (vm);
}

void		del_champ(t_vm *vm, int i)
{
  t_champ	*tmp;
  t_champ	*tmp2;

  if ((tmp = vm->champs) == NULL)
    return ;
  if (i == 0)
    {
      tmp = tmp->next;
      free(vm->champs);
      vm->champs = tmp;
      return ;
    }
  while (i-- > 1)
    {
      if (vm->champs == NULL)
	return ;
      vm->champs = vm->champs->next;
    }
  if ((tmp2 = vm->champs->next) != NULL)
    vm->champs->next = vm->champs->next->next;
  free(tmp2);
  vm->champs = tmp;
}
