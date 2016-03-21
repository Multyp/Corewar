#ifndef __VM_COREWAR_H__
#define __VM_COREWAR_H__

# include <stdio.h>
# include <stdbool.h>
# include "libmy.h"

# define MALLOC_FAILED "Error: Malloc Failed"
# define INVALID_OPTION "Error: Invalid option, try to use --help"
# define OPEN_FAILED(file_name) "Error: Could not open file "#file_name
# define INVALID_FILE(file_name) "Error: "#file_name" is not a corewar executable"
# define USED_PROGNUMBER(x) "Error: Prog number "#x" already used"
# define PLAYER_ALIVE(player_name) "Player "#player_name" is alive"
# define PLAYER_WIN(winner_name) "Player "#winner_name" wins"

typedef struct		s_prog
{
  int			prog_number;
  unsigned int		address;
  char			*prog_name;
  struct s_prog		*next;
}			t_prog;

typedef struct		s_champ
{
  int			magic;
  char			name[128];
  int			size;
  char			comment[2048];
  struct s_champ	*next;
}			t_champ;

typedef struct		s_vm
{
  int			dump;
  bool			prog_opts[3];
  int			progs_nb;
  t_prog		*progs;
  t_champ		*champs;
}			t_vm;

/*
** ***********
** * OPTIONS *
** ***********
*/
/*
** Parsing
*/
int	check_options(char **, t_vm *, int);
char	*get_binary(char *);
void	init_bool_opts(t_vm *);
int	check_bool_opts(t_vm *);
/*
** Commands
*/
int	show_help(t_vm *, char *);
int	my_dump_memory(t_vm *, char *);
int	my_load_address(t_vm *, char *);
int	my_get_prognumber(t_vm *, char *);

# endif /* _VM_COREWAR_H__ */
