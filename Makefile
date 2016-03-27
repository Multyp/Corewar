##
## Makefile for Makefile in /home/arnaud_e/rendu/cpe/corewar
##
## Made by Arthur ARNAUD
## Login   <arnaud_e@epitech.net>
##
## Started on  Wed Mar  2 02:57:33 2016 Arthur ARNAUD
## Last update Sun Mar 27 23:16:31 2016 Poc
##

POC=			no

DEBUG=			no

SRC_VM	=		main_vm_corewar.c	\
			options.c		\
			default_opts.c		\
			list_manage_tool.c	\
			my_getnbr.c		\
			game_check_steps.c	\
			check_champs_cors.c	\
			aff_winner.c		\
			put_champs_in_map.c	\
			list_champs_tool.c	\
			change_endian.c		\
			pc_correction.c		\
			free.c			\
			displays.c		\
			free_champions.c	\
			get_base_16.c		\
			check_champs_size.c	\
			default_addr.c		\
			progs_sorting.c		\
			addr_get.c		\
			options_cmds.c		\
			functions_calls.c	\
			live_function.c		\
			ld_function.c		\
			st_function.c		\
			add_function.c		\
			sub_function.c		\
			and_function.c		\
			or_function.c		\
			xor_function.c		\
			zjmp_function.c		\
			ldi_function.c		\
			sti_function.c		\
			fork_function.c		\
			lld_function.c		\
			lldi_function.c		\
			lfork_function.c	\
			aff_function.c		\
			octet_codage.c		\
			init_ops.c

BASICS  =		my_memset.c		\
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


SRC_FILES_ASM=		add_to_list.c		\
			add_label.c		\
			add_prog_size.c		\
			check_args.c		\
			check_label.c		\
			check_type.c		\
			create_list.c		\
			fill_arg.c		\
			free_lists.c		\
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
			write_types.c		\
			write_indirects.c	\
			change_to_odds.c	\
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

SRC_FILES_LIB=		change_endian.c		\
			check_empty.c		\
			convert_to_nb.c		\
			epur.c			\
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
			str_to_word_tab.c	\

SRC_LIB=		$(addprefix src/lib/,$(SRC_FILES_LIB))

SRC_ASM=		$(addprefix src/compiler/,$(SRC_FILES_ASM))

OBJ_VM= 		$(addprefix src/src_vm/, $(SRC_VM:.c=.o))

OBJLIB= 		$(addprefix basics/, $(BASICS:.c=.o))

OBJ_LIB=		$(SRC_LIB:.c=.o)

NAME_VM	= 		corewar/corewar

LIBNAME	= 		libmy.a

NAME=			asm/asm

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror
endif

ifeq ($(POC), yes)
	CC =		clang
else
	CC = 		gcc
endif

RM=			rm -f

OBJ_ASM=		$(SRC_ASM:.c=.o)

all:			$(NAME)

$(NAME_VM):		$(LIBNAME) $(OBJ_VM)
			@ $(CC) $(OBJ_VM) -o $(NAME_VM) $(LIBNAME)
			@ echo -e "\033[1;33m \t \t \n \t ♩♪♫ $(NAME_VM) \033[1;33m Compiled Sucesfully ♩♪♫\033[0m "

$(NAME):		$(NAME_VM) $(OBJ_ASM) $(OBJ_LIB)
			@$(CC) $(OBJ_ASM) $(OBJ_LIB) -o asm/asm
			@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(NAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m "

$(LIBNAME):		$(OBJLIB)
			ar rc $(LIBNAME) $(OBJLIB)
			@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(LIBNAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m "

clean:
			@echo "[ OK ] Removing OBJ files ..."
			@$(RM) $(OBJ_DECOMPILER)
			@$(RM) $(OBJ_ASM)
			@$(RM) $(OBJ_LIB)
			@$(RM) $(OBJ_VM)
			@$(RM) $(OBJLIB)

fclean:			clean
			@echo "[ OK ] Deleting binaries ..."
			@$(RM) $(NAME)
			@$(RM) $(NAME_VM)
			@$(RM) $(LIBNAME)

re:			fclean all

%.o:			%.c
			@echo "[ OK ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS)


.PHONY:			all clean fclean re
