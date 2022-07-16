# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 10:07:24 by ablaamim          #+#    #+#              #
#    Updated: 2022/07/16 12:19:02 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

READLINE_FLAGS = -lreadline

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRC = ./sources/main.c \
	  ./sources/debug.c \
	  ./sources/variadic_error_printer.c \
	  ./sources/variadic_format_specifier.c \
	  ./sources/libft_utils_00.c \
	  ./sources/variadic_type_converter.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(SRC)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re