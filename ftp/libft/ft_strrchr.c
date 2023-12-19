/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:30:55 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/17 20:39:37 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i])
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			temp = (char *)(str + i);
		i++;
	}
	if (((unsigned char *)str)[i] == (unsigned char)c)
		return ((char *)str + i);
	return (temp);
}
