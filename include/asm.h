/*
** asm.h for asm in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:09:32 2016 Arthur ARNAUD
** Last update Tue Mar 22 16:57:39 2016 Arthur ARNAUD
*/

#ifndef ASM_H_
# define ASM_H_

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_012345678"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define REG_NUMBER 16
# define REG_SIZE 1
# define IND_SIZE 2
# define DIR_SIZE 4
# define PROG_NAME_SIZE 128
# define COMMENT_LENGTH 2048

typedef struct		s_header
{
  int	magic;
  char	prog_name[PROG_NAME_SIZE + 1];
  int	prog_size;
  char	comment[COMMENT_LENGTH + 1];
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
  int			pos_link;
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
  char			identifier;
  char			*instruction;
  t_arg			*args;
  struct s_action	*next;
}			t_action;

typedef int	(*t_ftab)(t_action *, char **tab, t_pos *);

/*
** ================================
**              INIT
** ================================
*/
t_label		*create_label_list();
t_action       	*create_action_list();
t_file		*create_file_list();
t_ftab		*set_ftab(t_ftab *);
/*
** ================================
**              LEXER
** ================================
*/
char		*add_to_label(char *, int, t_label *, int);
char		*check_label(char *, t_label *, t_pos *);
char		*format_instruction(char *);
char		**cut_instruction(char *);
int		add_action(t_action *, t_action *);
int		is_valid_label(char *, int);
int		is_char_valid(char, char *);
int		add_to_back(t_file *, char *);
int		check_action(char *, t_action *, t_pos *, t_ftab *);
int		get_header(char *, t_header *);
int		lexer(t_label *, t_action *, t_header *, int);
/*
** ================================
**              LIB
** ================================
*/
char		**str_to_word_tab(char *,  char);
char		*epur_str(char *);
char		*get_line_not_empty(int, int *);
char		*get_next_line(int);
char		*my_strdup(char *);
int		check_empty(char *);
int		my_memset(void *, char , int);
int		my_putstr(char *);
int		my_strlen(char *);
int		my_strcpy(char *, char *);
int		my_strncmp(char *, char *, int);
void		*free_first(t_file *);
void		showtab(char **);

#endif /* !ASM_H_*/
