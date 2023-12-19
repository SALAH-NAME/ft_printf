/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:28:37 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/20 08:31:38 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return ((void *)malloc(0));
	ptr = (void *)malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
