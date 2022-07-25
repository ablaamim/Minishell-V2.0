/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:17:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/25 07:44:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Entry point of minishell program :
 *
 * Utility :
 *
 * ==> Error handling of arguments :
 *
 * If : argc == 1 we launch our program [Normal behavior].
 * Else : error handling [Output an error message using
 * variadic_error_printer()].
 *
 * ==> if argc == 1 :
 *
 * Init all process :
 *
 * ==> Init environment cache.
 * ==> launch prompt.
 *
*/

int	main(int argc, char **argv, char **env)
{
	(void) argv;
	(void) env;
	if (argc == 1)
	{
		printf("===================== ENV DATA =========================\n\n");
		initialize_bash_env(env);
		printf("========================================================\n\n");
		minishell();
	}
	else
	{
		variadic_error_printer(2, "Error : Invalid argument\n");
		variadic_error_printer(2, "Usage : ./minishell\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
