/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:30:47 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/11 15:54:42 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_trim_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*temp;
	size_t		len;
	char		*str;
	int			i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_inset(s1[i], set))
		i++;
	len = 0;
	temp = s1 + i;
	len = ft_strlen(temp);
	if (len)
		while (temp[len - 1] && ft_inset(temp[len - 1], set))
			len--;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_trim_strncpy(str, temp, len);
		return (str);
	}
	return (NULL);
}
