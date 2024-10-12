/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:45:26 by maw               #+#    #+#             */
/*   Updated: 2024/10/10 00:15:40 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "LIBFT/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen_spe(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_puthexa_fd(unsigned int n, int fd);
void	ft_puthexa_up_fd(unsigned int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
void	put0x(void *ptr);
void	ft_puthexa_pre(unsigned long int n, int fd);
void	ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		ft_putchar_spe(char c, int fd);

#endif
