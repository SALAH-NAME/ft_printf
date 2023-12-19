/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:24:50 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/17 20:39:07 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (((unsigned char *)str)[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}
