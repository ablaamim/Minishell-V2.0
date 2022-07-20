/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:19:17 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/20 11:25:37 by ablaamim         ###   ########.fr       */
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
	//printf("%s\n", input);
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
		input = read_input();
		executor(input);
		free(input);
	}
}
