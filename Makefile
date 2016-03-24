##
## Makefile for Makefile in /home/arnaud_e/rendu/cpe/corewar
##
## Made by Arthur ARNAUD
## Login   <arnaud_e@epitech.net>
##
## Started on  Wed Mar  2 02:57:33 2016 Arthur ARNAUD
## Last update Thu Mar 24 17:39:16 2016 Poc
##

POC=			yes

DEBUG=			yes

SRC_FILES_DECOMPILER=	main.c			\
			header.c		\
			fill_file.c		\
			check_codage.c		\
			set_ftab.c		\
			new_name.c		\
			op_live.c		\
			op_add.c		\
			op_aff.c		\
			op_and.c		\
			op_fork.c		\
			op_ld.c			\
			op_ldi.c		\
			op_lfork.c		\
			op_lld.c		\
			op_lldi.c		\
			op_or.c			\
			op_st.c			\
			op_sti.c		\
			op_sub.c		\
			op_xor.c		\
			op_zjmp.c		\

SRC_DECOMPILER=		$(addprefix src/decompiler/,$(SRC_FILES_DECOMPILER))

SRC_FILES_ASM=		add_to_list.c		\
			add_label.c		\
			add_prog_size.c		\
			check_args.c		\
			check_label.c		\
			check_type.c		\
			create_list.c		\
			fill_arg.c		\
			get_header.c		\
			is_char.c		\
			lexer.c			\
			main.c			\
			format_instruction.c	\
			check_action.c		\
			init_args.c		\
			print_error.c		\
			parser.c		\
			set_ftab.c		\
			write_action.c		\
			write_header.c		\
			op/op_live.c		\
			op/op_ld.c		\
			op/op_st.c		\
			op/op_add.c		\
			op/op_sub.c		\
			op/op_and.c		\
			op/op_or.c		\
			op/op_xor.c		\
			op/op_zjmp.c		\
			op/op_ldi.c		\
			op/op_sti.c		\
			op/op_fork.c		\
			op/op_lld.c		\
			op/op_lldi.c		\
			op/op_lfork.c		\
			op/op_aff.c

SRC_ASM=		$(addprefix src/compiler/,$(SRC_FILES_ASM))

SRC_FILES_LIB=		change_endian.c		\
			check_empty.c		\
			convert_to_nb.c		\
			epur.c			\
			free_first.c		\
			free_tab.c		\
			get_next_line.c		\
			my_getnbr.c		\
			my_putnbr_file.c	\
			my_putstrs.c		\
			my_putnbr.c		\
			my_memset.c		\
			my_showtab.c		\
			my_strcat.c		\
			my_strcmp.c		\
			my_strcpy.c		\
			my_strdup.c		\
			my_strlen.c		\
			my_strncmp.c		\
			show_list.c		\
			str_to_word_tab.c	\

SRC_LIB=		$(addprefix src/lib/,$(SRC_FILES_LIB))

OBJ_LIB=		$(SRC_LIB:.c=.o)

NAME=			asm

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

ifeq ($(POC), yes)
	CC =		clang
else
	CC = 		gcc
endif

RM=			rm -f

OBJ_DECOMPILER=		$(SRC_DECOMPILER:.c=.o)

OBJ_ASM=		$(SRC_ASM:.c=.o)

$(NAME):		$(OBJ_ASM) $(OBJ_LIB)
			@echo "[ OK ] Soft Compiled"
			@$(CC) $(OBJ_ASM) $(OBJ_LIB) -o asm

%.o:			%.c
			@echo "[ OK ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS)

all:			$(NAME)

clean:
			@echo "[ OK ] Removing OBJ files ..."
			@$(RM) $(OBJ_DECOMPILER)
			@$(RM) $(OBJ_ASM)
			@$(RM) $(OBJ_LIB)

fclean:			clean
			@echo "[ OK ] Deleting binaries ..."
			@$(RM) $(NAME)
			@$(RM) decompiler

re:			fclean all

decompiler:		$(OBJ_DECOMPILER) $(OBJ_LIB)
			@$(CC) -o decompiler $(OBJ_DECOMPILER) $(OBJ_LIB)
			@echo "[ OK ] Decompiler Compiled"

.PHONY:			all clean fclean re
