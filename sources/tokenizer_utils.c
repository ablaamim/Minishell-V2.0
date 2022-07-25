/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:37:40 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/24 10:39:36 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	devour_token(t_token **token_list)
{
	t_token	*tmp;

	tmp = *token_list;
	if (*token_list == 0x0)
		return ;
	*token_list = (*token_list)->next;
	free(tmp->data);
	free(tmp);
}
