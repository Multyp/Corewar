/*
** list_champs_tool.c for list_champs in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:57:03 2016 Da Fonseca Samuel
** Last update Sat Mar 26 09:25:21 2016 Marwane
*/

#include "vm_corewar.h"

/*
**  file_champion lis les 2184 octets contenu dans un fichier et remplis
**  dans champ (cf structure : include/vm_corewar.h") toutes les informations
**  contenu dans celui ci sur les 2184 octets.
*/
int		file_champion(t_champ *champ, char *file_path)
{
  int		fd;

  if ((fd = open(file_path, O_RDONLY)) == -1)
    {
      return (my_error(OPEN_FAILED(fle_path)));
      close(fd);
    }
  if (read(fd, champ, (int)sizeof(t_champ)) < 2192)
    {
      champ->name[0] = 0;
      champ->magic = -1;
      champ->size = -1;
      champ->comment[0] = 0;
      champ->pc = -1;
      champ->alive = false;
      champ->cycles_to_wait = 0;
      close(fd);
      return (0);
    };
  champ->magic = convert_to_little_endian(champ->magic);
  champ->size = convert_to_little_endian(champ->size);
  champ->alive = false;
  champ->cycles_to_wait = 0;
  close(fd);
  return (0);
}

t_champ		*create_champ(char *file_path, int address)
{
  t_champ	*new_champ;

  if ((new_champ = malloc(sizeof(t_champ))) == NULL)
    return (my_perror(MALLOC_FAILED));
  if (file_champion(new_champ, file_path) == 1)
    {
      free (new_champ);
      return (NULL);
    }
  new_champ->pc = address;
  new_champ->next = NULL;
  return (new_champ);
}

/*
**   add_champt_to_list prend en paramètre un champion (vide et non malloc)
**   le path du champion, et le rempli.
*/
t_vm		*add_champ_to_list(t_vm *vm, char *file_path, int address)
{
  t_champ	*tmp_champ;

  tmp_champ = vm->champs;
  while (vm->champs != NULL && vm->champs->next != NULL)
    vm->champs = vm->champs->next;
  if (vm->champs == NULL)
    vm->champs = create_champ(file_path, address);
  else
    {
      vm->champs->next = create_champ(file_path, address);
      vm->champs = tmp_champ;
    }
  return (vm);
}

/*
**  add_champion ajoute tous les programmes contenu dans t_prog dans la
**  liste chainee t_champ, add_champions ne corrige pas les erreurs des
**  progs (cf : check_champs_cors.c)
*/
void		*add_champions(t_vm *vm)
{
  t_prog	*tmp_progs;
  int		i;

  tmp_progs = vm->progs;
  i = 0;
  while (tmp_progs)
    {
      if (add_champ_to_list(vm, tmp_progs->prog_name,
			    tmp_progs->address) == NULL)
	return (NULL);
      tmp_progs = tmp_progs->next;
      i++;
    }
  return (vm);
}

/*
**  del_champ permet de supprimer un champion dans la liste chainée de champions
**  à la position i.
*/
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
