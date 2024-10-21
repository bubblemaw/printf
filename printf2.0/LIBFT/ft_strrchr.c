/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:33:45 by maw               #+#    #+#             */
/*   Updated: 2024/09/23 15:59:05 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	cc;

	if (!str)
		return (NULL);
	cc = (char) c;
	last = NULL;
	while (*str)
	{
		if (*str == cc)
			last = (char *) str;
		str++;
	}
	if (cc == '\0')
		return ((char *) str);
	return (last);
}
