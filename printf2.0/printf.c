/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:15:59 by maw               #+#    #+#             */
/*   Updated: 2024/10/20 21:51:17 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkflag(char c, va_list *ap)
{
	int	count;

	count = 0;
	if (c == 'c' || c == 'C')
		count += ft_putchar_spe((char)va_arg(*ap, int), 1);
	else if (c == 's' || c == 'S')
		count += ft_putstr(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
		count += ft_putnbr_fi(va_arg(*ap, int), 1);
	else if (c == 'x')
		count += ft_puthexa_fd(va_arg(*ap, int), 1);
	else if (c == 'X')
		count += ft_puthexa_up_fd(va_arg(*ap, int), 1);
	else if (c == 'u' || c == 'U')
		count += ft_putnbr_unsigned(va_arg(*ap, unsigned int), 1);
	else if (c == '%')
		count += ft_putchar_spe('%', 1);
	else if (c == 'p')
		count += put0x(va_arg(*ap, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	// va_list	ap_copy1;
	int		i;
	size_t	charcount;

	charcount = 0;
	i = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// va_copy(ap_copy1, ap);
			// charcount += countchar(format[i], ap_copy1);
			charcount += checkflag(format[i], &ap);
			// va_end(ap_copy1);
		}
		else
		{
			if (ft_putchar_spe(format[i], 1) == -1)
				return (-1);
			charcount += 1;
		}
		i++;
	}
	va_end(ap);
	return (charcount);
}

// int main(void)
// {
// 	// int a = NULL;
// 	// int *ptr = &a;

// 	printf("%d\n" , ft_printf(" %d",-10));
// 	printf("%d\n" , printf(" %d",-10));
// 	return (0);
// }
