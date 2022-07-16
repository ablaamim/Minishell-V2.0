/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_format_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:50:39 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 12:27:46 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		variadic_type_recognizer(char type, va_list ap, t_buffering *format)
{
	int	iterator;

	iterator = 0x0;
	t_converter const convert[] = {
	{.type = '%', .function = &converter_percentage},
	{.type = 'c', .function = &converter_character},
	{.type = '\0'}
	};
	while (convert[iterator].type != type && convert[iterator].type != 0x0)
		iterator++;
	if (convert[iterator].type == '\0')
		return (-1);
	convert[iterator].function(format, ap);
	return (0x0);
}

char	*variadic_format_specifier(const char *str, va_list ap)
{
	int			iterator;
	t_buffering	format;

	iterator = 0x0;
	format.i = 0x0;
	ft_bzero(format.buffer, BUFFERING_SIZE);
	while (str[iterator] != '\0')
	{
		if (str[iterator] == '%')
		{
			if (variadic_type_recognizer(str[++iterator], ap, &format) == -1)
				return (0x0);
		}
		else
			format.buffer[format.i++] = str[iterator];
		iterator++;
	}
	return (ft_strdup(format.buffer));
}
