/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:20:47 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/20 08:09:28 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_clear(char **arr, int n)
{
	int	i;

	i = 0;
	while (arr[i] && i < n)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	*ft_strndup(char const *src, int size)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_core(char **split, const char *str, char c, int words)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (str[j] == c)
			j++;
		start = j;
		while (str[j] && str[j] != c)
			j++;
		split[i] = ft_strndup(str + start, j - start);
		if (!split[i])
			return (ft_clear(split, i));
		i++;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		words;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = ft_core(split, str, c, words);
	return (split);
}
