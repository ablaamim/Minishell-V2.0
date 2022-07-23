/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word_and_separators.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:51:12 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/23 14:07:29 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*tokenize_word(char *input, int *i)
{
	char	*data;
	int		j;
	bool	squoted;
	bool	dquoted;

	j = 0x0;
	squoted = false;
	dquoted = false;
	data = malloc(sizeof(*data));
	if (data == 0x0)
		return (0x0);
	*data = '\0';
	while (verifier(input[*i + j], &squoted, &dquoted) == ACCEPTED)
		++j;
	if (input[*i + j] == '\0' && (squoted == true || dquoted == true))
	{
		variadic_error_printer(2, \
				"Minishell : syntax error unexpected end of file\n");
		free(data);
		return (0x0);
	}
	data = ft_strndup(input + *i, j);
	*i += j;
	return (token_generator(data, WORD_TOKEN));
}

t_token	*tokenize_and(char *input, int *i)
{
	enum  e_token_type	type;
	char				*data;

	if (define_char_type(input[++(*i)]) == AND_CHAR)
	{
		data = malloc(sizeof(*data) * 3);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, "&&\0", 3);
		type = AND_TOKEN;
		++(*i);
	}
	else
	{
		variadic_error_printer(2, "This feature is not supported\n");
		return (0x0);
	}
	return (token_generator(data, type));
}

t_token	*tokenize_pipe(char *input, int *i)
{
	enum e_token_type	type;
	char				*data;

	if (define_char_type(input[++(*i)]) == PIPE_CHAR)
	{
		data = malloc(sizeof(*data) * 3);
		if (data == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return (0x0);
		}
		ft_memcpy(data, "||\0", 3);
		type = OR_TOKEN;
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
		ft_memcpy(data, "|\0", 2);
		type = PIPE_TOKEN;
	}
	return (token_generator(data, type));
}

t_token	*tokenize_parenthesis(char *input, int *i)
{
	char				*data;
	enum e_token_type	type;

	if (input[*i] == '(')
		type = OP_PARENTH_TOKEN;
	else
		type = CLOSE_PARENTH_TOKEN;
	data = malloc(sizeof(*data) * 2);
	if (data == 0x0)
	{
		variadic_error_printer(2, "Error : malloc() failed\n");
		return (0x0);
	}
	if (input[*i] == '(')
		ft_memcpy(data, "(\0", 2);
	else
		ft_memcpy(data, ")\0", 2);
	printf("Occurence = %c\n", input[*i]);
	++(*i);
	return (token_generator(data, type));
}
