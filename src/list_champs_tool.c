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
    return (-1);
  if (read(fd, champ, (int)sizeof(t_champ)) < (int)sizeof(t_champ))
    return (-1);
  champ->magic = convert_to_little_endian(champ->magic);
  champ->size = convert_to_little_endian(champ->size);
  return (0);
}

/*
**   add_champt_to_list prend en paramètre un champion (vide et non malloc)
**   le path du champion, et le rempli.
*/
t_champ		*add_champ_to_list(t_champ *champ, char *file_path)
{
  while (champ != NULL)
    champ = champ->next;
  if ((champ = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  if (file_champion(champ, file_path) == -1)
    return (NULL);
  champ->next = NULL;
  printf("[OK]\n");
  return (champ);
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
      if (vm->champs == NULL)
	{
	  if ((vm->champs =
	       add_champ_to_list(vm->champs, tmp_progs->prog_name)) == NULL)
	    return (NULL);
	}
      else
	if ((vm->champs->next =
	     add_champ_to_list(vm->champs, tmp_progs->prog_name)) == NULL)
	  return (NULL);
      tmp_progs = tmp_progs->next;
      i++;
    }
  printf("nombre de progs = %d\n", i);
  return (vm);
}

/*
**  del_champ permet de supprimer un champion dans la liste chainée de champions
**  à la position i.
*/
void		del_champ(t_vm *vm, int i)
{
  t_champ	*tmp;

  tmp = vm->champs;
  if (i == 0)
    {
      vm->champs = vm->champs->next;
      free(tmp);
      return ;
    }
  while (i-- > 1)
    tmp = tmp->next;
  tmp->next = tmp->next->next;
  free(tmp->next);
  return ;
}
