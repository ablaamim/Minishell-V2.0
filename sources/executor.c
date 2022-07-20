/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:01:15 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/20 09:24:10 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * initialize my abstract syntax tree, lex and parse content of iput string, 
 * using lexer and recursive descent parser.
*/

void	executor(char *input)
{
	t_node	*ast;

	ast = 0x0;
	if (input != 0x0)
	{
		ast = ft_lexer_parser(input);
		if (ast == 0x0)
			variadic_error_printer(2, "AST IS EMPTY\n");
	}
}
