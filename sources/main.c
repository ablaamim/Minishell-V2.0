/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:17:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 14:28:26 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Entry point of my program :
 *
 * Utility :
 *
 * ==> Init and launch all processes :
 *
 * ==> Error handling of arguments :
 *
 * If : argc == 1 we launch our program.
 * Else : error handling.
 *
*/

int	main(int argc, char **argv, char **env)
{
	(void)	argv;
	(void)	env;
	if (argc == 1)
	{
		/*
		 * Print content of env cache.
		*/
		//print_env(env);
		/*
		 * Core function :
		*/
		minishell();
	}
	else
	{
		/*
		 * TO DO :
		 *
		 * Create a variadic error print function to print errors on
		 * a given fd with an arbitary number of arguments.
		*/
		variadic_error_printer(2, "Error : Invalid argument\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
