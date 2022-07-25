# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 10:07:24 by ablaamim          #+#    #+#              #
#    Updated: 2022/07/24 10:45:44 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

READLINE_FLAGS = -lreadline

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = ./sources/main.c \
	  ./sources/debug.c \
	  ./sources/variadic_error_printer.c \
	  ./sources/variadic_format_specifier.c \
	  ./sources/libft_utils_00.c \
	  ./sources/variadic_type_converter.c \
	  ./sources/libft_utils_01.c \
	  ./sources/minishell.c \
	  ./sources/initialize_bash_env.c \
	  ./sources/env_utils.c \
	  ./sources/executor.c \
	  ./sources/ft_lexer_parser.c \
	  ./sources/linked_list_constructor.c \
	  ./sources/define_char_type.c \
	  ./sources/tokenize_word_and_separators.c \
	  ./sources/tokenize_redirections.c \
	  ./sources/abstract_syntax_tree_constructor.c \
	  ./sources/tokenizer_utils.c \
	  ./sources/tokens_identifier.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(SRC)
		$(CC) $(CFLAGS) $(SRC) $(READLINE_FLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
