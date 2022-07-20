/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:42:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/20 09:31:30 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*ft_lexer_parser(char *input)
{
	t_node	*ast;
	t_token	*token_list;

	ast = 0x0;
	token_list = 0x0;
	if (linked_list_constructor(input, &token_list) == true)
	{
		/*
		 * TO DO :
		 *
		 * CREATE A DEBUGGER.
		*/
		//printf("Linked list built, i have to print it next !\n");
		print_linked_list_tokens(token_list);
	}
	return (ast);
}
