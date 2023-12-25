/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:51:42 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:51:58 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_base(unsigned long nb, char *base)
{
	int				count;
	unsigned long	len;

	len = ft_strlen(base);
	count = 0;
	if (nb >= len)
		count += ft_put_base(nb / len, base);
	count += ft_put_char(base[nb % len]);
	return (count);
}
