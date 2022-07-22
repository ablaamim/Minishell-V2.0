/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_constructor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:58:46 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/22 19:16:14 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Add a token to the linked list of tokens.
*/

void	append_token(t_token *new_token, t_token **token_list)
{
	t_token	*current;

	if (*token_list == 0x0)
		*token_list = new_token;
	else
	{
		current = *token_list;
		while (current->next)
			current = current->next;
		current->next = new_token;
	}
}

/*
 * Dispatch table / array of function pointers, it will call the appropriate
 * tokenizer depending on the type of character encountred in the input string.
 *
 * FOR FURTHER INFOS : check ../includes/minishell.h
*/

t_token	*retrieve_next_token(char *input, int *i)
{
	t_token	*(*tokenizer[NB_CHAR_TYPES])(char *, int *);

	tokenizer[NULL_CHAR] = 0x0;
	tokenizer[ANY_CHAR] = &tokenize_word;
	tokenizer[SPACE_CHAR] = &tokenize_word;
	tokenizer[SQUOTES_CHAR] = &tokenize_word;
	tokenizer[DQUOTES_CHAR] = &tokenize_word;
	tokenizer[AND_CHAR] = &tokenize_and;
	tokenizer[PIPE_CHAR] = &tokenize_pipe;
	tokenizer[OP_PARENTH_CHAR] = &tokenize_parenthesis;
	tokenizer[CLOSE_PARENTH_CHAR] = &tokenize_parenthesis;
	/*
	 * TO DO :
	 *
	 * Create appropriate function to tokenize analyzed types.
	*/
	//tokenizer[PIPE_CHAR] = &tokenize_pipe;
	//tokenizer[OP_PARENTH_TOKEN] = &tokenize_parenthesis;
	//tokenizer[CLOSE_PARENTH_TOKEN] = &tokenize_parenthesis;
	return (tokenizer[define_char_type(input[*i])](input, i));
}

/*
 * This particular function will build a linked list of tokens based on
 * read buffer from readline(), respecting lexer grammar [SYNTAXIC ANALYSIS].
 *
 * ft_iswhite_space() : Will escape all white spaces incountred in scanned
 * input string.
 *
 * retrieve_next_token() : Dispatch table aka array of pointer functions,
 * this function will apply the proper tokenizer depending on the e_char_type
 * encountred inside scanned string.
*/

bool	linked_list_constructor(char *input, t_token **token_list)
{
	t_token	*new_token;
	int		iterator;

	iterator = 0x0;
	while (ft_iswhite_space(input[iterator]))
		++iterator;
	while (input[iterator])
	{
		new_token = retrieve_next_token(input, &iterator);
		if (new_token == 0x0)
			return (false);
		append_token(new_token, token_list);
		while (ft_iswhite_space(input[iterator]))
			++iterator;
	}
	return (true);
}
