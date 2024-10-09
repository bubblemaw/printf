/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:45:26 by maw               #+#    #+#             */
/*   Updated: 2024/10/09 14:58:11 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_puthexa_fd(int n, int fd);
void	ft_puthexa_up_fd(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
void	put0x(void *ptr);
void	ft_puthexa_pre(unsigned long int n, int fd);
void	ft_putstr_fd(char *str, int fd);


#endif
