/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:56:13 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/16 12:32:38 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_strlen(char *str)
{
	int	len;

	if (str == 0x0)
		return (0x0);
	len = 0x0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	if (str == 0x0)
		return (0x0);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (new == 0x0)
		return (0x0);
	while (++i < len)
		new[i] = str[i];
	return (new);
}

void	*ft_memset(void *memory, int c, size_t n)
{
	size_t	iterator;

	iterator = 0x0;
	while (iterator < n)
	{
		((unsigned char *) memory)[iterator] = c;
		iterator++;
	}
	return (memory);
}

void	ft_bzero(void *memory, size_t size)
{
	ft_memset(memory, 0x0, size);
}

int	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str)
		write(fd, str, len);
	return (len);
}
/*
int	main(int argc, char **argv)
{
	printf("|%s|\n", ft_strdup("DUPLICATE ME"));
	printf("|%s|\n", ft_strdup(NULL));
	return (EXIT_SUCCESS);
}
*/
