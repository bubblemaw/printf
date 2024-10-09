/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:44:44 by maw               #+#    #+#             */
/*   Updated: 2024/09/09 17:36:50 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
// char	*ft_strdup(const char *source)
// {
// 	int		i;
// 	int		len;
// 	char	*dup;

// 	len = ft_strlen(source);
// 	i = 0;
// 	dup = malloc((len + 1) * sizeof(char));
// 	if (dup == NULL)
// 		return (dup);
// 	while (source[i])
// 	{
// 		dup[i] = source[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		i;
// 	char		*sub;

// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	sub = malloc((len + 1) * sizeof(char));
// 	if (sub == NULL)
// 		return (sub);
// 	i = 0;
// 	while (s[start] && i < len)
// 	{
// 		sub[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }

int	countwords(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		in;

	in = 0;
	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] != c && in == 0)
		{
			count++;
			in = 1;
		}
		else if (str[i] == c)
			in = 0;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	start;
	size_t	num;
	size_t	i;

	split = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (split == NULL || s == NULL)
		return (NULL);
	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			split[num] = ft_substr(s, start, i - start);
			num++;
		}
	}
	split[num] = NULL;
	return (split);
}

// int main (void)
// {
// 	char mot[]= "";
// 	char set = ' ';
// 	char **tab;
// 	int i;

// 	tab = ft_split(mot, set);
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }