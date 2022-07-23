/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:38:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/23 13:19:43 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strnlen(char *str, int maxlen)
{
	int	size;

	size = 0x0;
	if (str == 0x0)
		return (0x0);
	while (*(str + size) && maxlen--)
		size++;
	return (size);
}

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		max_len;

	if (str == 0x0)
		return (0x0);
	max_len = ft_strnlen(str, n);
	new = malloc(sizeof(*str) * (max_len + 0x1));
	if (new == 0x0)
		return (0x0);
	*(new + max_len) = '\0';
	return (ft_memcpy(new, str, max_len));
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((dest == 0x0 && src == 0x0) || n == 0x0)
		return (dest);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}

bool	ft_iswhite_space(int c)
{
	if (c == 32 || (c >= 7 && c <= 14))
		return (true);
	return (false);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	iterator;

	iterator = 0x0;
	while (src[iterator])
	{
		dest[iterator] = src[iterator];
		iterator++;
	}
	dest[iterator] = '\0';
	return (dest);
}
