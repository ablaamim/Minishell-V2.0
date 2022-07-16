/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_format_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:50:39 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 11:02:50 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*variadic_format_specifier(const char *str, va_list ap)
{
	int			iterator;
	t_buffering	format;

	iterator = 0x0;
	format.i = 0x0;
	bzero(format.buffer, BUFFERING_SIZE);
	while (str[iterator] != '\0')
	{
		iterator++;
	}
	return (strdup(format.buffer));
}
