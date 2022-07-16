/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 14:28:51 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
 * Core functions :
*/

/*
 *int		main(int argc, char **argv, char **env);
*/

/*
 * Debugers :
*/

void	print_env(char **env);
void	minishell(void);
char	*read_input(void);

/*
 * Libft_utils :
*/

char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	*ft_memset(void *memory, int c, size_t n);
void	ft_bzero(void *memory, size_t size);
int		ft_putstr_fd(int fd, char *str);
char	*ft_strcpy(char *dest, char *src);

/*
 * Error handling utils :
*/

#define BUFFERING_SIZE 4096

typedef struct s_buffering
{
	int		i;
	char	buffer[BUFFERING_SIZE];
}	t_buffering;

typedef struct s_converter
{
	char	type;
	void	(*function)(t_buffering *, va_list);
}	t_converter;

int		variadic_error_printer(int fd, const char *fmt, ...);
char	*variadic_format_specifier(const char *str, va_list ap);
void	converter_percentage(t_buffering *format, va_list ap);
void	converter_character(t_buffering *format, va_list ap);
void	converter_string(t_buffering *format, va_list ap);

#endif
