/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_type_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:13:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 12:29:03 by ablaamim         ###   ########.fr       */
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
