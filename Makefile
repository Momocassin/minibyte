# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 07:30:46 by edvicair          #+#    #+#              #
#    Updated: 2023/01/20 17:03:49 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g
RL = -lreadline
INC = minishell.h
SRC = 	minishell.c \
		LIB/ft_free.c \
		LIB/lib.c \
		LIB/lib_bis.c \
		LIB/split.c \
		LIB/ft_isalnum.c \
		LIB/ft_atoi.c \
		LIB/ft_itoa.c \
		INIT/init_env.c \
		INIT/init_tok.c \
		INIT/init_redir.c \
		BUILT/cd.c \
		BUILT/pwd.c \
		BUILT/export.c \
		BUILT/export_sort.c \
		BUILT/env.c \
		BUILT/unset.c \
		BUILT/echo.c \
		BUILT/exit.c \
		PARSING/parsing.c \
		PARSING/tokenizator.c \
		PARSING/utils_parsing.c \
		PARSING/syntax.c \
		PARSING/utils_parsing2.c \
		PARSING/sida.c \
		PARSING/expand.c \
		EXEC/child.c \
		EXEC/redir.c \
		EXEC/exec.c 
OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(RL) #-fsanitize=address
	
%.o: %.c
	gcc -g -o $@ -c $< 

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
