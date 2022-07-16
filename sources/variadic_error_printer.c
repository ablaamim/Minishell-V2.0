/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_error_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:42:09 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 10:49:43 by ablaamim         ###   ########.fr       */
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
	return (len);
}

int	main(void)
{

	return (EXIT_SUCCESS);
}
