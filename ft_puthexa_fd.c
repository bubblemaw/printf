/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:06:02 by maw               #+#    #+#             */
/*   Updated: 2024/10/09 14:47:50 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int		modulo;
	char	reste;
	int		count;

	count = 0;
	if (n >= 10)
	{
		modulo = n % 10;
		reste = modulo + '0';
		ft_putnbr_unsigned(n / 10, fd);
		write(fd, &reste, 1);
		count++;
	}
	if (n < 10)
	{
		reste = n + '0';
		write(fd, &reste, 1);
	}
	return (count);
}

int	ft_puthexa_fd(int n, int fd)
{
	char			reste;
	unsigned int	num;
	int				count;

	count = 0;
	if (n < 0)
	{
		num = (unsigned int)n;
	}
	else
		num = n;
	if (num >= 16)
	{
		ft_puthexa_fd(num / 16, fd);
		num = num % 16;
	}
	if (num < 10)
	{
		reste = num + '0';
	}
	if (num >= 10 && num < 16)
		reste = (num - 10) + 'a';
	count++;
	write(fd, &reste, 1);
	return (count);
}

void	ft_puthexa_pre(unsigned long int n, int fd)
{
	char	reste;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 16)
	{
		ft_puthexa_pre(n / 16, fd);
		n = n % 16;
	}
	if (n < 10)
	{
		reste = n + '0';
	}
	if (n >= 10 && n < 16)
		reste = (n - 10) + 'a';
	write(fd, &reste, 1);
}

void	put0x(void *ptr)
{
	write(1, "0x", 2);
	ft_puthexa_pre((unsigned long int)ptr, 1);

}

void	ft_puthexa_up_fd(int n, int fd)
{
	char	reste;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 16)
	{
		ft_puthexa_up_fd(n / 16, fd);
		n = n % 16;
	}
	if (n < 10)
	{
		reste = n + '0';
	}
	if (n >= 10 && n < 16)
		reste = (n - 10) + 'A';
	write(fd, &reste, 1);
}
