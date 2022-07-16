/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_error_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:42:09 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 14:00:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Variadic function to print given format specifiers on a specified fd.
*/

int	variadic_error_printer(int fd, const char *fmt, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	va_start(ap, fmt);
	str = variadic_format_specifier(fmt, ap);
	len = ft_putstr_fd(fd, str);
	free(str);
	return (len);
}
/*
int	main(void)
{
	//variadic_error_printer(2, "Perc : %%\n");
	//variadic_error_printer(2, "CHAR 0 : %c\n", '@');
	//variadic_error_printer(1, "CHAR 1 : %c\n", '#');
	variadic_error_printer(1,"%s", "Print me!\n");
	//variadic_error_printer(2,"%s\n", NULL);
	//variadic_error_printer(1, "%s", "ERROR\n");
	//while (1);
	return (EXIT_SUCCESS);
}
*/
