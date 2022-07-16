/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:19:17 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 14:28:59 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*read_input(void)
{
	char *input;

	input = readline("Minishell-V2.0$> ");
	printf("%s\n", input);
	add_history(input);
	return (input);
}

void	minishell(void)
{
	char	*input;

	while (1337)
	{
		input = read_input();
		free(input);
	}
}
