/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_logical_operators.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:00:17 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/28 14:47:23 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	parse_logical_operators(t_token **token_list, t_node **ast, \
		bool is_subshell)
{
	t_node	*node_separator;

	if (*ast == 0x0)
		return (0x0);
	node_separator = 0x0;
	node_separator = malloc(sizeof(*node_separator));
	if (node_separator == 0x0)
	{
		variadic_error_printer(2, "Error : malloc() failed\n");
		return (false);
	}
	ft_bzero(node_separator, sizeof(*node_separator));
	node_separator->type = (enum e_node_type) ((*token_list)->type);
	node_separator->content.child.left = *ast;
	*ast = node_separator;
	devour_token(token_list);
	return (parse_pipe_line(token_list, &(node_separator->content.child.right), \
				is_subshell));
}
