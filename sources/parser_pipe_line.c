/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:42:14 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/28 15:00:11 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	 parse_pipe_line(t_token **token_list, t_node **ast, bool is_subshell)
{
	t_node	*pipe_node;
	t_node	*simple_command;

	if (simple_command_parser(token_list, &simple_command, is_subshell) == false)
		return (false);
	*ast = simple_command;
	return (true);
}
