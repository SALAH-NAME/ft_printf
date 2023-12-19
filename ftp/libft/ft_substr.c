/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:48:37 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/20 08:35:08 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_pro(char const *str)
{
	if (!str)
		return (0);
	return (ft_strlen(str));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	new_len;
	char	*substr;

	s_len = ft_strlen_pro(s);
	if (start < s_len)
	{
		new_len = ft_strlen_pro(s + start);
		if (new_len < len)
			len = new_len;
	}
	else
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (start <= s_len && s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
