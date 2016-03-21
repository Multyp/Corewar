#ifndef __VM_COREWAR_H__
#define __VM_COREWAR_H__

# include <stdio.h>
# include "libmy.h"

# define MALLOC_FAILED "Error: Malloc Failed"
# define INVALID_OPTION "Error: Invalid option, try to use --help"
# define OPEN_FAILED(file_name) "Error: Could not open file "#file_name
# define INVALID_FILE(file_name) "Error: "#file_name" is not a corewar executable"
# define USED_PROGNUMBER(x) "Error: Prog number "(x)" already used"
# define PLAYER_ALIVE(player_name) "Player "#player_name" is alive"
# define PLAYER_WIN(winner_name) "Player "#winner_name" wins"

typedef struct		s_champ
{

  struct s_champ	*next;
}			t_champ;

typedef struct		s_vm
{

  t_champ		*champ;
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
/*
** Commands
*/
int	show_help(t_vm *, char *);
int	my_dump_memory(t_vm *, char *);
int	my_load_address(t_vm *, char *);
int	my_next_prognumber(t_vm *, char *);

# endif /* _VM_COREWAR_H__ */
