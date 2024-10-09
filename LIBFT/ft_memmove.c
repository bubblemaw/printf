/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:43:49 by maw               #+#    #+#             */
/*   Updated: 2024/09/23 16:32:23 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t  i;

	i = 0;
	if (dest == NULL && src == NULL)
			return (NULL);
	if (((char *)dest) < ((char *)src))
	{
			while (i < len)
			{
					((char *)dest)[i] = ((char *)src)[i];
					i++;
			}
	}
	else
	{
			while (len > 0)
			{
					len--;
					((char *)dest)[len] = ((char *)src)[len];
			}
	}
	return (dest);
}

// void	*ft_memmove(void *dest, void *src, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dest && !src)
// 		return (NULL);
// 	if (((char *)dest) < ((char *)src))
// 	{
// 		while (i < len)
// 		{
// 			((char *)dest)[i] = ((char *)src)[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (len > 0)
// 		{
// 			len--;
// 			((char *)dest)[len] = ((char *)src)[len];
// 		}
// 	}
// 	return (dest);
// }

// void	*ft_memmove(void *dest, const void *src, size_t len)
// {
// 	size_t	i;
// 	char	*c_dest;
// 	char	*c_src;

// 	if (!dest && !src)
// 		return (NULL);
// 	c_dest = (char *) dest;
// 	c_src = (char *) src;
// 	i = 0;
// 	if (c_dest > c_src)
// 	{
// 		while (len-- > 0)
// 			c_dest[len] = c_src[len];
// 	}
// 	else
// 	{
// 		while (i < len)
// 		{
// 			c_dest[i] = c_src[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }
