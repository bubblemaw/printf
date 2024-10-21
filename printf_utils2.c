/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:08:13 by maw               #+#    #+#             */
/*   Updated: 2024/10/20 14:06:35 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen_spe(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (6);
	}
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_spe(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
