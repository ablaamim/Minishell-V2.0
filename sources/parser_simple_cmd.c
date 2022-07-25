/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 07:14:23 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/25 07:55:53 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	simple_command_parser(t_token **token_list, t_node **ast, bool is_subshell)
{
	t_node	*simple_command;

	if ((*token_list)->type == CLOSE_PARENTH_TOKEN)
		return (false);
	else if ((*token_list)->type == OP_PARENTH_TOKEN)
		return (parser_parenthesis(token_list, ast));
	return (true);
}
