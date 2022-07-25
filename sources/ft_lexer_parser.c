/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:42:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/24 09:50:49 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Initialize my tokens linked-list with NULL.
 * Initialize my AST with NULL as well.
 *
 * linked_list_constructor() : This particular function will build my tokens
 * linked list respecting LEXER grammar [SYNTAXIC ANALYSIS].
 *
 * print_linked_list_tokens() : Linked list debugger.
 *
*/

t_node	*ft_lexer_parser(char *input)
{
	t_node	*ast;
	t_token	*token_list;

	ast = 0x0;
	token_list = 0x0;
	if (linked_list_constructor(input, &token_list) == true)
	{
		print_linked_list_tokens(token_list);
		if (abstract_syntax_tree_constructor(&token_list, &ast, false))
		{
			if (token_list != 0x0)
			{
				variadic_error_printer(2, \
						"Minishell : Syntax error near unexpected token %s\n", \
						token_list->data);
			}
		}
	}
	return (ast);
}
