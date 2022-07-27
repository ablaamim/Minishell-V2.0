/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 07:56:37 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/27 19:54:08 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*start_before_parenth_matching(t_token *token_list)
{
	int		parenth_counter;
	t_token	*previous;

	parenth_counter = 0x1;
	previous = token_list;
	token_list = token_list->next;
	while (token_list != 0x0)
	{
		if (token_list->type == OP_PARENTH_TOKEN)
			++parenth_counter;
		else if (token_list->type == CLOSE_PARENTH_TOKEN)
		{
			--parenth_counter;
			if (parenth_counter == 0x0)
				return (previous);
		}
		previous = token_list;
		token_list = token_list->next;
	}
	return (0x0);
}

bool	devour_token_and_ret_false(t_token **token_list)
{
	devour_token(token_list);
	return (false);
}

bool	parser_parenthesis(t_token **token_list, t_node **ast)
{
	t_token	*before_parenth_matching;
	t_token	*sub_tree;
	t_token	*sub_token_list;

	if ((*token_list)->next != 0x0 && (*token_list)->type == CLOSE_PARENTH_TOKEN)
		return (devour_token_and_ret_false(token_list));
	before_parenth_matching = start_before_parenth_matching(*token_list);
	devour_token(token_list);
	if (before_parenth_matching == 0x0)
	{
		tokens_free(token_list);
		return (print_err_and_return(*token_list));
	}
	sub_token_list = *token_list;
	*token_list = before_parenth_matching->next->next;
	return (true);
}
