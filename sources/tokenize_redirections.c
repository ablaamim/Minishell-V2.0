/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:33:17 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/22 22:10:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*tokenize_lesser(char *input, int *i)
{
	char				*data;
	enum e_token_type	type;

	if (define_char_type(input[++(*i)]) == LESS_CHAR)
	{
		data = malloc(sizeof(*data) * 3);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, "<<\0", 3);
		type = DLESSER_TOKEN;
		++(*i);
	}
	else
	{
		data = malloc(sizeof(*data) * 2);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, "<\0", 2);
		type = LESSER_TOKEN;
		++(*i);
	}
	return (token_generator(data, type));
}

t_token	*tokenize_greater(char *input, int *i)
{
	char				*data;
	enum e_token_type	type;

	if (define_char_type(input[++(*i)]) == GREAT_CHAR)
	{
		data = malloc(sizeof(data) * 3);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, ">>\0", 3);
		type = DGREATER_TOKEN;
		++(*i);
	}
	else
	{
		data = malloc(sizeof(*data) * 2);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, ">\0", 2);
		type = GREATER_TOKEN;
		++(*i);
	}
	return (token_generator(data, type));
}
