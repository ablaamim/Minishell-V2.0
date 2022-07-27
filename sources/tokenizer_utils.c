/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:37:40 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/27 19:50:10 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	print_err_and_return(t_token *token)
{
	if (token == NULL)
		variadic_error_printer(2,
			"\nminishell: syntax error: unexpected end of file\n");
	else
		variadic_error_printer(2,
			"\nminishell: syntax error near unexpected token `%s'\n",
			token->data);
	return (false);
}

void	tokens_free(t_token **token_list)
{
	t_token	*previous;
	t_token	*current;

	if (*token_list == 0x0)
		return ;
	current = *token_list;
	while (current)
	{
		free(current->data);
		previous = current;
		free(previous);
	}
	token_list = 0x0;
}

void	devour_token(t_token **token_list)
{
	t_token	*tmp;

	tmp = *token_list;
	if (*token_list == 0x0)
		return ;
	*token_list = (*token_list)->next;
	free(tmp->data);
	free(tmp);
}
