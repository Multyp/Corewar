/*
** asm.h for asm in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:09:32 2016 Arthur ARNAUD
** Last update Fri Mar 18 16:58:48 2016 Clement Peau
*/

#ifndef ASM_H_
# define ASM_H_

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_header
{
  int	magic;
  char	prog_name[128 + 1];
  int	prog_size;
  char	comment[2048 + 1];
  int	full;
}			t_header;

typedef struct		s_pos
{
  int	prog_size;
  int	line;
}			t_pos;

typedef struct		s_arg
{
  char			type;
  char			*link_name;
  int			value;
  struct s_arg		*next;
}			t_arg;

typedef struct		s_label
{
  char			*name;
  int			pos;
  struct s_label	*next;
}			t_label;

typedef struct		s_file
{
  char			*str;
  struct s_file		*next;
}			t_file;

typedef struct		s_action
{
  int			coding_byte;
  char			*identifier;
  char			*str;
  t_arg			*args;
  struct s_action	*next;
}			t_action;

/*
** ================================
**              INIT
** ================================
*/
t_label		*create_label_list();
t_action	*create_action_list();
t_file		*create_file_list();
/*
** ================================
**              LEXER
** ================================
*/
char	**str_to_word_tab(char *, char);
char	**check_label(char *, t_label *, int);
int	add_to_back(t_file *, char *);
int	get_header(t_header *, char *);
int	lexer(t_label *, t_action *, t_header *, char *);

/*
** ================================
**              LIB
** ================================
*/
char	*epur_str(char *);
char	*get_line_not_empty(int);
char	*get_next_line(int);
int	check_empty(char *);
int	my_memset(void *, char , int);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_strcpy(char *, char *);
int	my_strncmp(char *, char *, int);
void	*free_first(t_file *);

#endif /* !ASM_H_*/
