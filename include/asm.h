/*
** asm.h for asm in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:09:32 2016 Arthur ARNAUD
** Last update Mon Feb 29 12:35:32 2016 Arthur ARNAUD
*/

#ifndef ASM_H_
# define ASM_H_

typedef struct	s_pos
{
  int	adress;
  int	line;
}

typedef struct	s_arg
{
  char		type;
  char		*link_name;
  int		value;
}		t_arg;

typedef struct	s_label
{
  char		*name;
  int		pos;
}		t_label;

typedef struct		s_action
{
  char			*identifier;
  t_arg			*args;
  struct s_action	*next;
  struct s_action	*prev;
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
