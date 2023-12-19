/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:37:17 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/18 08:37:22 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			lu2;
	unsigned int	i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char *)haystack;
	u2 = (unsigned char *)needle;
	lu2 = ft_strlen((char *)u2);
	if (lu2 == 0)
		return ((char *)u1);
	if (len == 0)
		return (NULL);
	while (u1[i] && i <= (len - lu2) && (len >= lu2))
	{
		if (ft_strncmp((const char *)u1 + i, (const char *)u2, lu2) == 0)
			return ((char *)u1 + i);
		i++;
	}
	return (NULL);
}
