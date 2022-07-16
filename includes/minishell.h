/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 11:01:46 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

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

/*
 * Error handling defines/Structs/functions :
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

#endif
