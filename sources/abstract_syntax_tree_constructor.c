/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_syntax_tree_constructor.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:21:13 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/25 07:09:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	abstract_syntax_tree_constructor(t_token **token_list, t_node **ast, \
		bool is_subshell)
{
	bool	ret;

	ret = true;
	while (*token_list != 0x0)
	{
		/*
		 * TO DO :
		 * ==> check if  logical accures in tokens seperators.
		 * ==> parse logical operators.
		 * ==> parse pipelines.
		*/
		if (check_logical_operators((*token_list)->type) == true)
		{
			if (*ast == 0x0)
				return (false);
			//ret = parse_logical_operators(token_list, is_subshell);
		}
	}
	return (true);
}
