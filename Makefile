##
## Makefile for Makefile in /home/arnaud_e/rendu/cpe/corewar
##
## Made by Arthur ARNAUD
## Login   <arnaud_e@epitech.net>
##
## Started on  Wed Mar  2 02:57:33 2016 Arthur ARNAUD
## Last update Wed Mar  2 11:06:26 2016 Arthur ARNAUD
##

DEBUG=			yes

SRC_PREFIX=		src/decompiler/

SRC_FILES=		main.c		\
			header.c	\
			my_putstrs.c	\
			my_memset.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

NAME=			decompiler

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

LIB=			-lncurses

OBJ=			$(SRC:.c=.o)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
endif
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled game"
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
