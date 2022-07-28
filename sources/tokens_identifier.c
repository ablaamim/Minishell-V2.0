/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:56:45 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/28 14:46:32 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	check_logical_operators(enum e_token_type type)
{
	return (type == OR_TOKEN || type == AND_TOKEN);
}

bool	is_redirection(enum e_token_type type)
{
	return (type == LESSER_TOKEN || type == DLESSER_TOKEN || \
			type == GREATER_TOKEN || type == DGREATER_TOKEN);
}

bool	is_leaf(enum e_token_type type)
{
	return (is_redirection(type) == true || type == WORD_TOKEN);
}
