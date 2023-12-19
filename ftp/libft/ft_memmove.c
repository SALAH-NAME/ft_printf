/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:38:44 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/08 20:20:15 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void *src, size_t n)
{
	unsigned char		*d;
	int					i;
	unsigned const char	*s;

	d = dest;
	s = src;
	if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
