/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:24:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/20 10:56:39 by ablaamim         ###   ########.fr       */
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
	if (token == 0x0)
		variadic_error_printer(2, "LINKED LIST IS EMPTY\n");
	printf("\n================= LINKED LIST DEBUGGER =================\n\n");
	while (token != 0x0)
	{
		if (token->next == WORD_TOKEN)
			printf("| TYPE = WORD_TOKEN |");
		else
			printf("| UNKNOWN TOKEN |");
		printf("--->");
		token = token->next;
	}
	if (token == 0x0)
		printf("(NULL)\n\n");
	printf("========================================================\n\n");
}
