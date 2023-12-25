/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:15:44 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:16:18 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
		count += ft_put_nbr(nb / 10);
	count += ft_put_char('0' + (nb % 10));
	return (count);
}
