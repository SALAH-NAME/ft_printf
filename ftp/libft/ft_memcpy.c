/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:20:16 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/15 10:00:35 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char		*d;
	size_t				i;
	const unsigned char	*s;

	if (!to && !from)
		return (NULL);
	d = to;
	s = from;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (to);
}
