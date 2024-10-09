/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:17:06 by maw               #+#    #+#             */
/*   Updated: 2024/09/01 19:33:55 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	if (small[0] == '\0')
		return ((char *)big);
	i = 0;
	while ((big[i] && i < len))
	{
		j = 0;
		while ((small[j] == big[i + j] && (i + j) < len))
		{
			if (small[j + 1] == '\0')
				return (&((char *)big)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
