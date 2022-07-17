/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:17:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/17 15:09:30 by ablaamim         ###   ########.fr       */
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
		 * Core functions :
		*/
		/*
		 * Init bash environment :
		*/
		printf("===================== ENV DATA =========================\n\n");
		initialize_bash_env(env);
		printf("========================================================\n\n");
		/*
		 * Core function that will read commnd line input via readline().
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
