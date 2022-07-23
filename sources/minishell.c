/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:19:17 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/23 15:10:00 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Function that will read input and save history.
*/

char	*read_input(void)
{
	char	*input;

	input = readline("Minishell-V2.0$> ");
	{
		if (input == 0x0)
		{
			variadic_error_printer(2, "exit\0");
			exit(EXIT_FAILURE);
		}
	}
	add_history(input);
	return (input);
}

/*
 * Read command line input via readline() system function in an infinite loop.
 * read_input() : Reads input via readline and saves history using
 * add_history() : system function that will save input history.
*/

void	minishell(void)
{
	char	*input;

	while (1337)
	{
		signal(SIGQUIT, SIG_IGN);
		input = read_input();
		executor(input);
		free(input);
	}
}
