/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:08:42 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/15 10:43:32 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_des;
	size_t	i;
	size_t	j;

	len_src = 0;
	len_des = 0;
	while (dest[len_des] != '\0')
		len_des++;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0 || size <= len_des)
		return (len_src + size);
	i = 0;
	j = len_des;
	while (src[i] != '\0' && i < size - len_des - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (len_src + len_des);
}
