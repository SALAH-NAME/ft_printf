/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:17:00 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/09 10:58:31 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*u1;
	const unsigned char	*u2;

	u1 = (const unsigned char *)s1;
	u2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (u1[i] == u2[i] && i < n - 1)
		i++;
	return (u1[i] - u2[i]);
}
