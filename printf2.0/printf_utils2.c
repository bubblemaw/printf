/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:08:13 by maw               #+#    #+#             */
/*   Updated: 2024/10/21 16:59:14 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fi(int n, int fd)
{
	int			modulo;
	char		reste;
	int			count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		count++;
		n *= -1;
	}
	if (n >= 10)
	{
		modulo = n % 10;
		reste = modulo + '0';
		count += ft_putnbr_fi(n / 10, fd);
		if (write(fd, &reste, 1) == -1)
			return (-1);
		count++;
	}
	if (n < 10)
	{
		reste = n + '0';
		if (write(fd, &reste, 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}


int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
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

int	ft_putchar_spe(unsigned char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
