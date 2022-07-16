/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_type_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:13:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 14:06:36 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	converter_percentage(t_buffering *format, va_list ap)
{
	(void)	ap;
	format->buffer[format->i++] = '%';
}

void	converter_character(t_buffering *format, va_list ap)
{
	int	c;

	c = (char) va_arg(ap, int);
	format->buffer[format->i++] = c;
}

void	converter_string(t_buffering *format, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0x0)
		str = "(null)";
	len = ft_strlen(str);
	ft_strcpy(&format->buffer[format->i], str);
	format->i += len;
}
