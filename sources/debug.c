/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:24:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/22 22:20:39 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * print content of bash cache via env variable.
*/

void	print_env(char **env)
{
	int	param;

	param = 0x0;
	while (env[param])
	{
		printf("%s\n", env[param]);
		param++;
	}
}

/*
 * Linked list debugger :
*/

void	print_linked_list_tokens(t_token *token)
{
	t_token	*current_token;

	current_token = malloc(sizeof(*token));
	current_token = token;
	if (token  == 0x0)
		variadic_error_printer(2, "LINKED LIST IS EMPTY\n");
	printf("\n================= LINKED LIST DEBUGGER =================\n\n");

	while (current_token != 0x0)
	{
		if (current_token->type == WORD_TOKEN)
			printf("[ WORD_TOKEN");
		else if (current_token->type == DLESSER_TOKEN)
			printf("[ DLESSER_TOKEN");
		else if (current_token->type == PIPE_TOKEN)
			printf("[ PIPE_TOKEN");
		else if (current_token->type == AND_TOKEN)
			printf("[ AND_TOKEN");
		else if (current_token->type == OR_TOKEN)
			printf("[ OR_TOKEN");
		else if (current_token->type == OP_PARENTH_TOKEN)
			printf("[ OP_PARENTH_TOKEN");
		else if (current_token->type == CLOSE_PARENTH_TOKEN)
			printf("[ CLOSE_PARENTH_TOKEN");
		else if (current_token->type == LESSER_TOKEN)
			printf("LESSER_TOKEN");
		else if (current_token->type == DLESSER_TOKEN)
			printf("DLESSER_TOKEN");
		else if (current_token->type == GREATER_TOKEN)
			printf("GREATER_TOKEN");
		else if (current_token->type == DGREATER_TOKEN)
			printf("DGREATER_TOKEN");
		printf(" | Data = ##%s## ]----->", current_token->data);
		current_token = current_token->next;
	}
	if (current_token == 0x0)
		printf("(NULL)\n\n");
	printf("========================================================\n\n");
}
