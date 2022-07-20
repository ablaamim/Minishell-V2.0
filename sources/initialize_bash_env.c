/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bash_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:01:42 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/20 10:56:08 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Save environment data in accessible memory area [char **t_env]
 *
 * env_length() : Calculates the length of initiale env and returns it.
 *
*/

void	initialize_bash_env(t_env env)
{
	t_env	*bash_env;
	int		len;
	int		iterator;
	t_env	tmp;

	iterator = 0x0;
	len = env_length(env);
	printf("====> Bash cache length :%d\n\n", len);
	bash_env = retrieve_bash_env();
	if (bash_env == 0x0)
	{
		tmp = malloc (sizeof(char *) * (len + 0x1));
		if (tmp == 0x0)
		{
			variadic_error_printer(2, "Error : malloc() failed\n");
			return ;
		}
		while (env[iterator])
		{
			tmp[iterator] = ft_strdup(env[iterator]);
			iterator++;
		}
		tmp[iterator] = 0x0;
		*bash_env = tmp;
	}
	printf("==================== ENV CACHE ========================\n\n");
	print_env(env);
}
