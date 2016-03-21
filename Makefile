## Makefile for Makefile in /home/khsime_m/rendu/Projet/PSU/PSU_2015_minishell1
##
## Made by marwane khsime
## Login   <khsime_m@epitech.net>
##
## Started on  Fri Jan  8 02:57:27 2016 marwane khsime
## Last update Sun Mar 20 15:40:49 2016 marwane khsime
##

RM	= rm -f

CC	= gcc

SRC	=	main_vm_corewar.c	\
		bool_options.c		\
		options.c		\
		options_cmds.c

BASICS  =	my_memset.c		\
		my_revstr.c		\
		my_strcmp.c		\
		my_strseek.c		\
		my_getbase.c		\
		my_putc.c		\
		my_realloc.c		\
		my_strcat.c		\
		my_strcat_cpy.c		\
		my_strcpy.c		\
		my_str_to_wordtab.c   	\
		my_showtabs.c 		\
		my_putnbr.c		\
		my_printf.c		\
		my_strdup.c		\
		my_error.c

OBJ	= $(addprefix src/, $(SRC:.c=.o))

OBJLIB  = $(addprefix basics/, $(BASICS:.c=.o))

CFLAGS	= -W -Werror -Wall -I./include -g3

NAME	= vm_corewar

LIBNAME	= libmy.a

name: 	lib proj

lib:	$(OBJLIB)
	ar rc $(LIBNAME) $(OBJLIB)
	@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(LIBNAME) da-fon_s\033[0;31m®\033[1;31m Created Sucesfully \033[0m "

proj:	$(OBJ)
	@ $(CC) $(OBJ) -o $(NAME) $(LIBNAME)
	@ echo -e "\033[1;33m \t \t \n \t ♩♪♫ $(NAME) \033[1;33m Compiled Sucesfully ♩♪♫\033[0m "

all:	name

clean:
	$(RM) $(OBJ) $(OBJLIB)

fclean:	clean
	$(RM) $(NAME) $(LIBNAME)

re:	fclean all
