/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_char_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:50:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/19 11:55:05 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*token_generator(char *data, enum e_token_type type)
{
	t_token	*new_token;

	new_token = malloc(sizeof(*new_token));
	if (new_token == 0x0)
		return (0x0);
	new_token->data = data;
	new_token->type = type;
	new_token->next = 0x0;
	return (new_token);
}

enum e_char_rules	apply_rules(enum e_char_type char_type)
{
	enum e_char_rules apply_rules[] = {
	[NULL_CHAR] = NOT_ACCEPTED,
	[ANY_CHAR] = ACCEPTED,
	[SPACE_CHAR] = NOT_ACCEPTED,
	[SQUOTES_CHAR] = ACCEPTED,
	[DQUOTES_CHAR] = ACCEPTED
	};

	return (apply_rules[char_type]);
}

enum e_char_rules	verifier(char c, bool *squotes_found, bool *dquotes_found)
{
	enum e_char_type	char_type;

	char_type = define_char_type(c);
	if (*squotes_found == false && *dquotes_found == false)
	{
		if (char_type == SQUOTES_CHAR)
			*squotes_found = true;
		else if (char_type == DQUOTES_CHAR)
			*dquotes_found = true;
	}
	else
	{
		if (char_type == NULL_CHAR)
			return (NOT_ACCEPTED);
		if (char_type == SQUOTES_CHAR && *squotes_found == true)
			*squotes_found = false;
		else if (char_type == DQUOTES_CHAR && *dquotes_found == true)
			*dquotes_found = false;
		return (NOT_ACCEPTED);
	}
	return (apply_rules(char_type));
}

t_token	*tokenize_word(char *input, int *i)
{
	char	*data;
	int		j;
	bool	squotes_found;
	bool	dquotes_found;

	j = 0x0;
	dquotes_found = false;
	squotes_found = false;
	data = malloc (sizeof(*data));
	if (data == 0x0)
		return (0x0);
	*data = '\0';
	while (verifier(input[*i + j], &squotes_found, &dquotes_found) == ACCEPTED)
		++j;
	if (input[*i + j] == '\0' && (squotes_found == true || dquotes_found == true))
	{
		variadic_error_printer(2, "Minishell : syntax error unexpected end of file");
		free(data);
		return (0x0);
	}
	data = ft_strndup(input + *i, j);
	*i += j;
	return (token_generator(data, WORD_TOKEN));
}

enum e_char_type	define_char_type(char c)
{
	enum e_char_type	char_type[128] = {
		ANY_CHAR,
	['\t'...'\r'] = SPACE_CHAR,
	[' '] = SPACE_CHAR,
	['\''] = SQUOTES_CHAR,
	['\"'] = DQUOTES_CHAR,
	};

	if (c == '\0')
		return (NULL_CHAR);
	return(char_type[(int) c]);
}