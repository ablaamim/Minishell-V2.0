/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:17:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 10:41:36 by ablaamim         ###   ########.fr       */
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
	if (argc == 1)
	{
		/*
		 * Print content of env cache.
		*/
		print_env(env);
	}
	else
	{
		/*
		 * TO DO :
		 *
		 * Create a variadic error print function to print errors on
		 * a given fd with an arbitary number of arguments.
		*/
		printf("Error handing should be managed properly\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
