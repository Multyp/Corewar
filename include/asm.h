/*
** asm.h for asm in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:09:32 2016 Arthur ARNAUD
** Last update Wed Mar 16 19:23:05 2016 Clement Peau
*/

#ifndef ASM_H_
# define ASM_H_

typedef struct		s_header
{
  int	magic;
  char	prog_name[128 + 1];
  int	prog_size;
  char	comment[2048 + 1];
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

typedef struct		s_action
{
  int			coding_byte;
  char			*identifier;
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

/*
** ================================
**              LEXER
** ================================
*/
void	lexer(t_label *, t_action *);
char	**str_to_word_tab(char *, char);
char	**check_label(char *, t_label *, int);
int	check_action(char *, t_action *);

#endif /* !ASM_H_*/
