/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:15:59 by maw               #+#    #+#             */
/*   Updated: 2024/10/08 17:59:13 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reconnaitre le % afin de pouvoir compter le nombre d'arguments et leurs type aussi

-boucle while qui va recoonaitre le genre d'argument et sois ca va l'introduire
dans la fonction va arg ou sinon j'ai une fonction deja faite avec
le bon va arg qui va pouvoir ecrire ma fonction
il faudra un compteur de pourcentage surment.

-si il y plus d'arguments que de scpécifications de formats  les arguments supllémentaire
sont evaluié mes ignorés.

int ft_printf(const char *format, ...);

Comment print ce que n'en b esoin au bon endroit comment rremplacer le %d par le int ?
Comment aller au prochain % à chaque fois en reprnant ou le pointeur en était ?
comment integrer la libft dans ce projet ?

J'ecris char par char jusqua que je recontre un % quand je rencontre un pourcentage 
j'envoie dans 

#stdarg
FONCTIONS:
strchr
putstr
putnbr
*/
#include <stdarg.h>
#include <stdio.h>
#include "libftprintf.h"

size_t	ft_division_10(long int num)
{
	size_t	digit;

	digit = 0;
	if (num < 0)
	{
		digit++;
		num = -num;
	}
	if (num == 0)
	{
		return (1);
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

size_t	ft_division_10_unsigned(unsigned int num)
{
	size_t	digit;

	digit = 0;
	if (num == 0)
	{
		return (1);
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

size_t	ft_division_16(long int num)
{
	size_t	digit;

	digit = 0;
	if (num < 0)
	{
		num *= -1;
		digit++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		digit++;
	}
	return (digit);
}

size_t	ft_division_16_pointer(void *num)
{
	size_t	digit;
	unsigned long int n;

	n = (unsigned long int)num;

	digit = 2;
	while (n > 0)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}

int	countchar(char c, va_list ap_copy1)
{
	int	count;

	count = 0;
	if (c == 'c' || c == 'C')
		count++;
	else if (c == 's' || c == 'S')
		count = ft_strlen(va_arg(ap_copy1, char *));
	else if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
		count = ft_division_10(va_arg(ap_copy1, int));
	else if (c == 'x')
		count = ft_division_16(va_arg(ap_copy1, int));
	else if (c == 'X')
		count = ft_division_16(va_arg(ap_copy1, int));
	else if (c == 'u' || c == 'U')
		count = ft_division_10_unsigned(va_arg(ap_copy1, unsigned int));
	else if (c == '%')
		count++;
	else if (c == 'p')
		count = ft_division_16_pointer(va_arg(ap_copy1, void *));
	return (count);
}

void	checkflag(char c, va_list *ap)
{
	if (c == 'c' || c == 'C')
		ft_putchar_fd((char)va_arg(*ap, int), 1);
	else if (c == 's' || c == 'S')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
		ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (c == 'x')
		ft_puthexa_fd(va_arg(*ap, int), 1);
	else if (c == 'X')
		ft_puthexa_up_fd(va_arg(*ap, int), 1);
	else if (c == 'u' || c == 'U')
		ft_putnbr_unsigned(va_arg(*ap, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'p')
		put0x(va_arg(*ap, void *));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_list ap_copy1;
	// va_list ap_copy2;
	int		i;
	size_t	charcount;

	charcount = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// if (format[i] == 'c' || format[i] == 'C')
			// 	ft_putchar_fd((char)va_arg(ap, int), 1);
			// if (format[i] == 's' || format[i] == 'S')
			// 	ft_putstr_fd(va_arg(ap, char *), 1);
			// if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D' || format[i] == 'I')
			// 	ft_putnbr_fd(va_arg(ap, int), 1);
			// if (format[i] == 'x')
			// 	ft_puthexa_fd(va_arg(ap, int), 1);
			// if (format[i] == 'X')
			// 	ft_puthexa_up_fd(va_arg(ap, int), 1);
			// if (format[i] == 'u' || format[i] == 'U')
			// 	ft_putnbr_unsigned(va_arg(ap, int), 1);
			// if (format[i] == '%')
			// 	ft_putchar_fd('%', 1);
			// if (format[i] == 'p')
			// 	put0x(va_arg(ap, void *));
				// va_copy(ap_copy1, ap);
				va_copy(ap_copy1, ap);
				charcount += countchar(format[i], ap_copy1);
				checkflag(format[i], &ap);
				va_end(ap_copy1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			charcount++;
		}

	i++;
	}
	va_end(ap);
	return (charcount);	
}


// int main(void)
// {
// 	int a = 5;
// 	int *ptr = &a;

// 	printf("%d\n" ,ft_printf("je suis %d dans le bussinnes %s et %p \n", 500, "me demande pas pq", ptr));
// 	printf("%d\n", printf("je suis %d dans le bussinnes %s et %p\n", 500, "me demande pas pq", ptr));
// 	return (0);
// }